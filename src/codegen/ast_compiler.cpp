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
std::pair<int, std::string> getOffsetAndReferenceRegister(ProgramContext &context, NodePtr identifierNode);

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
            if (Util::qemu) *output << ".text\n";  // qemu flag
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
            context.frameIndex = context.frameTracker.size();  // frame number based on the number of functions

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
            context.functionBindings[id].frame = context.frameIndex;
            std::string functionEnd = createLabel(context, id + "_end_");
            context.functionEnds.push_back(functionEnd);
            if (context.scope == 0 && Util::qemu) {
                *output << "\n.globl " << id << "\n";  // Global flag for mips gcc
            }
            *output << id << ":\n";
            // qemu lines
            if (Util::qemu) {
                *output << "\t\t.ent " << id << "\n"
                        << "\t\t.frame $sp, " << bytes << ", $ra\n"
                        << "\t\t.set noreorder\n"
                        << "\t\t.cpload $t4\n"
                        << "\t\t.set reorder\n";
            }

            context.scope++;
            // Push to stack
            *output << "\t\t"
                    << "addiu\t$sp, $sp, " << -bytes << "\t\t# (fn def: frame start) Move sp to end of new frame\n";
            storeRegisters(output);
            context.variableAssignmentState = "FUNCTION_ARGUMENTS";
            Compile(output, context, astNode->getArgs());
            if (Util::debug) {
                std::cerr << "#######################################################\n";
                std::cerr << context;
                std::cerr << "#######################################################\n";
            }
            int argCount = context.functionBindings[id].args.size();
            for (int i = 0; i < argCount; i++) {  // Load fn args to registers, save if more than 4
                int offset = getVariableAddressOffset(context, context.functionBindings[id].args[i]);
                std::string ref = getReferenceRegister(context, context.functionBindings[id].args[i]);
                *output << "\t\tlw\t$t8, "
                        << 8 * (argCount - (i + 1)) << "($a0) \t\t# (fn args) Load fn call args from old virtual to $t8\n"
                        << "\t\tnop\n";
                *output << "\t\tsw\t$t8, "
                        << offset << ref << "\t\t# (fn args) Store fn call args from $t8 to memory\n";
            }
            context.scope--;

            // All function parameters are now in their respective variables in the new frame

            // Get scope
            Compile(output, context, astNode->getScope());

            *output << "\n"
                    << functionEnd << ":\n";

            // Load from stack
            loadRegisters(output);
            *output << "\t\t"
                    << "addiu\t$sp, $sp, " << bytes << "\t\t# (fn def: frame end) Move sp to end of previous frame\n";

            // Frame end
            context.frameIndex = 0;  // out of function, in global frame

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
            // qemu lines
            if (Util::qemu) *output << "\t\t.end " << id << "\n";
            context.functionEnds.pop_back();

        } else if (astNode->getType() == "FUNCTION_CALL") {
            // std::string prev = context.variableAssignmentState;
            context.variableAssignmentState = "FUNCTION_CALL";
            Compile(output, context, astNode->getIdentifier());
            std::string id = context.identifier;
            int argCount = context.functionBindings[id].args.size();

            if (astNode->getParameters()) {
                Compile(output, context, astNode->getParameters());

                *output << "\t\tmove\t$a0, $sp \t\t# Store current sp in $a0\n";      //storing current fp into t4
                *output << "\t\tjal\t" << id << "\t\t\t\t# (fn call) enter fn def\n"  // return value of function call in $v0
                        << "\t\tnop\n";
                *output << "\t\taddiu\t$sp, $sp, " << 8 * (argCount - 1) << "\t\t# Erasing virtual register for " << id << "\n";
                context.virtualRegisters -= (argCount - 1);  // This tells it to store at this VR
            }                                                //assuming all arguments are in virtual registers up to $sp
            // for (int i = 0; i < argCount; i++) {
            //     if (i < 4) {
            //         *output << "\t\tlw\t$a" << i << ", " << 8 * (argCount - (i + 1)) << "($sp)"
            //                 << "\t\t# Loading argument no. " << i << "\n";
            //     } else {
            //         break;
            //     }
            // }

            // if (prev == "ASSIGNMENT_STATEMENT") {
            context.variableAssignmentState = "FUNCTION_CALL";  // Save to $v0 instead of $t0
            context.identifier = id;                            // exit function call with function id
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
            if (context.variableAssignmentState == "FUNCTION_CALL") {
                context.variableAssignmentState = "NO_ASSIGN";
            }

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
                if (Util::debug) std::cerr << "[DEBUG] MULT_ARGS : B: " << context.variableAssignmentState << "\n";
            }
        } else if (astNode->getType() == "MULTIPLE_PARAMETERS") {
            std::string id = context.identifier;
            if (astNode->getStatements()) {
                context.variableAssignmentState = "NO_ASSIGN";             // Default state for function readings
                Compile(output, context, astNode->getStatements());        //get in t0
                if (context.variableAssignmentState == "FUNCTION_CALL") {  // From function call
                    *output << "\t\tsw\t$v0, 0($sp) \t\t# (fn call params) fn call result stored in virtual reg\n";
                    // *output << "\t\taddiu\t$sp, $sp, -8 \t\t# (fn call params) Expanding stack\n";
                } else {  // Normal variable
                    *output << "\t\t"
                            << "addiu\t$sp, $sp, -8 \t\t# (fn call params) Expanding stack\n";
                    *output << "\t\t"
                            << "sw\t$t0, 0($sp) \t\t# (fn call params) store in virtual register\n";
                }
            }

            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());
            }
            context.virtualRegisters -= context.functionBindings[id].args.size();  // Clear used virtual regs
        } else if (astNode->getType() == "MULTIPLE_STATEMENTS") {                  //most indentation happens here
            context.variableAssignmentState = "NO_ASSIGN";                         // Clear any previous variableAssignContext
            Compile(output, context, astNode->getStatements());                    // Current statement
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());  // Any further statements
            }
        } else if (astNode->getType() == "ASSIGNMENT_STATEMENT") {
            // (type) id = statements = next;
            if (!astNode->getStatements() && !astNode->getNext()) {  // Single declarator
                if (context.variableAssignmentState == "VARIABLE_DECLARATION" || context.variableAssignmentState == "NO_ASSIGN") {
                    // temp : no assign comes from expressions
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: single declataror A\n";
                    Compile(output, context, astNode->getIdentifier());

                } else if (context.variableAssignmentState == "ASSIGNMENT_STATEMENT") {  // Recursive assignment terminal case
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: single declataror B, recursive terminal\n";
                    int offsetLeft = getVariableAddressOffset(context, context.identifier);  // Previous id
                    std::string refLeft = getReferenceRegister(context, context.identifier);
                    context.variableAssignmentState = "NO_ASSIGN";
                    Compile(output, context, astNode->getIdentifier());  // Value of RHS loaded into $t0
                    // int offsetRight = getVariableAddressOffset(context, context.identifier);  // New id
                    // std::string refRight = getReferenceRegister(context, context.identifier);
                    // *output << "\t\t"
                    //         << "lw\t$t0, " << offsetRight << refRight << "\n";
                    // *output << "\t\t"
                    //         << "nop\n";
                    *output << "\t\t"
                            << "sw\t$t0, " << offsetLeft << refLeft << "\t\t# (assign) store recursive assign\n";
                }

            } else {
                if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: non-single declarator\n";
                Compile(output, context, astNode->getIdentifier());  // Set LHS in context
                std::string id = context.identifier;
                std::pair<int, std::string> addressInfo = getOffsetAndReferenceRegister(context, astNode->getIdentifier());
                int offset = addressInfo.first;
                std::string ref = addressInfo.second;
                context.variableAssignmentState = "ASSIGNMENT_STATEMENT";
                if (astNode->getStatements()) {  // Math or bitwise
                    // if (Util::viewAllNodesContext) std::cerr << context;
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: non-single declarator A, math or bitwise\n";
                    Compile(output, context, astNode->getStatements());        // output -> $v0 (function) / $t0 (var)
                    if (context.variableAssignmentState == "FUNCTION_CALL") {  // From function call
                        *output << "\t\tsw\t$v0, " << offset << ref
                                << "\t\t# (assign) store fn result in " << context.variableBindings[id].back().varType << " variable\n";
                    } else {  // Normal variable
                        *output << "\t\tsw\t$t0, " << offset << ref
                                << "\t\t# (assign) store var result in " << context.variableBindings[id].back().varType << " variable\n";
                    }
                }
                if (astNode->getNext()) {  // Recursive or variable
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: non-single declarator B, recursive\n";
                    Compile(output, context, astNode->getNext());
                }
            }
        } else if (astNode->getType() == "IF_STATEMENT") {
            std::string label = createLabel(context, "_");
            std::string start = "if_start" + label;
            std::string next = "if_next" + label;
            std::string end = "if_end" + label;
            context.functionEnds.push_back(end);

            *output << "\n"
                    << start << ":\n";
            Compile(output, context, astNode->getCondition());  // Condition result stored in $t0
            *output << "\t\t"
                    << "beq\t$t0, $0, " << next << "\n";  // If $t0==0 skip to else branch
            *output << "\t\t"
                    << "nop"
                    << "\n";

            Compile(output, context, astNode->getStatements());  // If statement
            *output << "\t\t"
                    << "j\t" << end << "\n";  // Skips else statement
            *output << "\t\t"
                    << "nop"
                    << "\n";
            *output << "\n"
                    << next << ":\n";
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());  // Else or else if statement
            }

            *output << "\n"
                    << end << ":\n";
            context.functionEnds.pop_back();

        } else if (astNode->getType() == "WHILE_LOOP") {
            if (astNode->getVal() == 1) {  //if loop is a do while loop - do an iteration before checking conditions
                Compile(output, context, astNode->getNext());
            }

            std::string label = createLabel(context, "_");
            std::string start = "while_start" + label;
            std::string end = "while_end" + label;
            std::string continue_ = "while_continue" + label;
            context.functionEnds.push_back(continue_);
            context.functionEnds.push_back(end);

            *output << "\n"
                    << start << ":\n";
            Compile(output, context, astNode->getCondition());  //result in t0
            *output << "\t\t"
                    << "beq\t$t0, $0, " << end << "\n";  // condition returns 0 (false), exit while loop
            *output << "\t\t"
                    << "nop"
                    << "\n";

            Compile(output, context, astNode->getNext());
            *output << "\n"
                    << continue_ << ":\n";
            *output << "\t\t"
                    << "j\t" << start << "\n";  // unconditional jump to start
            *output << "\t\t"
                    << "nop"
                    << "\n";

            *output << "\n"
                    << end << ":\n";
            context.functionEnds.pop_back();  //popping end
            context.functionEnds.pop_back();  //popping continue_
        } else if (astNode->getType() == "FOR_LOOP") {
            std::string label = createLabel(context, "_");
            std::string start = "for_start" + label;
            std::string end = "for_end" + label;
            std::string continue_ = "for_continue" + label;
            context.functionEnds.push_back(continue_);
            context.functionEnds.push_back(end);

            Compile(output, context, astNode->getConditionOne());  // Initialize the iterator
            *output << "\n"
                    << start << ":\n";
            Compile(output, context, astNode->getConditionTwo());  // Evaluate condition, result in t0
            *output << "\t\t"
                    << "beq\t$t0, $0, " << end << "\n";
            *output << "\t\t"
                    << "nop"
                    << "\n";
            Compile(output, context, astNode->getNext());
            *output << "\n"
                    << continue_ << ":\n";
            Compile(output, context, astNode->getConditionThree());  // Modifying the iterator

            *output << "\t\t"
                    << "j\t" << start << "\n";
            *output << "\t\t"
                    << "nop"
                    << "\n";

            *output << "\n"
                    << end << ":\n";
            context.functionEnds.pop_back();  //popping end
            context.functionEnds.pop_back();  //popping continue
        } else if (astNode->getType() == "ASSIGNMENT_EXPRESSION") {
            std::string id = astNode->getLeft()->getId();        // LHS Variable ID
            evaluateExpression(output, context, astNode);        // $t0 = LHS, $t1 = RHS
            Compile(output, context, astNode->getIdentifier());  // Evaluate result in $t0
            // x += y
            // x = x + y
            std::pair<int, std::string> addressInfo = getOffsetAndReferenceRegister(context, astNode->getLeft());
            int offset = addressInfo.first;
            std::string ref = addressInfo.second;
            *output << "\t\tsw\t$t0, " << offset << ref << "\t\t# (assign expr) storing evaluated expression from $t0 to LHS variable in memory\n";

        } else if (astNode->getType() == "UNARY_EXPRESSION") {
            Compile(output, context, astNode->getRight());       // Identifier - stores result in t0
            Compile(output, context, astNode->getIdentifier());  // Operator - process t0 and restore it in t0

            std::pair<int, std::string> addressInfo = getOffsetAndReferenceRegister(context, astNode->getRight());
            int offset = addressInfo.first;
            std::string ref = addressInfo.second;

            *output << "\t\t"
                    << "sw\t$t0, " << offset << ref << "\t\t# (unary) storing to variable\n";
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
                        << "sltu\t$t0, $0, $t0\n";  //set t0 to 1 if t0 > 0
                *output << "\t\t"
                        << "sltu\t$t1, $0, $t1\n";  //set t1 to 1 if t1 > 0
                *output << "\t\t"
                        << "and\t$t0, $t0, $t1\n";  //set t0 to (t0 && t1)
            } else if (astNode->getId() == "or") {
                *output << "\t\t"
                        << "sltu\t$t0, $0, $t0\n";  //set t0 to 1 if t0 > 0
                *output << "\t\t"
                        << "sltu\t$t1, $0, $t1\n";  //set t1 to 1 if t1 > 0
                *output << "\t\t"
                        << "or\t$t0, $t0, $t1\n";  //set t0 to (t0 || t1)

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
            std::string id = context.identifier;
            std::pair<int, std::string> addressInfo = getOffsetAndReferenceRegister(context, astNode->getLeft());
            int offset = addressInfo.first;
            std::string ref = addressInfo.second;
            *output << "\t\t"
                    << "lw\t$t0, " << offset << ref
                    << "\t\t# (postfix) store var result in " << context.variableBindings[id].back().varType << " variable\n"
                    << "\t\t"
                    << "nop\n";

            *output << "\t\tmove\t$t1, $t0\n";
            if (astNode->getId() == "++") {
                *output << "\t\t"
                        << "addi\t$t0, $t0, 1"
                        << "\n";
            } else if (astNode->getId() == "--") {
                *output << "\t\t"
                        << "addi\t$t0, $t0, -1"
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
                Compile(output, context, astNode->getStatements());
                context.functionBindings[functionId].addArg(context.identifier);  // Adding new variable id to function args

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
                Compile(output, context, astNode->getReturnValue());       // RV either $v0 or $t0
                if (context.variableAssignmentState != "FUNCTION_CALL") {  // From function call
                    *output << "\t\t"
                            << "move\t$v0, $t0 \t\t# (return node) load $t0 to $v0 if not function call\n";
                }
            } else if (context.returnType == "VOID") {
                *output << "\t\t"
                        << "nop\n";
            } else {
                throw std::runtime_error("[ERROR] Int type function requires return type INT, got \"" + context.returnType + "\" instead");
            }
            *output << "\t\t"
                    << "j\t" << context.functionEnds.back() << "\n"
                    << "\t\tnop\n";
        } else if (astNode->getType() == "BREAK") {
            *output << "\t\t"
                    << "j\t" << context.functionEnds.back() << "\n"
                    << "\t\tnop\n";
        } else if (astNode->getType() == "CONTINUE") {
            *output << "\t\t"
                    << "j\t" << context.functionEnds[context.functionEnds.size() - 2] << "\n"
                    << "\t\tnop\n";
        } else if (astNode->getType() == "VOID") {
            context.typeSpecifier = "VOID";
        } else if (astNode->getType() == "SIZE_OF") {
            Compile(output, context, astNode->getNext());
            if (context.typeSpecifier == "CHAR") {
                *output << "\t\tli\t$t0, 1\n";
            } else if (context.typeSpecifier == "SHORT") {
                *output << "\t\tli\t$t0, 2\n";
            } else if (context.typeSpecifier == "INT") {
                *output << "\t\tli\t$t0, 4\n";
            } else if (context.typeSpecifier == "LONG") {
                *output << "\t\tli\t$t0, 8\n";
            } else if (context.typeSpecifier == "FLOAT") {
                *output << "\t\tli\t$t0, 4\n";
            } else if (context.typeSpecifier == "DOUBLE") {
                *output << "\t\tli\t$t0, 8\n";
            } else if (context.typeSpecifier == "SIGNED") {
                *output << "\t\tli\t$t0, 4\n";
            } else if (context.typeSpecifier == "UNSIGNED") {
                *output << "\t\tli\t$t0, 4\n";
            }

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
            if (astNode->getId() == "++") {
                *output << "\t\taddi\t$t0, $t0, 1\n";
            } else if (astNode->getId() == "--") {
                *output << "\t\taddi\t$t0, $t0, -1\n";
            } else if (astNode->getId() == "&") {  //address
                *output << "\t\taddi\t$t0, $0, ref\n";
                *output << "\t\taddi\t$t0, $t0, offset\n";
            } else if (astNode->getId() == "+") {  //positive
                *output << "\t\taddu\t$t0, $t0, $0\n";
            } else if (astNode->getId() == "-") {  //negative
                *output << "\t\tsub\t$t0, $0, $t0\n";
            } else if (astNode->getId() == "~") {  //ones complement
                *output << "\t\tli\t$t1, -1\n"
                        << "\t\txor\t$t0, $t0, $t1\n";
            } else if (astNode->getId() == "!") {  //logical NOT
                *output << "\t\tsltu\t$t0, $0, $t0\n";  //set t0 to 1 if t0 > 0
                *output << "\t\txor\t$t0, $t0, $t0\n";  //inverse bits

            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
        } else if (astNode->getType() == "VARIABLE") {
            std::string id = context.identifier = astNode->getId();
            std::string type = astNode->getVarType();  // Normal, array, pointer
            if (Util::debug) std::cerr << "[DEBUG] VAR_NODE id: " << id << ". type: " << type << ", state: " << context.variableAssignmentState << "\n";
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
                        newVariable.frame = context.frameIndex;
                        newVariable.typeSpecifier = context.typeSpecifier;
                        context.variableBindings[id].push_back(newVariable);  // Append context to associated variiable in map

                    } else {                                                        // shadowing
                        int lastScope = context.variableBindings[id].back().scope;  // check if variable has been declared in this scope
                        int lastFrame = context.variableBindings[id].back().frame;  // check if variable has been declared in this frame
                        if (lastScope == context.scope && lastFrame == context.frameIndex) {
                            throw std::runtime_error("[ERROR] Variable \"" + id + "\" is already declared in this scope: " + std::to_string(context.scope) + "\n");
                        }
                        context.frameTracker[index].variableBytes += 8;  // Increment size of variable block in frame
                        // context.frameTracker[index].addVariable(id);  // Track variable id
                        VariableContext newVariable;
                        newVariable.addressOffset = context.frameTracker[index].totalBytes - context.frameTracker[index].variableBytes;  // Get next available memory address after vars
                        newVariable.varType = type;
                        newVariable.size = 8;
                        newVariable.scope = context.scope;
                        newVariable.frame = context.frameIndex;
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
                    throw std::runtime_error("[ERROR] Attempted read from undeclaraed " + type + " \"" + id + "\"\n");
                }
                if (type == "NORMAL") {
                    int addrOffset = getVariableAddressOffset(context, id);
                    std::string ref = getReferenceRegister(context, id);
                    *output << "\t\t"
                            << "lw\t$t0, " << addrOffset << ref << "\t\t# (var: normal) Reading from variable \"" << id << "\"\n"
                            << "\t\t"
                            << "nop\n";
                } else if (type == "ARRAY") {                                                      // Reading from array
                    int addrOffset = 8 * evalArrayIndexOrSize(context, astNode->getStatements());  // Element index stored in $t0
                    int arrayBase = getVariableAddressOffset(context, id);
                    std::string ref = getReferenceRegister(context, id);
                    // Add element index to array base
                    *output << "\t\t"
                            << "lw\t$t0, " << arrayBase + addrOffset << ref
                            << "\t\t# (var: array) Reading from array \"" << id << "\" at index " << addrOffset / 8 << "\n"
                            << "\t\t"
                            << "nop\n";
                } else if (type == "POINTER") {
                } else {
                    throw std::runtime_error("[ERROR] Unknown variable type of " + type);
                }

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
                    << "li\t$t0, " << astNode->getVal() << "\t\t\t\t# (int const)\n";
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
    if (!astNode || astNode->getType() == "FUNCTION_CALL") {
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
        if (keyValuePair.second.back().frame > context.scope) {
            context.variableBindings[keyValuePair.first].pop_back();  // Remove scope bindings
        }
        if (keyValuePair.second.back().scope > context.scope) {
            context.variableBindings[keyValuePair.first].pop_back();  // Remove scope bindings
        }
        if (keyValuePair.second.size() == 0) {
            context.variableBindings.erase(keyValuePair.first);  // Remove empty bindings
        }
    }
}

int getLastVariableAddressOffset(ProgramContext &context, const std::string &id) {
    // check for matching frame
    // if no matching frame, throw error
    // check for matching scope
    // if no matching scope, check all previous scopes
    // else , throw error
    // Iterating from back to front using reverse iterator
    int currentFrame = context.frameIndex;
    int currentScope = context.scope;
    for (auto it = context.variableBindings[id].rbegin(); it != context.variableBindings[id].rend(); ++it) {
        // Matching frame and scope
        if (it->frame == currentFrame && it->scope == currentScope) {
            return it->addressOffset;
            // Matching frame and previous scope
        } else if (it->frame == currentFrame && it->scope <= currentScope) {
            return it->addressOffset;
        }
    }
    throw std::runtime_error("[ERROR] Could not find variable binding in frame " + std::to_string(currentFrame) + ", scope " + std::to_string(currentScope) + "\n");
}

int getVariableAddressOffset(ProgramContext &context, const std::string &id) {
    try {
        // variable not bound
        if (!context.variableBindings.count(id)) {
            throw std::runtime_error("[ERROR] Could not find binding associated to variable \"" + id + "\"\n");
        } else {
            // get address offset of the last context associated with id.
            int offset;
            for (auto it = context.variableBindings[id].rbegin(); it != context.variableBindings[id].rend(); ++it) {
                if (it->frame == context.frameIndex && it->scope == context.scope) {  // Matching frame and scope
                    offset = it->addressOffset;
                    break;

                } else if (it->frame == context.frameIndex && it->scope <= context.scope) {  // Matching frame and previous scope
                    offset = it->addressOffset;
                    break;
                } else {
                    throw std::runtime_error("[ERROR] Could not find variable binding that matches frame " + std::to_string(context.frameIndex) + ", scope " + std::to_string(context.scope) + "\n");
                }
            }

            // verify address
            if (offset < 0) {
                throw std::runtime_error("[ERROR] Address offset associated to variable \"" + id + "\" outside of frame\n");
            }
            return offset;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        Util::abort;
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

std::pair<int, std::string> getOffsetAndReferenceRegister(ProgramContext &context, NodePtr identifierNode) {
    std::string id = context.identifier;
    std::string ref = getReferenceRegister(context, id);
    int offset;
    if (context.variableBindings[id].back().varType == "NORMAL") {
        offset = getVariableAddressOffset(context, id);
        ref = getReferenceRegister(context, id);
    } else if (context.variableBindings[id].back().varType == "ARRAY") {
        int addrOffset = 8 * evalArrayIndexOrSize(context, identifierNode->getStatements());
        int arrayBase = getVariableAddressOffset(context, id);
        offset = arrayBase + addrOffset;
    } else if (context.variableBindings[id].back().varType == "POINTER") {
        /* code */
    }
    return std::make_pair(offset, ref);
}

void clearRegisters(std::ostream *output) {
    *output << "\t\taddiu\t$t0, $0, 0\n";
    *output << "\t\taddiu\t$t1, $0, 0\n";
    *output << "\t\taddiu\t$t2, $0, 0\n";
    *output << "\t\taddiu\t$t3, $0, 0\n";
    *output << "\t\taddiu\t$t4, $0, 0\n";
    *output << "\t\taddiu\t$t5, $0, 0\n";
    *output << "\t\taddiu\t$t6, $0, 0\n";
    *output << "\t\taddiu\t$t7, $0, 0\n";
    *output << "\t\taddiu\t$t8, $0, 0\n";
    *output << "\t\taddiu\t$s0, $0, 0\n";
    *output << "\t\taddiu\t$s1, $0, 0\n";
    *output << "\t\taddiu\t$s2, $0, 0\n";
    *output << "\t\taddiu\t$s3, $0, 0\n";
    *output << "\t\taddiu\t$s4, $0, 0\n";
    *output << "\t\taddiu\t$s5, $0, 0\n";
    *output << "\t\taddiu\t$s6, $0, 0\n";
    *output << "\t\taddiu\t$s7, $0, 0\n";
}

void storeRegisters(std::ostream *output) {
    // Store address of previous frame on stack at 0($sp)
    *output << "\t\tsw\t$fp, 0($sp) \t\t# (fn def) Store addr of old fp on stack\n";
    *output << "\t\tadd\t$fp, $sp, $0 \t\t# (fn def) Move fp to new sp\n";
    *output << "\t\tsw\t$ra, 4($sp) \t\t# (fn def) Store ra on stack\n";
    *output << "\t\tsw\t$s0, 8($sp) \t\t# (fn def) Store save regs $s0-$s7 on stack\n";
    *output << "\t\tsw\t$s1, 12($sp)\n";
    *output << "\t\tsw\t$s2, 16($sp)\n";
    *output << "\t\tsw\t$s3, 20($sp)\n";
    *output << "\t\tsw\t$s4, 24($sp)\n";
    *output << "\t\tsw\t$s5, 28($sp)\n";
    *output << "\t\tsw\t$s6, 32($sp)\n";
    *output << "\t\tsw\t$s7, 36($sp)\n";
    *output << "\t\tsw\t$a0, 40($sp) \t\t# (fn def) Store prev fn args $a0-$a3 on stack\n";
    *output << "\t\tsw\t$a1, 44($sp)\n";
    *output << "\t\tsw\t$a2, 48($sp)\n";
    *output << "\t\tsw\t$a3, 52($sp)\n";
    *output << "\t\tsw\t$gp, 56($sp) \t\t# Store value of $gp on stack\n";
    // qemu lines
    if (Util::qemu) *output << "\t\t.cprestore 60\n";

    *output << "\t\t"
            << "nop\n";
}

void loadRegisters(std::ostream *output) {
    *output << "\t\tlw\t$s0, 8($fp) \t\t# (fn def) Load saved regs into $s0-$s7\n";
    *output << "\t\tlw\t$s1, 12($fp)\n";
    *output << "\t\tlw\t$s2, 16($fp)\n";
    *output << "\t\tlw\t$s3, 20($fp)\n";
    *output << "\t\tlw\t$s4, 24($fp)\n";
    *output << "\t\tlw\t$s5, 28($fp)\n";
    *output << "\t\tlw\t$s6, 32($fp)\n";
    *output << "\t\tlw\t$s7, 36($fp)\n";
    *output << "\t\tlw\t$a0, 40($fp)\n";
    *output << "\t\tlw\t$a1, 44($fp) \t\t# (fn def) Load prev fn args into $a0-$a3\n";
    *output << "\t\tlw\t$a2, 48($fp)\n";
    *output << "\t\tlw\t$a3, 52($fp)\n";
    *output << "\t\tlw\t$ra, 4($fp) \t\t# (fn def) Load return address into $ra\n";
    *output << "\t\tlw\t$fp, 0($fp) \t\t# (fn def) Load prev fp into $fp\n";
    *output << "\t\tnop\n";
}
