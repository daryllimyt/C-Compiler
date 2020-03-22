#include "../../include/ast.hpp"

// template <class T1, class T2>
// void addToHashedClass(T1 &container, const std::string &key, const T2& value);
void clearRegisters(std::ostream *output);
void storeRegisters(std::ostream *output);
void loadRegisters(std::ostream *output);
void updateVariableBindings(ProgramContext &context);
void evaluateExpression(std::ostream *output, ProgramContext &context, NodePtr astNode);
int getSize(const NodePtr &astNode);
int getVariableAddressOffset(ProgramContext &context, const std::string &id);
std::string getReferenceRegister(ProgramContext &context, const std::string &id);
std::string createLabel(ProgramContext &context, const std::string &name);

void Compile(std::ostream *output, ProgramContext &context, NodePtr astNode) {
    try {
        if (astNode == NULL) {
            throw std::runtime_error("[ERROR] Unhandled NULL-type ast node \n");
        } else if (astNode->getType() == "ROOT") {
            /* STEPS
            1. Count global vars
            2. Init framesizes
            3. Init all functions vector
            4. Init all vars vector
            5. Init end label for program
            6. Init qemu flag .text
            */
            FrameContext globalFrame;
            globalFrame.bytes = 0;
            globalFrame.variableCount = 0;
            context.frameTracker = {globalFrame};
            // *output << ".text\n";  // qemu flag
            Compile(output, context, astNode->getNext());
            *output << "\n"
                    << context.endLabel << ":\n";  // add\tend label

        } else if (astNode->getType() == "FRAME") {
            Compile(output, context, astNode->getLeft());
            Compile(output, context, astNode->getRight());

        } else if (astNode->getType() == "FUNCTION_DECLARATION") {
            Compile(output, context, astNode->getIdentifier());
        } else if (astNode->getType() == "FUNCTION_DEFINITION") {
            // Get type specifier
            if (astNode->getTypeSpecifier()) {
                Compile(output, context, astNode->getTypeSpecifier());
                context.returnType = context.typeSpecifier;
            }
            // Calculate required number of bytes for this function on the stack
            int bytes = getSize(astNode);
            /* Adjustments
            -8  -> function's own identifier
            +32 -> saved registers $s0 - $s7 (8 x 4 bytes)
            +4  -> return address in $ra
            +4  -> previous frame address in $fp
            +4  -> global address in $gp
            +(8-bytes%8) -> padding to ensure double-alignment of stack pointer, i.e. bytes is a multiple of 8 */
            bytes += (36 + (8 - (bytes % 8)));

            // Frame start
            context.frameIndex++;

            // Tracking frame sizes
            if (context.frameIndex >= context.frameTracker.size()) {
                FrameContext newFrame;
                newFrame.bytes = bytes;
                newFrame.variableCount = 0;
                context.frameTracker.push_back(newFrame);
            } else {
                context.frameTracker[context.frameIndex].bytes = bytes;
                context.frameTracker[context.frameIndex].variableCount = 0;
            }

            // Get identifier
            context.variableAssignmentState = "FUNCTION_DEFINITION";
            Compile(output, context, astNode->getIdentifier());  // Links to VARIABLE node

            // Create labels
            std::string id = context.identifier;
            std::string functionEnd = createLabel(context, id + "_end_");
            context.functionEnds.push_back(functionEnd);
            *output << "\n"
                    << id << ":\n";
            if (context.scope == 0) {
                *output << ".globl " << id << "\n";  // Global flag for mips gcc
            }

            // Push to stack
            *output << "\t\t"
                    << "addiu\t$sp, $sp, " << -bytes << "\n";
            storeRegisters(output);
            Compile(output, context, astNode->getArgs());
            // For loop

            // Get scope
            Compile(output, context, astNode->getScope());

            *output << "\n"
                    << functionEnd << ":\n";

            // Load from stack
            loadRegisters(output);
            *output << "\t\t"
                    << "addiu\t$sp, $sp, " << bytes << "\n";

            // Frame end
            context.frameIndex--;

            // If $ra == 0 then jump to end of program
            *output << "\t\t"
                    << "beq\t$ra, $0, " << context.endLabel << "\n"
                    << "\t\t"
                    << "nop\n";

            // Return to previous frame
            *output << "\t\t"
                    << "jr\t$ra\n";
            *output << "\t\t"
                    << "nop\n";

        } else if (astNode->getType() == "FUNCTION_CALL") {
        } else if (astNode->getType() == "SCOPE") {
            context.scope++;
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());
            } else {
                *output << "\t\t"
                        << "nop\n";
            }
            context.scope--;

        } else if (astNode->getType() == "PARENTHESIS_WRAPPER") {
            if (astNode->getStatements()) {
                Compile(output, context, astNode->getStatements());
            }
        } else if (astNode->getType() == "MULTIPLE_ARGUMENTS") {
            context.variableAssignmentState = "FUNCTION_ARGUMENTS";
            if (astNode->getArgs()) {
                Compile(output, context, astNode->getArgs());
            }
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());
            }

        } else if (astNode->getType() == "MULTIPLE_PARAMETERS") {
            if (astNode->getStatements()) {
                Compile(output, context, astNode->getStatements());
            }
            if (astNode->getNext()) {
                *output << ", ";
                Compile(output, context, astNode->getNext());
            }
        } else if (astNode->getType() == "MULTIPLE_STATEMENTS") {  //most indentation happens here
            Compile(output, context, astNode->getStatements());    // Current statement
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());  // Any further statements
            }

        } else if (astNode->getType() == "ASSIGNMENT_STATEMENT") {
            if (!astNode->getStatements() && !astNode->getNext()) {  // Single declarator
                if (context.variableAssignmentState == "VARIABLE_DECLARATION" || context.variableAssignmentState == "NO_ASSIGN") {
                    Compile(output, context, astNode->getIdentifier());
                    // *output << "\t\t"
                    //         << "nop\n";
                } else if (context.variableAssignmentState == "ASSIGNMENT_STATEMENT") {
                    int offsetLeft = getVariableAddressOffset(context, context.identifier);
                    std::string refLeft = getReferenceRegister(context, context.identifier);
                    Compile(output, context, astNode->getIdentifier());
                    int offsetRight = getVariableAddressOffset(context, context.identifier);
                    std::string refRight = getReferenceRegister(context, context.identifier);
                    *output << "\t\t"
                            << "lw\t$t0, " << offsetRight << refRight << "\n";
                    *output << "\t\t"
                            << "nop\n";
                    *output << "\t\t"
                            << "sw\t$t0, " << offsetLeft << refLeft << "\n";

                } else {
                    throw std::runtime_error("[ERROR] Detected standalone variable declarator. Variable needs type specifier");
                }

            } else {
                Compile(output, context, astNode->getIdentifier());
                context.variableAssignmentState = "ASSIGNMENT_STATEMENT";
                if (astNode->getStatements()) {
                    Compile(output, context, astNode->getStatements());
                    int offset = getVariableAddressOffset(context, context.identifier);
                    std::string ref = getReferenceRegister(context, context.identifier);
                    *output << "\t\t"
                            << "sw\t$t0, " << offset << ref << "\n";
                }
                if (astNode->getNext()) {
                    Compile(output, context, astNode->getNext());
                }
            }

        } else if (astNode->getType() == "IF_STATEMENT") {
            std::string label = createLabel(context, "_");
            std::string start = "if_start" + label;
            std::string next = "if_next" + label;
            std::string end = "if_end" + label;

            *output << start << "\n";
            Compile(output, context, astNode->getCondition());  // Condition result stored in $t0
            *output << "\t\t"
                    << "beq\tt0, 0, " << next << "\n";  // If $t0==0 skip to else branch
            *output << "\t\t"
                    << "nop"
                    << "\n";

            Compile(output, context, astNode->getStatements());  // If statement
            *output << "\t\t"
                    << "j\t" << end << "\n";  // Skips else statement
            *output << "\t\t"
                    << "nop"
                    << "\n";
            *output << next << "\n";
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());  // Else or else if statement
            }

            *output << end << "\n";

        } else if (astNode->getType() == "WHILE_LOOP") {
            std::string label = createLabel(context, "_");
            std::string start = "while_start" + label;
            std::string end = "while_end" + label;

            *output << start << "\n";
            Compile(output, context, astNode->getCondition());  //result in t0
            *output << "\t\t"
                    << "beq\tt0, 0, " << end << "\n";  // condition returns 0 (false), exit while loop
            *output << "\t\t"
                    << "nop"
                    << "\n";

            Compile(output, context, astNode->getStatements());
            *output << "\t\t"
                    << "j\t" << start << "\n";  // unconditional jump to start
            *output << "\t\t"
                    << "nop"
                    << "\n";

            *output << end << "\n";

        } else if (astNode->getType() == "FOR_LOOP") {
            std::string label = createLabel(context, "_");
            std::string start = "for_start" + label;
            std::string end = "for_end" + label;

            Compile(output, context, astNode->getConditionOne());  // Initialize the iterator
            *output << start << "\n";
            Compile(output, context, astNode->getConditionTwo());  // Evaluate condition, result in t0
            *output << "\t\t"
                    << "beq\tt0, 0, " << end << "\n";
            *output << "\t\t"
                    << "nop"
                    << "\n";
            Compile(output, context, astNode->getNext());

            Compile(output, context, astNode->getConditionThree());  // Modifying the iterator
            *output << "\t\t"
                    << "j\t" << start << "\n";
            *output << "\t\t"
                    << "nop"
                    << "\n";

            *output << end << "\n";

        } else if (astNode->getType() == "ASSIGNMENT_EXPRESSION") {
            Compile(output, context, astNode->getLeft());
            Compile(output, context, astNode->getIdentifier());
            Compile(output, context, astNode->getRight());

        } else if (astNode->getType() == "UNARY_EXPRESSION") {
            Compile(output, context, astNode->getRight());  //identifier

            int offset = getVariableAddressOffset(context, context.identifier);
            std::string ref = getReferenceRegister(context, context.identifier);
            *output << "\t\t"
                    << "lw\t$t0, " << offset << ref << "\n"
                    << "\t\t"
                    << "nop\n";
            if (astNode->getId() == "++") {
                *output << "\t\t"
                        << "addi\t$t0, $t0, 1"
                        << "\n";
            } else if (astNode->getId() == "--") {
                *output << "\t\t"
                        << "subi\t$t0, $t0, 1"
                        << "\n";
            } else if (astNode->getId() == "&") {  //address
                *output << "\t\t"
                        << "addi\t$t0, $0, ref"
                        << "\n";
                *output << "\t\t"
                        << "addi\t$t0, $t0, offset"
                        << "\n";
            } else if (astNode->getId() == "+") {  //positive
                *output << "\t\t"
                        << "addu\t$t0, $t0, $0"
                        << "\n";
            } else if (astNode->getId() == "-") {  //negative
                *output << "\t\t"
                        << "xori\t$t0, $t0, -1"  //flip
                        << "\n";
                *output << "\t\t"
                        << "addi\t$t0, $t0, 1"  //add 1
                        << "\n";
            } else if (astNode->getId() == "~") {  //ones complement
                *output << "\t\t"
                        << "xori\t$t0, $t0, -1"
                        << "\n";
            } else if (astNode->getId() == "!") {  //logical NOT
                *output << "\t\t"
                        << "sltu\t$t0, $0, $t0"  //if unsigned t0 is bigger than 0 set to 1
                        << "\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
            *output << "\t\t"
                    << "sw\t$t0, " << offset << ref << "\n";

        } else if (astNode->getType() == "MULTIPLICATIVE_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "*") {
                *output << "\t\t"
                        << "mult\t$t0, $t1\n";
                *output << "\t\t"
                        << "mflo\t$t0\n";
            } else if (astNode->getId() == "/") {
                *output << "\t\t"
                        << "div\t$t1, $t0\n";
                *output << "\t\t"
                        << "mflo\t$t0\n";
            } else if (astNode->getId() == "%") {
                *output << "\t\t"
                        << "div\t$t1, $t0\n";
                *output << "\t\t"
                        << "mfhi\t$t0\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }

        } else if (astNode->getType() == "ADDITIVE_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "+") {
                *output << "\t\t"
                        << "add\t$t0, $t0, $t1\n";
            } else if (astNode->getId() == "-") {
                *output << "\t\t"
                        << "sub\t$t0, $t0, $t1\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }

        } else if (astNode->getType() == "BITWISE_AND_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            *output << "\t\t"
                    << "and\t$t0, $t0, $t1\n";
        } else if (astNode->getType() == "BITWISE_XOR_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            *output << "\t\t"
                    << "xor\t$t0, $t0, $t1\n";
        } else if (astNode->getType() == "BITWISE_OR_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            *output << "\t\t"
                    << "or\t$t0, $t0, $t1\n";
        } else if (astNode->getType() == "BOOLEAN_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "and") {
                *output << "\t\t"
                        << "and\t$t0, $t0, $t1\n";

            } else if (astNode->getId() == "or") {
                *output << "\t\t"
                        << "or\t$t0, $t0, $t1\n";

            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
            *output << "\t\t"
                    << "andi\t$t0, $t0, 1\n";  // Extract bits

        } else if (astNode->getType() == "EQUALITY_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            *output << "\t\t"
                    << "slt\t$v0, $t0, $t1\n"
                    << "\t\t"
                    << "slt\t$v1, $t1, $t0\n"
                    << "\t\t"
                    << "xor\t$t0, $v0, $v1\n"
                    << "\t\t"
                    << "sltu\t$t0, $t0, 1\n";
        } else if (astNode->getType() == "SHIFT_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "<<") {
                *output << "\t\t"
                        << "sll\t$t0, $t0, $t1\n";
            } else if (astNode->getId() == ">>") {
                *output << "\t\t"
                        << "sra\t$t0, $t0, $t1\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }

        } else if (astNode->getType() == "RELATIONAL_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "<") {
                *output << "\t\t"
                        << "slt\t$t0, $t0, $t1\n";
            } else if (astNode->getId() == ">") {
                *output << "\t\t"
                        << "slt\t$t0, $t1, $t0\n";
            } else if (astNode->getId() == "<=") {
                *output << "\t\t"
                        << "slt\t$t0, $t1, $t0\n"
                        << "\t\t"
                        << "sltu\t$t0, $t0, 1\n";

            } else if (astNode->getId() == ">=") {
                *output << "\t\t"
                        << "slt\t$t0, $t0, $t1\n"
                        << "\t\t"
                        << "sltu\t$t0, $t0, 1\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }

        } else if (astNode->getType() == "POSTFIX_EXPRESSION") {
            Compile(output, context, astNode->getLeft());  //identifier

            int offset = getVariableAddressOffset(context, context.identifier);
            std::string ref = getReferenceRegister(context, context.identifier);
            *output << "\t\t"
                    << "lw\t$t0, " << offset << ref << "\n"
                    << "\t\t"
                    << "nop\n";
            if (astNode->getId() == "++") {
                *output << "\t\t"
                        << "addi\t$t0, $t0, 1"
                        << "\n";
            } else if (astNode->getId() == "--") {
                *output << "\t\t"
                        << "subi\t$t0, $t0, 1"
                        << "\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
            *output << "\t\t"
                    << "sw\t$t0, " << offset << ref << "\n";

        } else if (astNode->getType() == "VARIABLE_DECLARATION") {
            if (context.variableAssignmentState == "FUNCTION_ARGUMENTS") {
                std::string functionId = context.identifier;
                Compile(output, context, astNode->getTypeSpecifier());

                context.variableAssignmentState = "VARIABLE_DECLARATION";
                context.scope++;
                Compile(output, context, astNode->getStatements());
                context.functionBindings[functionId].addArg(context.identifier); // Adding new variable id to function args
                context.scope--;
                context.variableAssignmentState = "FUNCTION_ARGUMENTS"; // Future arguments have same context

            } else { // Coming from ASSIGNMENT_STATEMENT
                context.variableAssignmentState = "VARIABLE_DECLARATION";
                Compile(output, context, astNode->getTypeSpecifier());
                Compile(output, context, astNode->getStatements());
            }

        } else if (astNode->getType() == "RETURN") {
            if (astNode->getReturnValue()) {
                // if (astNode->getReturnValue()->getType() != context.returnType) {
                //     throw std::runtime_error(context.returnType+" type function requires "+context.returnType+" return value, but got "+astNode->getReturnValue()->getType()+"\n");
                // }
                Compile(output, context, astNode->getReturnValue());
                *output << "\t\t"
                        << "add\t$v0, $t0, $0\n";

            } else if (context.returnType == "VOID") {
                *output << "\t\t"
                        << "nop\n";
            } else {
                throw std::runtime_error("[ERROR] Int type function requires return type INT, got \"" + context.returnType + "\" instead");
            }
            *output << "\t\t"
                    << "j\t" << context.functionEnds.back() << "\n";
            context.functionEnds.pop_back();
        } else if (astNode->getType() == "BREAK") {
        } else if (astNode->getType() == "CONTINUE") {
        } else if (astNode->getType() == "VOID") {
            context.typeSpecifier = "VOID";
        } else if (astNode->getType() == "CHAR") {
            context.typeSpecifier = "CHAR";
        } else if (astNode->getType() == "SHORT") {
            context.typeSpecifier = "SHORT";
        } else if (astNode->getType() == "INT") {
            context.typeSpecifier = "INT";
        } else if (astNode->getType() == "LONG") {
            context.typeSpecifier = "LONG";
        } else if (astNode->getType() == "FLOAT") {
            context.typeSpecifier = "FLOAT";
        } else if (astNode->getType() == "DOUBLE") {
            context.typeSpecifier = "DOUBLE";
        } else if (astNode->getType() == "SIGNED") {
            context.typeSpecifier = "SIGNED";
        } else if (astNode->getType() == "UNSIGNED") {
            context.typeSpecifier = "UNSIGNED";
        } else if (astNode->getType() == "ASSIGNMENT_OPERATOR" ||
                   astNode->getType() == "UNARY_OPERATOR") {
        } else if (astNode->getType() == "VARIABLE") {
            std::string id = context.identifier = astNode->getId();
            std::string type = astNode->getVarType();                         // Normal, array, pointer
            if (context.variableAssignmentState == "VARIABLE_DECLARATION") {  // Declaring new variable
                if (type == "NORMAL") {
                    if (context.variableBindings.count(id) == 0) {  // Non-shadowing
                        int index = context.frameIndex;
                        if (context.scope == 0) {
                            index = 0;  // For global variables
                        }
                        context.frameTracker[index].variableCount++;  // Increment number of variables in frame
                        // context.frameTracker[index].addVariable(id);  // Track variable id
                        VariableContext newVariable;
                        newVariable.addressOffset = context.frameTracker[index].bytes - 8 * context.frameTracker[index].variableCount;  // Get next available memory address after vars
                        newVariable.scope = context.scope;
                        newVariable.typeSpecifier = context.typeSpecifier;
                        context.variableBindings[id].push_back(newVariable);  // Append context to associated variiable in map

                    } else {  // shadowing
                    }
                } else if (type == "ARRAY") {
                    Compile(output, context, astNode->getType())
                    
                } else if (type == "POINTER") {
                    /* code */
                } else {
                    throw std::runtime_error("[ERROR] Unknown variable type of " + type);
                }

            } else if (context.variableAssignmentState == "NO_ASSIGN") {  // Reading from existing variable
                if (context.variableBindings.count(id) == 0) {            // Varibale does not exist
                    throw std::runtime_error("[ERROR] Attempted read from undeclaraed variable " + id + "\n");
                }
                int addrOffset = getVariableAddressOffset(context, id);
                std::string ref = getReferenceRegister(context, id);
                *output << "\t\t"
                        << "lw\t$t0, " << addrOffset << ref << "\n"
                        << "\t\t"
                        << "nop\n";

            } else if (context.variableAssignmentState == "ASSIGNMENT_STATEMENT") {  // Writing to existing variable
                if (context.variableBindings.count(id) == 0) {                       // Varibale does not exist
                    throw std::runtime_error("[ERROR] Assignment to undeclaraed variable " + id + "\n");
                }
            } else if (context.variableAssignmentState == "FUNCTION_DEFINITION") {
                if (context.allFunctions.count(id)) {
                    throw std::runtime_error("[ERROR] Function already declared");
                } else {
                    FunctionContext newFunction;
                    newFunction.scope = context.scope;
                    newFunction.typeSpecifier = context.typeSpecifier;
                    context.functionBindings[id] = newFunction;
                    context.allFunctions.insert(id);
                }

            } else if (context.variableAssignmentState == "FUNCTION_DECLARATION") {
            } else {
            }

        } else if (astNode->getType() == "INTEGER_CONSTANT") {
            *output << "\t\t"
                    << "li\t$t0, " << astNode->getVal() << "\n";
        } else if (astNode->getType() == "FLOAT_CONSTANT") {
        } else if (astNode->getType() == "STRING_LITERAL") {
        } else {
            throw std::runtime_error("[ERROR] Unknown astNode of type " + astNode->getType() + "\n");
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << "\n";
        Util::abort();
    }
}

/******************** HELPER FUNCTIONS ********************/

// template <class T1, class T2>
// void addToHashedClass(T1 &container, const std::string &key, const T2& value) {
//     if (!container.count(key) && value != NULL) {
//         container[key] = value;
//     } else {
//         container.insesrt(key);
//     }
// }

std::string createLabel(ProgramContext &context, const std::string &name) {
    return name + std::to_string(context.labelCount++);
}

int getSize(const NodePtr &astNode) {
    // Base cases
    if (!astNode) {
        return 0;
    }

    int bytes = 0;
    if (astNode->getType() == "VARIABLE" ||
        astNode->getType() == "INTEGER_CONSTANT" ||
        astNode->getType() == "FLOAT_CONSTANT") {
        bytes += 8;  // 8 bytes -> 64bits, keep stack pointer double word aligned
    } else {
        bytes += getSize(astNode->getLeft());
        bytes += getSize(astNode->getRight());
        bytes += getSize(astNode->getNext());
        bytes += getSize(astNode->getPointer());
        bytes += getSize(astNode->getIdentifier());
        bytes += getSize(astNode->getArgs());
        bytes += getSize(astNode->getCondition());
        bytes += getSize(astNode->getConditionOne());
        bytes += getSize(astNode->getConditionTwo());
        bytes += getSize(astNode->getConditionThree());
        bytes += getSize(astNode->getReturnValue());
        bytes += getSize(astNode->getIndex());
        bytes += getSize(astNode->getTypeSpecifier());
        bytes += getSize(astNode->getQualifiers());  // May not be used
        bytes += getSize(astNode->getStatements());
        bytes += getSize(astNode->getScope());
    }
    return bytes;
}

void updateVariableBindings(ProgramContext &context) {
    for (auto &keyValuePair : context.variableBindings) {
        if (keyValuePair.second.back().scope > context.scope) {
            context.variableBindings[keyValuePair.first].pop_back();  // Remove scope bindings
        }
        if (keyValuePair.second.size() == 0) {
            context.variableBindings.erase(keyValuePair.first);  // Remove empty bindings
        }
    }
}

int getVariableAddressOffset(ProgramContext &context, const std::string &id) {
    try {
        // variable not bound
        if (!context.variableBindings.count(id)) {
            throw std::runtime_error("[ERROR] Could not find binding associated to variable \"" + id + "\"\n");
        } else {
            // get address offset of the last context associated with id.
            int addressOffset = context.variableBindings[id].back().addressOffset;
            // verify address
            if (addressOffset < 0) {
                throw std::runtime_error("[ERROR] Invalid address offset associated to variable \"" + id + "\"\n");
            }
            return addressOffset;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

std::string getReferenceRegister(ProgramContext &context, const std::string &id) {
    try {
        // variable not bound
        if (!context.variableBindings.count(id)) {
            throw std::runtime_error("[ERROR] Could not find binding associated to variable \"" + id + "\"\n");
        } else {
            // get address offset of the last context associated with id
            int scope = context.variableBindings[id].back().scope;
            // verify address
            if (scope < 0) {
                throw std::runtime_error("[ERROR] Invalid address offset associated to variable \"" + id + "\"\n");
            } else if (scope == 0) {
                return "($gp)";  // global frame
            } else {
                return "($fp)";  // local frame
            }
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

void evaluateExpression(std::ostream *output, ProgramContext &context, NodePtr astNode) {
    *output << "\t\t"
            << "addiu\t$sp, $sp, -4\n";
    Compile(output, context, astNode->getLeft());  //identifier
    *output << "\t\t"
            << "sw\t$t0, " << -4 * context.tempReg++ << "($fp)\n";
    Compile(output, context, astNode->getRight());  //expr
    *output << "\t\t"
            << "lw\t$t1, " << -4 * (--context.tempReg)-- << "($fp)\n"
            << "\t\t"
            << "nop\n";
    *output << "\t\t"
            << "addiu\t$sp, $sp, 4\n";
}

void clearRegisters(std::ostream *output) {
    *output << "\t\t"
            << "addiu\t$t0, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$t1, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$t2, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$t3, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$t4, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$t5, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$t6, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$t7, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$t8, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$s0, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$s1, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$s2, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$s3, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$s4, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$s5, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$s6, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$s7, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$v0, $0, 0\n";
    *output << "\t\t"
            << "addiu\t$v1, $0, 0\n";
}

void storeRegisters(std::ostream *output) {
    // Store address of previous frame on stack at 0($sp)
    *output << "\t\t"
            << "sw\t$fp, 0($sp)\n";
    *output << "\t\t"
            << "add\t$fp, $sp, $0\n";
    // Store return address in stack at 4($fp) also stores in $25/$t9
    *output << "\t\t"
            << "sw\t$ra, 4($sp)\n";
    *output << "\t\t"
            << "addiu\t$t9, $ra, 0\n";
    // Store saved register values ($s0 - $s7) on stack at 8($fp) - 36($fp)
    *output << "\t\t"
            << "sw\t$s0, 8($sp)\n";
    *output << "\t\t"
            << "sw\t$s1, 12($sp)\n";
    *output << "\t\t"
            << "sw\t$s2, 16($sp)\n";
    *output << "\t\t"
            << "sw\t$s3, 20($sp)\n";
    *output << "\t\t"
            << "sw\t$s4, 24($sp)\n";
    *output << "\t\t"
            << "sw\t$s5, 28($sp)\n";
    *output << "\t\t"
            << "sw\t$s6, 32($sp)\n";
    *output << "\t\t"
            << "sw\t$s7, 36($sp)\n";
    // Store value of $gp on stack
    *output << "\t\t"
            << "sw\t$gp, 40($sp)\n";
    *output << "\t\t"
            << "nop\n";
}

void loadRegisters(std::ostream *output) {
    // Load saved register values into ($s0 - $s7)
    *output << "\t\t"
            << "lw\t$s0, 8($fp)\n";
    *output << "\t\t"
            << "lw\t$s1, 12($fp)\n";
    *output << "\t\t"
            << "lw\t$s2, 16($fp)\n";
    *output << "\t\t"
            << "lw\t$s3, 20($fp)\n";
    *output << "\t\t"
            << "lw\t$s4, 24($fp)\n";
    *output << "\t\t"
            << "lw\t$s5, 28($fp)\n";
    *output << "\t\t"
            << "lw\t$s6, 32($fp)\n";
    *output << "\t\t"
            << "lw\t$s7, 36($fp)\n";
    // Load return address into $ra
    *output << "\t\t"
            << "lw\t$ra, 4($fp)\n";
    // Load previous frame into $fp
    *output << "\t\t"
            << "lw\t$fp, 0($fp)\n";
    *output << "\t\t"
            << "nop\n";
}
