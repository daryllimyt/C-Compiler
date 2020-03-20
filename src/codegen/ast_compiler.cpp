#include "../../include/ast.hpp"

// template <class T1, class T2>
// void addToHashedClass(T1 &container, const std::string &key, const T2& value);
void clearRegisters(std::ostream *output);
void storeRegisters(std::ostream *output);
void loadRegisters(std::ostream *output);
int getSize(const NodePtr &astNode);
int getVariableAddressOffset(ProgramContext &context, const std::string &id);
std::string getReferenceRegister(ProgramContext &context, const std::string &id);
std::string createLabel(ProgramContext &context, const std::string &name);

void Compile(std::ostream *output, ProgramContext &context, NodePtr astNode) {
    try {
        if (astNode == NULL) {
            throw std::runtime_error("Unhandled NULL-type ast node \n");
        } else if (astNode->getType() == "ROOT") {
            /* STEPS
            1. Count global vars
            2. Init framesizes
            3. Init all functions vector
            4. Init all vars vector
            5. Init end label for program
            6. Init qemu flag .text
            */
            *output << ".text\n";  // qemu flag
            Compile(output, context, astNode->getNext());
            *output << "\n"
                    << context.endLabel << ":\n";  // Add end label

        } else if (astNode->getType() == "FRAME") {
            Compile(output, context, astNode->getLeft());
            Compile(output, context, astNode->getRight());

        } else if (astNode->getType() == "FUNCTION_DECLARATION") {
            Compile(output, context, astNode->getIdentifier());
        } else if (astNode->getType() == "FUNCTION_DEFINITION") {
            // Get type specifier
            std::cerr << "[DEBUG] 1\n";
            if (astNode->getTypeSpecifier()) {
                Compile(output, context, astNode->getTypeSpecifier());
                context.returnType = context.typeSpecifier;
            }
            std::cerr << "[DEBUG] 1\n";
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

            // Get identifier
            context.variableAssignmentState = "FUNCTION_DEFINITION";
            Compile(output, context, astNode->getIdentifier());  // Links to VARIABLE node
            std::string id = context.identifier;
            *output << "\n"
                    << id << ":\n";  // Label for function start

            // Get arguments
            Compile(output, context, astNode->getArgs());

            // Push to stack
            *output << "\t\t"
                    << "addiu $sp, $sp, " << -bytes << "\n";
            storeRegisters(output);
            // clearRegisters(output);
            std::string functionEnd = createLabel(context, id+"_end_");
            context.functionEnds.push_back(functionEnd);

            // Get scope
            Compile(output, context, astNode->getScope());

            *output << "\n"
                    << functionEnd << ":\n";

            // Load from stack
            // clearRegisters(output);
            loadRegisters(output);
            *output << "\t\t"
                    << "addiu $sp, $sp, " << bytes << "\n";

            // Frame end
            context.frameIndex--;

            // If $ra == 0 then jump to end of program
            *output << "\t\t"
                    << "beq $ra, $0, " << context.endLabel << "\n";

            // Return to previous frame
            *output << "\t\t"
                    << "jr $ra\n";
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
            if (astNode->getArgs()) {
                if (!context.functionArgs.count(astNode->getArgs()->getStatements()->getId())) {  // Record function arg in context
                    context.functionArgs.insert(astNode->getArgs()->getStatements()->getId());
                }
                Compile(output, context, astNode->getArgs());
            }
            if (astNode->getNext()) {
                *output << ", ";
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
            std::cerr << "[DEBUG] A\n";
            Compile(output, context, astNode->getStatements());  // Current statement
            std::cerr << "[DEBUG] B\n";
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());  // Any further statements
            }

        } else if (astNode->getType() == "ASSIGNMENT_STATEMENT") {
        } else if (astNode->getType() == "IF_STATEMENT") {
        } else if (astNode->getType() == "WHILE_LOOP") {
        } else if (astNode->getType() == "FOR_LOOP") {
        } else if (astNode->getType() == "ASSIGNMENT_EXPRESSION") {
            Compile(output, context, astNode->getLeft());
            Compile(output, context, astNode->getIdentifier());
            Compile(output, context, astNode->getRight());

        } else if (astNode->getType() == "UNARY_EXPRESSION") {
            Compile(output, context, astNode->getIdentifier());
            Compile(output, context, astNode->getRight());

        } else if (astNode->getType() == "MULTIPLICATIVE_EXPRESSION" ||
                   astNode->getType() == "ADDITIVE_EXPRESSION" ||
                   astNode->getType() == "BITWISE_AND_EXPRESSION" ||
                   astNode->getType() == "BITWISE_XOR_EXPRESSION" ||
                   astNode->getType() == "BITWISE_OR_EXPRESSION" ||
                   astNode->getType() == "BOOLEAN_EXPRESSION" ||
                   astNode->getType() == "EQUALITY_EXPRESSION" ||
                   astNode->getType() == "SHIFT_EXPRESSION" ||
                   astNode->getType() == "RELATIONAL_EXPRESSION") {
            Compile(output, context, astNode->getLeft());   //identifier
            *output << " " << astNode->getId() << " ";      //arithmetic operator
            Compile(output, context, astNode->getRight());  //expr

        } else if (astNode->getType() == "POSTFIX_EXPRESSION") {
            Compile(output, context, astNode->getLeft());  //identifier
            *output << astNode->getId();                   //operator

        } else if (astNode->getType() == "VARIABLE_DECLARATION") {
        } else if (astNode->getType() == "RETURN") {
            if (context.returnType == "INT") {
                /* code */
            } else {
                /* code */
            }

            *output << "move $v0, $0\n";
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
            context.identifier = astNode->getId();
            if (context.variableAssignmentState == "FUNCTION_DEFINITION") {
                if (context.allFunctions.count(context.identifier)) {
                    throw std::runtime_error("Warning: function already declared");
                } else {
                    FunctionContext functionContext;
                    functionContext.scope = context.scope;
                    functionContext.typeSpecifier = context.typeSpecifier;
                    context.functionBindings[context.identifier] = functionContext;
                    context.allFunctions.insert(context.identifier);
                }

            } else if (context.variableAssignmentState == "FUNCTION_DECLARATION") {
            } else {
            }

        } else if (astNode->getType() == "INTEGER_CONSTANT") {
        } else if (astNode->getType() == "FLOAT_CONSTANT") {
        } else if (astNode->getType() == "STRING_LITERAL") {
        } else {
            throw std::runtime_error("Unknown type of " + astNode->getType() + "\n");
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << "\n";
        exit(-1);
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

int getVariableAddressOffset(ProgramContext &context, const std::string &id) {
    try {
        // variable not bound
        if (!context.variableBindings.count(id)) {
            throw std::runtime_error("Could not find binding associated to variable \"" + id + "\"\n");
        } else {
            // get address offset of the last context associated with id.
            int addressOffset = context.variableBindings[id].back().addressOffset;
            // verify address
            if (addressOffset < 0) {
                throw std::runtime_error("Invalid address offset associated to variable \"" + id + "\"\n");
            }
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

std::string getReferenceRegister(ProgramContext &context, const std::string &id) {
    try {
        // variable not bound
        if (!context.variableBindings.count(id)) {
            throw std::runtime_error("Could not find binding associated to variable \"" + id + "\"\n");
        } else {
            // get address offset of the last context associated with id
            int scope = context.variableBindings[id].back().scope;
            // verify address
            if (scope < 0) {
                throw std::runtime_error("Invalid address offset associated to variable \"" + id + "\"\n");
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

void clearRegisters(std::ostream *output) {
    *output << "\t\t"
            << "addiu $t0, $0, 0\n";
    *output << "\t\t"
            << "addiu $t1, $0, 0\n";
    *output << "\t\t"
            << "addiu $t2, $0, 0\n";
    *output << "\t\t"
            << "addiu $t3, $0, 0\n";
    *output << "\t\t"
            << "addiu $t4, $0, 0\n";
    *output << "\t\t"
            << "addiu $t5, $0, 0\n";
    *output << "\t\t"
            << "addiu $t6, $0, 0\n";
    *output << "\t\t"
            << "addiu $t7, $0, 0\n";
    *output << "\t\t"
            << "addiu $t8, $0, 0\n";
    *output << "\t\t"
            << "addiu $s0, $0, 0\n";
    *output << "\t\t"
            << "addiu $s1, $0, 0\n";
    *output << "\t\t"
            << "addiu $s2, $0, 0\n";
    *output << "\t\t"
            << "addiu $s3, $0, 0\n";
    *output << "\t\t"
            << "addiu $s4, $0, 0\n";
    *output << "\t\t"
            << "addiu $s5, $0, 0\n";
    *output << "\t\t"
            << "addiu $s6, $0, 0\n";
    *output << "\t\t"
            << "addiu $s7, $0, 0\n";
    *output << "\t\t"
            << "addiu $v0, $0, 0\n";
    *output << "\t\t"
            << "addiu $v1, $0, 0\n";
}

void storeRegisters(std::ostream *output) {
    // Store address of previous frame on stack at 0($sp)
    *output << "\t\t"
            << "sw $fp, 0($sp)\n";
    *output << "\t\t"
            << "add $fp, $sp, $0\n";
    // Store return address in stack at 4($fp) also stores in $25/$t9
    *output << "\t\t"
            << "sw $ra, 4($sp)\n";
    *output << "\t\t"
            << "addiu $t9, $ra, 0\n";
    // Store saved register values ($s0 - $s7) on stack at 8($fp) - 36($fp)
    *output << "\t\t"
            << "sw $s0, 8($sp)\n";
    *output << "\t\t"
            << "sw $s1, 12($sp)\n";
    *output << "\t\t"
            << "sw $s2, 16($sp)\n";
    *output << "\t\t"
            << "sw $s3, 20($sp)\n";
    *output << "\t\t"
            << "sw $s4, 24($sp)\n";
    *output << "\t\t"
            << "sw $s5, 28($sp)\n";
    *output << "\t\t"
            << "sw $s6, 32($sp)\n";
    *output << "\t\t"
            << "sw $s7, 36($sp)\n";
    // Store value of $gp on stack
    *output << "\t\t"
            << "sw $gp, 40($gp)\n";
    *output << "\t\t"
            << ".cprestore 44\n";
}

void loadRegisters(std::ostream *output) {
    // Load saved register values into ($s0 - $s7)
    *output << "\t\t"
            << "lw $s0, 8($fp)\n";
    *output << "\t\t"
            << "lw $s1, 12($fp)\n";
    *output << "\t\t"
            << "lw $s2, 16($fp)\n";
    *output << "\t\t"
            << "lw $s3, 20($fp)\n";
    *output << "\t\t"
            << "lw $s4, 24($fp)\n";
    *output << "\t\t"
            << "lw $s5, 28($fp)\n";
    *output << "\t\t"
            << "lw $s6, 32($fp)\n";
    *output << "\t\t"
            << "lw $s7, 36($fp)\n";
    // Load return address into $ra
    *output << "\t\t"
            << "lw $ra, 4($fp)\n";
    // Load previous frame into $fp
    *output << "\t\t"
            << "lw $fp, 0($fp)\n";
}
