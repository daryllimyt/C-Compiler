#include "../../include/ast.hpp"

// template <class T1, class T2>
// void addToHashedClass(T1 &container, const std::string &key, const T2& value);
void clearRegisters(std::ostream *output);
void storeRegisters(std::ostream *output);
void loadRegisters(std::ostream *output);
void updateVariableBindings(ProgramContext &context);
void evaluateExpression(std::ostream *output, ProgramContext &context, NodePtr astNode);
int getSize(ProgramContext &context, NodePtr astNode);
int getVariableAddressOffset(ProgramContext &context, const std::string &id);
int evalArrayIndexOrSize(ProgramContext &context, NodePtr astNode);
std::string getReferenceRegister(ProgramContext &context, const std::string &id);
std::string createLabel(ProgramContext &context, const std::string &name);

void Compile(std::ostream *output, ProgramContext &context, NodePtr astNode) {
    try {
        if (Util::viewStartTags) std::cerr << "\n[DEBUG] ENTERING << " << astNode->getType() << "_NODE >>\n";
        if (Util::viewAllNodesContext) std::cerr << context;
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
            globalFrame.totalBytes = 0;
            globalFrame.variableBytes = 0;
            context.frameTracker = {globalFrame};
            // *output << ".text\n";  // qemu flag
            Compile(output, context, astNode->getNext());
            *output << "\n"
                    << context.endLabel << ":\n";  // add\tend label

        } else if (astNode->getType() == "FRAME") {
            Compile(output, context, astNode->getLeft());
            Compile(output, context, astNode->getRight());

        } else if (astNode->getType() == "FUNCTION_DECLARATION") {
            context.variableAssignmentState = "FUNCTION_DECLARATION";
            Compile(output, context, astNode->getIdentifier());
        } else if (astNode->getType() == "FUNCTION_DEFINITION") {
            // Get type specifier
            if (astNode->getTypeSpecifier()) {
                Compile(output, context, astNode->getTypeSpecifier());
                context.returnType = context.typeSpecifier;
            }
            // Calculate required number of bytes for this function on the stack
            int bytes = getSize(context, astNode);
            /* Adjustments
            -8  -> function's own identifier
            +48 -> saved registers $s0 - $s7 + $a0 - a3 (12 x 4 bytes)
            +4  -> return address in $ra
            +4  -> previous frame address in $fp
            +4  -> global address in $gp
            +(8-bytes%8) -> padding to ensure double-alignment of stack pointer, i.e. bytes is a multiple of 8 */
            bytes += (52 + (8 - (bytes % 8)));

            // Frame start
            context.frameIndex++;

            // Tracking frame sizes
            if (context.frameIndex >= context.frameTracker.size()) {
                FrameContext newFrame;
                newFrame.totalBytes = bytes;
                newFrame.variableBytes = 0;
                context.frameTracker.push_back(newFrame);
            } else {
                context.frameTracker[context.frameIndex].totalBytes = bytes;
                context.frameTracker[context.frameIndex].variableBytes = 0;
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
                    << "addiu\t$sp, $sp, " << -bytes << " \t\t# (frame start) Move sp to end of new frame\n";
            storeRegisters(output);
            context.variableAssignmentState = "FUNCTION_ARGUMENTS";
            Compile(output, context, astNode->getArgs());
            if (Util::debug) std::cerr << context;

            for (int i = 0; i < context.virtualRegisters; i++) {  // Load fn args to registers, save if more than 4
                int offset = getVariableAddressOffset(context, context.functionBindings[id].args[i]);
                std::string ref = getReferenceRegister(context, context.functionBindings[id].args[i]);
                *output << "\t\t"
                        << "lw\t$t8, "
                        << -8 * (1 + i) << "($t9) \t\t# (fn args) Load fn call args from old virtual to $t8\n";
                *output << "\t\t"
                        << "sw\t$t8, "
                        << offset << ref << "\t\t# (fn args) Store fn call args from $t8 to new virtual\n";
            }

            // All function parameters are now in their respective variables in the new frame

            // Get scope
            Compile(output, context, astNode->getScope());

            *output << "\n"
                    << functionEnd << ":\n";

            // Load from stack
            loadRegisters(output);
            *output << "\t\t"
                    << "addiu\t$sp, $sp, " << bytes << " \t\t# (frame end) Move sp to end of previous frame\n";

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
            Compile(output, context, astNode->getIdentifier());
            std::string id = context.identifier;

            if (astNode->getParameters()) {
                Compile(output, context, astNode->getParameters());

                *output << "\t\tmove\t$t9, $fp \t\t# Store current fp in $f9\n";      //storing current fp into t4
                *output << "\t\tjal\t" << id << "\t\t\t\t# (fn call) enter fn def\n"  // return value of function call in $v0
                        << "\t\tnop\n";
            }
            context.variableAssignmentState = "FUNCTION_CALL";
        } else if (astNode->getType() == "SCOPE") {
            context.scope++;
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());
            } else {
                *output << "\t\t"
                        << "nop\n";
            }
            context.scope--;
            // updateVariableBindings(context);  // Remove variable contexts created in this scope
        } else if (astNode->getType() == "PARENTHESIS_WRAPPER") {
            if (astNode->getStatements()) {
                Compile(output, context, astNode->getStatements());
            }
        } else if (astNode->getType() == "MULTIPLE_ARGUMENTS") {
            context.variableAssignmentState = "FUNCTION_ARGUMENTS";
            if (astNode->getArgs()) {
                Compile(output, context, astNode->getArgs());
                // if (Util::debug) std::cerr << "[DEBUG] MULT_ARGS : A: " << context.variableAssignmentState << "\n";
                // *output << "\t\t"
                //         << "addiu\t$sp, $sp, -8 \t\t# Expanding stack\n";
                // *output << "\t\t"
                //         << "sw\t$t0, " << -8 * (++context.virtualRegisters) << "($fp) \t\t# (arg) store in virtual\n";
            }
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());
                if (Util::debug) std::cerr << "[DEBUG] MULT_ARGS : B: " << context.variableAssignmentState << "\n";
            }
        } else if (astNode->getType() == "MULTIPLE_PARAMETERS") {
            if (astNode->getStatements()) {
                Compile(output, context, astNode->getStatements());  //get in t0
                *output << "\t\t"
                        << "addiu\t$sp, $sp, -8 \t\t# Expanding stack\n";
                *output << "\t\t"
                        << "sw\t$t0, " << -8 * (++context.virtualRegisters) << "($fp) \t\t# (fn call params) store in virtual\n";
            }

            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());
            }
        } else if (astNode->getType() == "MULTIPLE_STATEMENTS") {  //most indentation happens here
            context.variableAssignmentState = "NO_ASSIGN";         // Clear any previous variableAssignContext
            Compile(output, context, astNode->getStatements());    // Current statement
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());  // Any further statements
            }
        } else if (astNode->getType() == "ASSIGNMENT_STATEMENT") {
            // type id = statements = next;
            if (!astNode->getStatements() && !astNode->getNext()) {  // Single declarator

                if (context.variableAssignmentState == "VARIABLE_DECLARATION" || context.variableAssignmentState == "NO_ASSIGN") {
                    // temp : no assign comes from expressions
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: single declataror A\n";
                    Compile(output, context, astNode->getIdentifier());
                    // *output << "\t\t"
                    //         << "nop\n";
                } else if (context.variableAssignmentState == "ASSIGNMENT_STATEMENT") {  // Recursive assignment
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: single declataror B\n";
                    int offsetLeft = getVariableAddressOffset(context, context.identifier);  // Previous id
                    std::string refLeft = getReferenceRegister(context, context.identifier);
                    Compile(output, context, astNode->getIdentifier());
                    int offsetRight = getVariableAddressOffset(context, context.identifier);  // New id
                    std::string refRight = getReferenceRegister(context, context.identifier);
                    *output << "\t\t"
                            << "lw\t$t0, " << offsetRight << refRight << "\n";
                    *output << "\t\t"
                            << "nop\n";
                    *output << "\t\t"
                            << "sw\t$t0, " << offsetLeft << refLeft << "\n";
                }
                // else {
                //     throw std::runtime_error("[ERROR] Detected standalone variable declarator. Variable needs type specifier");
                // }

            } else {
                if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: non-single declarator\n";
                Compile(output, context, astNode->getIdentifier());
                std::string id = context.identifier;
                context.variableAssignmentState = "ASSIGNMENT_STATEMENT";
                if (astNode->getStatements()) {
                    // if (Util::viewAllNodesContext) std::cerr << context;
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: non-single declarator A\n";
                    Compile(output, context, astNode->getStatements());  // output -> $v0 (function) / $t0 (var)

                    int offset = getVariableAddressOffset(context, id);
                    std::string ref = getReferenceRegister(context, id);
                    if (context.variableAssignmentState == "FUNCTION_CALL") {  // From function call
                        *output << "\t\t"
                                << "sw\t$v0, " << offset << ref << "\t\t# (assign) store function result\n";
                        // *output << "\t\t"
                        //         << "sw\t$t0, " << offset << ref << "\t\t# (assign) store function result\n";
                    } else {  // Normal variable
                        *output << "\t\t"
                                << "sw\t$t0, " << offset << ref << "\t\t# (assign) store var result\n";
                    }
                }
                if (astNode->getNext()) {
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: non-single declarator B, recursive\n";
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
			if(astNode->getVal == 1){ //if loop is a do while loop - do an iteration before checking conditions
				Compile(output, context, astNode->getStatements());
			}

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
            std::string id = astNode->getLeft()->getId();        // LHS Variable ID
            evaluateExpression(output, context, astNode);        // $t0 = LHS, $t1 = RHS
            Compile(output, context, astNode->getIdentifier());  // Evaluate result in $t0
            // x += y
            // x = x + y
            int offset = getVariableAddressOffset(context, id);
            std::string ref = getReferenceRegister(context, id);
            *output << "\t\tsw\t$t0, " << offset << ref << " \t\t# (assign expr) storing evaluated expression from $t0 to LHS variable in memory\n";

        } else if (astNode->getType() == "UNARY_EXPRESSION") {
            Compile(output, context, astNode->getRight());       // Identifier - stores result in t0
            Compile(output, context, astNode->getIdentifier());  // Operator - process t0 and restore it in t0

            int offset = getVariableAddressOffset(context, context.identifier);
            std::string ref = getReferenceRegister(context, context.identifier);
            *output << "\t\t"
                    << "lw\t$t0, " << offset << ref << "\n"
                    << "\t\t"
                    << "nop\n";

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
                        << "div\t$t0, $t1\n";
                *output << "\t\t"
                        << "mflo\t$t0\n";
            } else if (astNode->getId() == "%") {
                *output << "\t\t"
                        << "div\t$t0, $t1\n";
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
                        << "add\t$t0, $t0, $t1 \t\t# (add node) lhs + rhs\n";
            } else if (astNode->getId() == "-") {
                *output << "\t\t"
                        << "sub\t$t0, $t0, $t1 \t\t# (add node) lhs - rhs\n";
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
                        << "sltu\t$t0, $0, $t0\n"; //set t0 to 1 if t0 > 0
                *output << "\t\t"
                        << "sltu\t$t1, $0, $t1\n"; //set t1 to 1 if t1 > 0
                *output << "\t\t"
                        << "and\t$t0, $t0, $t1\n"; //set t0 to (t0 && t1)
            } else if (astNode->getId() == "or") {
                *output << "\t\t"
                        << "sltu\t$t0, $0, $t0\n"; //set t0 to 1 if t0 > 0
                *output << "\t\t"
                        << "sltu\t$t1, $0, $t1\n"; //set t1 to 1 if t1 > 0
                *output << "\t\t"
                        << "or\t$t0, $t0, $t1\n"; //set t0 to (t0 || t1)

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
            *output << "\t\tmove\t$t1, $t0\n";
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
            *output << "\t\tmove\t$t0, $t1\n";
        } else if (astNode->getType() == "VARIABLE_DECLARATION") {
            if (context.variableAssignmentState == "FUNCTION_ARGUMENTS") {
                std::string functionId = context.allFunctions.back();  // Gets last bound function
                Compile(output, context, astNode->getTypeSpecifier());

                context.variableAssignmentState = "VARIABLE_DECLARATION";
                context.scope++;
                Compile(output, context, astNode->getStatements());
                context.functionBindings[functionId].addArg(context.identifier);  // Adding new variable id to function args
                context.scope--;

            } else {  // Coming from ASSIGNMENT_STATEMENT or FUNCTION_CALL
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
                        << "add\t$v0, $t0, $0 \t\t# (return node) put return val in $v0\n";

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
        } else if (astNode->getType() == "ASSIGNMENT_OPERATOR") {
            // $t0 = LHS, $t1 = RHS
            if (astNode->getId() == "*=") {
                *output << "\t\t"
                        << "mult\t$t0, $t1 \t\t# (assign op node) lhs *= rhs\n";
                *output << "\t\t"
                        << "mflo\t$t0\n";
            } else if (astNode->getId() == "/=") {
                *output << "\t\t"
                        << "div\t$t0, $t1 \t\t# (assign op node) lhs /= rhs\n";
                *output << "\t\t"
                        << "mflo\t$t0\n";
            } else if (astNode->getId() == "%=") {
                *output << "\t\t"
                        << "div\t$t0, $t1 \t\t# (assign op node) lhs %= rhs\n";
                *output << "\t\t"
                        << "mfhi\t$t0\n";
            } else if (astNode->getId() == "+=") {
                *output << "\t\t"
                        << "add\t$t0, $t0, $t1 \t\t# (assign op node) lhs += rhs\n";
            } else if (astNode->getId() == "-=") {
                *output << "\t\t"
                        << "sub\t$t0, $t0, $t1 \t\t# (assign op node) lhs -= rhs\n";
            } else if (astNode->getId() == "<<=") {
                *output << "\t\t"
                        << "sll\t$t0, $t0, $t1 \t\t# (assign op node) lhs <<= rhs\n";
            } else if (astNode->getId() == ">>=") {
                *output << "\t\t"
                        << "sra\t$t0, $t0, $t1 \t\t# (assign op node) lhs >>= rhs\n";
            } else if (astNode->getId() == "&=") {
                *output << "\t\t"
                        << "and\t$t0, $t0, $t1 \t\t# (assign op node) lhs &= rhs\n";
            } else if (astNode->getId() == "^=") {
                *output << "\t\t"
                        << "xor\t$t0, $t0, $t1 \t\t# (assign op node) lhs ^= rhs\n";
            } else if (astNode->getId() == "|=") {
                *output << "\t\t"
                        << "or\t$t0, $t0, $t1 \t\t# (assign op node) lhs |= rhs\n";
            }
        } else if (astNode->getType() == "UNARY_OPERATOR") {
            if (astNode->getIdentifier()->getId() == "++") {
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
                        << "sub\t$t0, $0, $t0"
                        << "\n";
            } else if (astNode->getId() == "~") {  //ones complement
                *output << "\t\t"
                        << "xori\t$t0, $t0, -1"
                        << "\n";
            } else if (astNode->getId() == "!") {  //logical NOT
                *output << "\t\t"
                        << "sltu\t$t0, $0, $t0\n"; //set t0 to 1 if t0 > 0
                *output << "\t\t"
                        << "xor\t$t0, $t0, $t0\n"; //inverse bits

            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
        } else if (astNode->getType() == "VARIABLE") {
            if (Util::debug) std::cerr << "[DEBUG] VAR_NODE D: " << context.variableAssignmentState << "\n";
            std::string id = context.identifier = astNode->getId();
            std::string type = astNode->getVarType();                         // Normal, array, pointer
            if (context.variableAssignmentState == "VARIABLE_DECLARATION") {  // Declaring new variable
                if (type == "NORMAL") {
                    int index = context.frameIndex;
                    if (context.variableBindings.count(id) == 0) {  // Non-shadowing
                        if (context.scope == 0) {
                            index = 0;  // For global variables
                        }
                        context.frameTracker[index].variableBytes += 8;  // Increment size of variable block in frame
                        // context.frameTracker[index].addVariable(id);  // Track variable id
                        VariableContext newVariable;
                        newVariable.addressOffset = context.frameTracker[index].totalBytes - context.frameTracker[index].variableBytes;  // Get next available memory address after vars
                        newVariable.varType = type;
                        newVariable.size = 8;
                        newVariable.scope = context.scope;
                        newVariable.typeSpecifier = context.typeSpecifier;
                        context.variableBindings[id].push_back(newVariable);  // Append context to associated variiable in map

                    } else {                                                        // shadowing
                        int lastScope = context.variableBindings[id].back().scope;  // check if variable has been declared in this scope
                        if (lastScope == context.scope) {
                            throw std::runtime_error("[ERROR] Variable \"" + id + "\" is already declared in this scope: " + std::to_string(context.scope) + "\n");
                        }
                        context.frameTracker[index].variableBytes += 8;  // Increment size of variable block in frame
                        // context.frameTracker[index].addVariable(id);  // Track variable id
                        VariableContext newVariable;
                        newVariable.addressOffset = context.frameTracker[index].totalBytes - context.frameTracker[index].variableBytes;  // Get next available memory address after vars
                        newVariable.varType = type;
                        newVariable.size = 8;
                        newVariable.scope = context.scope;
                        newVariable.typeSpecifier = context.typeSpecifier;
                        context.variableBindings[id].push_back(newVariable);  // Append context to associated variiable in map
                    }
                } else if (type == "ARRAY") {
                    int index = context.frameIndex;
                    if (context.scope == 0) {
                        index = 0;  // For global variables
                    }
                    int arrayBytes = 8 * evalArrayIndexOrSize(context, astNode->getStatements());
                    context.frameTracker[index].variableBytes += arrayBytes;  // Increment number of variables in frame
                    VariableContext newVariable;
                    // Array base offset is at the bottom of the array block in memory
                    newVariable.addressOffset = context.frameTracker[index].totalBytes - context.frameTracker[index].variableBytes;  // Get next available memory address after vars
                    newVariable.varType = type;
                    newVariable.size = arrayBytes;
                    newVariable.scope = context.scope;
                    newVariable.typeSpecifier = context.typeSpecifier;
                    context.variableBindings[id].push_back(newVariable);  // Append context to associated variiable in map

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
                        << "lw\t$t0, " << addrOffset << ref << " \t\t# Reading from variable\n"
                        << "\t\t"
                        << "nop\n";

            } else if (context.variableAssignmentState == "ASSIGNMENT_STATEMENT") {  // Writing to existing variable
                if (!context.variableBindings.count(id) &&
                    !context.functionBindings.count(id) &&
                    !context.declaredFunctions.count(id)) {  // Varibale does not exist
                    throw std::runtime_error("[ERROR] Assignment to undeclaraed variable " + id + "\n");
                }
            } else if (context.variableAssignmentState == "FUNCTION_DEFINITION") {
                if (context.functionBindings.count(id)) {
                    throw std::runtime_error("[ERROR] Function already declared");
                } else {
                    if (Util::debug) std::cerr << "[DEBUG] NEW_FUNCTION E: " << id << std::endl;
                    FunctionContext newFunction;
                    newFunction.scope = context.scope;
                    newFunction.typeSpecifier = context.typeSpecifier;
                    context.functionBindings[id] = newFunction;
                    context.allFunctions.push_back(id);
                }

            } else if (context.variableAssignmentState == "FUNCTION_DECLARATION") {
                if (!context.functionBindings.count(id)) {  // Function not found in bindings
                    context.declaredFunctions.insert(id);
                }
            } else if (context.variableAssignmentState == "FUNCTION_CALL") {
                if (!context.declaredFunctions.count(id)) {              // Undeclared function
                    if (findInVector(context.allFunctions, id).first) {  // Function is defined
                        std::cerr << "[WARNING] Call to undeclared function \"" + id + "\" before definition\n";
                    } else {  // Function is undefined
                        throw std::runtime_error("[ERROR] Call to undeclared and undefined function \"" + id + "\"\n");
                    }
                }
            }
        } else if (astNode->getType() == "INTEGER_CONSTANT") {
            *output << "\t\t"
                    << "li\t$t0, " << astNode->getVal() << "\n";
        } else if (astNode->getType() == "FLOAT_CONSTANT") {
        } else if (astNode->getType() == "STRING_LITERAL") {
        } else {
            throw std::runtime_error("[ERROR] Unknown astNode of type " + astNode->getType() + "\n");
        }
        if (Util::viewEndTags) std::cerr << "\n[DEBUG] EXITING << " << astNode->getType() << "_NODE >>\n";
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

int getSize(ProgramContext &context, NodePtr astNode) {
    // Base cases
    if (!astNode) {
        return 0;
    }

    int bytes = 0;
    if (astNode->getType() == "INTEGER_CONSTANT" || astNode->getType() == "FLOAT_CONSTANT") {
        bytes += 8;  // 8 bytes -> 64bits, keep stack pointer double word aligned
    } else if (astNode->getType() == "VARIABLE") {
        if (astNode->getVarType() == "NORMAL" || astNode->getVarType() == "POINTER") {
            bytes += 8;
        } else if (astNode->getVarType() == "ARRAY") {
            bytes += 8 * evalArrayIndexOrSize(context, astNode->getStatements());
        }
    } else {
        bytes += getSize(context, astNode->getLeft());
        bytes += getSize(context, astNode->getRight());
        bytes += getSize(context, astNode->getNext());
        bytes += getSize(context, astNode->getPointer());
        bytes += getSize(context, astNode->getIdentifier());
        bytes += getSize(context, astNode->getArgs());
        bytes += getSize(context, astNode->getCondition());
        bytes += getSize(context, astNode->getConditionOne());
        bytes += getSize(context, astNode->getConditionTwo());
        bytes += getSize(context, astNode->getConditionThree());
        bytes += getSize(context, astNode->getReturnValue());
        bytes += getSize(context, astNode->getIndex());
        bytes += getSize(context, astNode->getTypeSpecifier());
        bytes += getSize(context, astNode->getQualifiers());  // May not be used
        bytes += getSize(context, astNode->getStatements());
        bytes += getSize(context, astNode->getScope());
        bytes += getSize(context, astNode->getParameters());
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
            << "addiu\t$sp, $sp, -8 \t\t# (eval expr) move sp for virtual regs\n";
    Compile(output, context, astNode->getRight());             // identifier - RHS result are in virtual memory
    if (context.variableAssignmentState == "FUNCTION_CALL") {  // From function call
        *output << "\t\t"
                << "sw\t$v0, " << -8 * ++context.virtualRegisters << "($fp) \t\t# (eval expr) store lhs in virtual\n";
    } else {  // Normal variable
        *output << "\t\t"
                << "sw\t$t0, " << -8 * ++context.virtualRegisters << "($fp) \t\t# (eval expr) store lhs in virtual\n";
    }

    Compile(output, context, astNode->getLeft());              //expr - LHS result stored in $t0
    if (context.variableAssignmentState == "FUNCTION_CALL") {  // From function call
        *output << "\t\t"
                << "move\t$t0, $v0 \t\t# (eval expr) lhs from fn call\n";
    }
    *output << "\t\t"  //RHS is loaded to $t1
            << "lw\t$t1, " << -8 * context.virtualRegisters-- << "($fp) \t\t# (eval expr) load lhs from virtual to $t1, rhs in $t0\n"
            << "\t\t"
            << "nop\n";
    *output << "\t\t"
            << "addiu\t$sp, $sp, 8 \t\t# (eval expr) clearing virtual\n";
}

int evalArrayIndexOrSize(ProgramContext &context, NodePtr astNode) {
    int value;
    if (astNode->getType() == "INTEGER_CONSTANT") {
        value = astNode->getVal();
    } else if (astNode->getType() == "VARIABLE") {
        std::string id = astNode->getId();
        value = context.getVariableIntValue(id);
    } else if (astNode->getType() == "UNARY_EXPRESSION") {
        value = evalArrayIndexOrSize(context, astNode->getRight());  //identifier
        if (astNode->getIdentifier()->getId() == "++") {
            value = ++value;
        } else if (astNode->getIdentifier()->getId() == "--") {
            value = --value;
        } else if (astNode->getIdentifier()->getId() == "+") {  //positive
            value = +value;
        } else if (astNode->getIdentifier()->getId() == "-") {  //negative
            value = -value;
        } else if (astNode->getIdentifier()->getId() == "~") {  //ones complement
            value = ~value;
        } else if (astNode->getIdentifier()->getId() == "!") {  //logical NOT
            value = !value;
        } else {
            throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
        }
    } else if (astNode->getType() == "POSTFIX_EXPRESSION") {
        value = evalArrayIndexOrSize(context, astNode->getLeft());
        if (astNode->getId() == "++") {
            return (value++);
        } else if (astNode->getId() == "--") {
            return (value--);
        } else {
            throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
        }

    } else if (astNode->getType() == "MULTIPLICATIVE_EXPRESSION") {
        int left, right;
        left = evalArrayIndexOrSize(context, astNode->getLeft());
        right = evalArrayIndexOrSize(context, astNode->getRight());
        if (astNode->getId() == "*") {
            value = left * right;
        } else if (astNode->getId() == "/") {
            value = left / right;
        } else if (astNode->getId() == "%") {
            value = left % right;
        } else {
            throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
        }

    } else if (astNode->getType() == "ADDITIVE_EXPRESSION") {
        int left, right;
        left = evalArrayIndexOrSize(context, astNode->getLeft());
        right = evalArrayIndexOrSize(context, astNode->getRight());
        if (astNode->getId() == "+") {
            value = left + right;
        } else if (astNode->getId() == "-") {
            value = left - right;
        } else {
            throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
        }

    } else if (astNode->getType() == "BITWISE_AND_EXPRESSION") {
        int left, right;
        left = evalArrayIndexOrSize(context, astNode->getLeft());
        right = evalArrayIndexOrSize(context, astNode->getRight());

        value = left & right;

    } else if (astNode->getType() == "BITWISE_XOR_EXPRESSION") {
        int left, right;
        left = evalArrayIndexOrSize(context, astNode->getLeft());
        right = evalArrayIndexOrSize(context, astNode->getRight());

        value = left ^ right;

    } else if (astNode->getType() == "BITWISE_OR_EXPRESSION") {
        int left, right;
        left = evalArrayIndexOrSize(context, astNode->getLeft());
        right = evalArrayIndexOrSize(context, astNode->getRight());

        value = left | right;
    } else if (astNode->getType() == "BOOLEAN_EXPRESSION") {
        int left, right;
        left = evalArrayIndexOrSize(context, astNode->getLeft());
        right = evalArrayIndexOrSize(context, astNode->getRight());
        if (astNode->getId() == "and") {
            value = left && right;
        } else if (astNode->getId() == "or") {
            value = left || right;
        } else {
            throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
        }

    } else if (astNode->getType() == "EQUALITY_EXPRESSION") {
        int left, right;
        left = evalArrayIndexOrSize(context, astNode->getLeft());
        right = evalArrayIndexOrSize(context, astNode->getRight());

        value = (left == right);
    } else if (astNode->getType() == "SHIFT_EXPRESSION") {
        int left, right;
        left = evalArrayIndexOrSize(context, astNode->getLeft());
        right = evalArrayIndexOrSize(context, astNode->getRight());
        if (astNode->getId() == "<<") {
            value = left << right;
        } else if (astNode->getId() == ">>") {
            value = left >> right;
        } else {
            throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
        }

    } else if (astNode->getType() == "RELATIONAL_EXPRESSION") {
        int left, right;
        left = evalArrayIndexOrSize(context, astNode->getLeft());
        right = evalArrayIndexOrSize(context, astNode->getRight());
        ;
        if (astNode->getId() == "<") {
            value = left < right;
        } else if (astNode->getId() == ">") {
            value = left < right;
        } else if (astNode->getId() == "<=") {
            value = left <= right;
        } else if (astNode->getId() == ">=") {
            value = left >= right;
        } else {
            throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
        }
    }
    return value;
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
            << "sw\t$fp, 0($sp) \t\t# Store addr of old fp on stack\n";
    *output << "\t\t"
            << "add\t$fp, $sp, $0 \t\t# Move fp to new sp\n";
    *output << "\t\t"
            << "sw\t$ra, 4($sp) \t\t# Store ra on stack\n";
    // *output << "\t\t"
    //         << "addiu\t$t9, $ra, 0 \t\t# Store ra in $t9\n";
    *output << "\t\t"
            << "sw\t$s0, 8($sp) \t\t# Store save regs $s0-$s7 on stack\n";
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
    *output << "\t\t"
            << "sw\t$a0, 40($sp) \t\t# Store prev fn args $a0-$a3 on stack\n";
    *output << "\t\t"
            << "sw\t$a1, 44($sp)\n";
    *output << "\t\t"
            << "sw\t$a2, 48($sp)\n";
    *output << "\t\t"
            << "sw\t$a3, 52($sp)\n";
    *output << "\t\t"
            << "sw\t$gp, 56($sp) \t\t# Store value of $gp on stack\n";
    *output << "\t\t"
            << "nop\n";
}

void loadRegisters(std::ostream *output) {
    *output << "\t\t"
            << "lw\t$s0, 8($fp) \t\t# Load saved regs into $s0-$s7\n";
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
    *output << "\t\t"
            << "lw\t$a0, 40($fp)\n";
    *output << "\t\t"
            << "lw\t$a1, 44($fp) \t\t# Load prev fn args into $a0-$a3\n";
    *output << "\t\t"
            << "lw\t$a2, 48($fp)\n";
    *output << "\t\t"
            << "lw\t$a3, 52($fp)\n";
    *output << "\t\t"
            << "lw\t$ra, 4($fp) \t\t# Load return address into $ra\n";
    *output << "\t\t"
            << "lw\t$fp, 0($fp) \t\t# Load prev fp into $fp\n";
    *output << "\t\t"
            << "nop\n";
}
