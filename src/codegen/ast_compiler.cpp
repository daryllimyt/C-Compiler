#include "../../include/ast.hpp"

// template <class T1, class T2>
// void addToHashedClass(T1 &container, const std::string &key, const T2& value);
void clearRegisters(std::ostream *output);
void functionPrologue(std::ostream *output, const int &bytes);
void functionEpilogue(std::ostream *output, const int &bytes);
// void updateVariableBindings(ProgramContext &context);
void evaluateExpression(std::ostream *output, ProgramContext &context, NodePtr astNode);
int getSize(ProgramContext &context, NodePtr astNode);
int getVariableAddressOffset(ProgramContext &context, const std::string &id);
int evalArrayIndexOrSize(ProgramContext &context, NodePtr astNode);
std::pair<bool, int> checkForVariableInFrame(ProgramContext &context, const std::string &id);
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
            +32 -> saved registers $s0 - $s7 (8*4 bytes)
            +4  -> return address in $ra
            +4  -> previous frame address in $fp
            +4  -> global address in $gp
            +(8-bytes%8) -> padding to ensure double-alignment of stack pointer, i.e. bytes is a multiple of 8 */
            int variablebytes = bytes - 8;
            bytes += (36 + (8 - (bytes % 8)));

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
                *output << "\n.set noreorder\n"
                        << ".text\n"
                        << ".globl " << id << "\n";  // Global flag for mips gcc
            }
            *output << id << ":\n";
            // qemu lines
            if (Util::qemu) {
                *output << "\t\t.ent " << id << "\n";
                // << "\t\t.frame $sp, " << bytes << ", $ra\n"
                // << "\t\t.align 2\n"
                // << "\t\t.cpload $t4\n";
            }

            context.scope++;
            *output << "\t\tsw\t$a0, 0($sp) \t\t# (fn def) Store arg regs in memory\n"
                    << "\t\tsw\t$a1, 8($sp) \t\t# (fn def) Store arg regs in memory\n"
                    << "\t\tsw\t$a2, 16($sp) \t\t# (fn def) Store arg regs in memory\n"
                    << "\t\tsw\t$a3, 24($sp) \t\t# (fn def) Store arg regs in memory\n"
                    << "\t\tmove\t$t9, $sp \t\t# (fn def) Store caller $sp in $t9 for argument calling\n";

            // Shift stack pointer and storing registers
            functionPrologue(output, bytes);

            context.variableAssignmentState = "FUNCTION_ARGUMENTS";
            Compile(output, context, astNode->getArgs());
            // if (Util::debug) {
            //     std::cerr << "#######################################################\n";
            //     std::cerr << context;
            //     std::cerr << "#######################################################\n";
            // }
            int argCount = context.functionBindings[id].args.size();
            if (argCount > 0) {
                *output << "\t\taddiu\t$sp, $sp, " << -8 * argCount << "\t\t# Move $sp to end of function arg section for local variables\n";
            }
            for (int i = 0; i < argCount; i++) {  // Load fn args to registers, save if more than 4
                int offset = getVariableAddressOffset(context, context.functionBindings[id].args[i]);
                std::string ref = getReferenceRegister(context, context.functionBindings[id].args[i]);
                *output << "\t\tlw\t$t0, "
                        << 8 * i << "($t9) \t\t\t# (fn args) Load fn call args from arg slots to $t0\n"
                        << "\t\tnop\n";
                *output << "\t\tsw\t$t0, "
                        << offset << ref << "\t\t\t# (fn args) Store fn call args from $t0 to memory\n";
            }

            context.scope--;

            // All function parameters are now in their respective variables in the new frame
            *output << "\t\taddiu\t$sp, $sp, " << -variablebytes << "\t# Move $sp to end of variable section before function call\n";
            // Get function body
            Compile(output, context, astNode->getScope());
            *output << "\n"
                    << functionEnd << ":\n";
            // Load saved registers and previous stack info from stack
            *output << "\t\taddiu\t$sp, $sp, " << (8 * argCount) + variablebytes << "\t# Move $sp to end of function arg section after function call\n";
            functionEpilogue(output, bytes);

            // Frame end
            context.frameIndex = 0;  // out of function, in global frame

            // If $ra == 0 then jump to end of program
            *output << "\t\tbeq\t$ra, $0, " << context.endLabel << "\n"
                    << "\t\tnop\n";

            // Return to previous frame
            *output << "\t\tjr\t$ra\n";
            *output << "\t\tnop\n";
            // qemu lines
            if (Util::qemu) *output << "\t\t.end " << id << "\n";
            context.functionEnds.pop_back();

        } else if (astNode->getType() == "FUNCTION_CALL") {
            context.variableAssignmentState = "FUNCTION_CALL";
            Compile(output, context, astNode->getIdentifier());
            std::string id = context.identifier;
            int argCount = context.functionBindings[id].args.size();  // Get arg count
            if (argCount < 4) {
                argCount = 4;
            }
            context.functionArgs.push_back(0);  // tracks arg count
            // int varBytes = context.frameTracker[context.frameIndex].variableBytes;  // Space allocated to variables
            int functionCallOffset = (8 * argCount);
            if (astNode->getParameters()) {
                *output << "\t\taddiu\t$sp, $sp, " << -functionCallOffset << "\t# (fn call) Expand stack for fn \"" << id << "\" arg slots\n";
                Compile(output, context, astNode->getParameters());  // Loading function arguments into arg slots
                // Load args from arg slots into $a0-$a3 before jal
                // Function args is now the number of function args
                for (int i = 0; i < context.functionArgs.back(); i++) {
                    if (i < 4) {
                        *output << "\t\tlw\t$a" << i << ", " << 8 * i << "($sp) \t\t# Load arguments into $a0-$a3\n";
                    } else {
                        break;
                    }
                }
            }                                                                     //assuming all arguments are in virtual registers up to $sp
            *output << "\t\tjal\t" << id << "\t\t\t\t# (fn call) enter fn def\n"  // return value of function call in $v0
                    << "\t\tnop\n";
            *output << "\t\taddiu\t$sp, $sp, " << functionCallOffset << "\t# (fn call) Shrink stack for fn \"" << id << "\" arg slots\n";
            context.functionArgs.pop_back();                    // Remove arg count for this function call
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
            }
        } else if (astNode->getType() == "MULTIPLE_PARAMETERS") {
            if (astNode->getStatements()) {
                context.variableAssignmentState = "NO_ASSIGN";       // Default state for function readings
                Compile(output, context, astNode->getStatements());  // get in t0 for vars, v0 for functions
                int argSlotPosition = context.functionArgs.back()++;
                if (argSlotPosition < 0) {
                    throw std::runtime_error("[ERROR] Negative arg slot offset\n");
                }
                if (context.variableAssignmentState == "FUNCTION_CALL") {  // From nested function call
                    *output << "\t\tsw\t$v0, ";
                } else {  // Normal variable
                    *output << "\t\tsw\t$t0, ";
                }
                *output << 8 * argSlotPosition << "($sp) \t\t# (fn call params) store in arg slot\n";
            }

            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());
            }

        } else if (astNode->getType() == "MULTIPLE_STATEMENTS") {
            context.variableAssignmentState = "NO_ASSIGN";         // Clear any previous variableAssignContext
            Compile(output, context, astNode->getStatements());    // Current statement
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());  // Any further statements
            }
        } else if (astNode->getType() == "ASSIGNMENT_STATEMENT") {
            // (type) id = statements = next;
            if (!astNode->getStatements() && !astNode->getNext()) {  // Single declarator
                if (context.variableAssignmentState == "VARIABLE_DECLARATION" || context.variableAssignmentState == "NO_ASSIGN") {
                    // temp : no assign comes from expressions
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: single declarator A\n";
                    Compile(output, context, astNode->getIdentifier());

                } else if (context.variableAssignmentState == "ASSIGNMENT_STATEMENT") {  // Recursive assignment terminal case
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: single declataror B, recursive terminal\n";
                    int offsetLeft = getVariableAddressOffset(context, context.identifier);  // Previous id
                    std::string refLeft = getReferenceRegister(context, context.identifier);

					if (context.enumerations.count(context.typeSpecifier) &&
					!context.enumerations[context.identifier].elements.count(astNode->getIdentifier()->getId())){
						throw std::runtime_error ("Enumerator not declared");
					}
                    context.variableAssignmentState = "NO_ASSIGN";
                    Compile(output, context, astNode->getIdentifier());  // Value of RHS loaded into $t0
                    *output << "\t\tsw\t$t0, " << offsetLeft << refLeft << "\t\t\t# (assign) store recursive assign\n";
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
					if (context.enumerations.count(context.typeSpecifier)){
						throw std::runtime_error( "Enumerations cannot be assigned directly");
					}
                    if (Util::debug) std::cerr << "[DEBUG] ASSIGNMENT_STATEMENT: non-single declarator A, math or bitwise\n";
                    Compile(output, context, astNode->getStatements());        // output -> $v0 (function) / $t0 (var)
                    if (context.variableAssignmentState == "FUNCTION_CALL") {  // From function call
                        *output << "\t\tsw\t$v0, " << offset << ref
                                << "\t\t\t# (assign) store fn result in " << context.variableBindings[id].back().varType << " variable \"" << id << "\"\n";
                    } else {  // Normal variable
                        *output << "\t\tsw\t$t0, " << offset << ref
                                << "\t\t\t# (assign) store var result in " << context.variableBindings[id].back().varType << " variable \"" << id << "\"\n";
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

            *output << "\n"
                    << start << ":\n";
            Compile(output, context, astNode->getCondition());  // Condition result stored in $t0
            *output << "\t\tbeq\t$t0, $0, " << next << "\n";    // If $t0==0 skip to else branch
            *output << "\t\tnop\n";

            Compile(output, context, astNode->getStatements());  // If statement
            *output << "\t\tj\t" << end << "\n";                 // Skips else statement
            *output << "\t\tnop\n";
            *output << "\n"
                    << next << ":\n";
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());  // Else or else if statement
            }

            *output << "\n"
                    << end << ":\n";

        } else if (astNode->getType() == "SWITCH_STATEMENT") {
            std::string label = createLabel(context, "_");
            std::string start = "switch_start" + label;
            std::string end = "switch_end" + label;
            context.breakPoints.push_back(end);

            *output << "\n"
                    << start << ":\n";
            *output << "\t\tli\t$s1, 1\n";
            Compile(output, context, astNode->getCondition());  //result in $t0

            if (context.variableAssignmentState == "FUNCTION_CALL") {
                *output << "\t\tmove\t$s0, $v0 \t\t# (switch) Storing the switch expression in $s0\n";
            } else {
                *output << "\t\tmove\t$s0, $t0\t\t# (switch) Storing the switch expression in $s0\n";
            }
            Compile(output, context, astNode->getNext());  //going into WRAPPED_CASE_STATEMENTS
            *output << "\n"
                    << end << ":\n";
            context.breakPoints.pop_back();
        } else if (astNode->getType() == "MULTIPLE_CASE_STATEMENTS") {
            context.variableAssignmentState = "NO_ASSIGN";  // Clear any previous variableAssignContext

            if (astNode->getStatements()) {
                Compile(output, context, astNode->getStatements());
            }
            if (astNode->getNext()) {
                Compile(output, context, astNode->getNext());
            }
        } else if (astNode->getType() == "SINGLE_CASE_STATEMENT") {
            std::string label = createLabel(context, "_");
            std::string start = "case_start" + label;
            std::string end = "case_end" + label;

            *output << "\n"
                    << start << ":\n";
            Compile(output, context, astNode->getCondition());  //result in $t0
            *output << "\t\tslt\t$t1, $t0, $s0\n";
            *output << "\t\tslt\t$t2, $s0, $t0\n";
            *output << "\t\tor\t$t0, $t1, $t2\n";   //t0 == 1 if t0 != s0
            *output << "\t\tand\t$t0, $t0, $s1\n";  //branch if t0 == s1 == 1
            *output << "\t\tbgtz\t$t0, " << end
                    << "\t\t# (case) branching past case if expr not same\n";
            *output << "\t\tmove\t$s1, $0\n";
            if (astNode->getStatements()) {
                Compile(output, context, astNode->getStatements());
            }
            *output << "\n"
                    << end << ":\n";
        } else if (astNode->getType() == "DEFAULT_STATEMENT") {
            std::string label = createLabel(context, "_");
            std::string start = "default_start" + label;
            std::string end = "default_end" + label;

            *output << "\t\tj " << end << "\n"  //go to end
                    << "\t\tnop\n";
            *output << "\n"
                    << start << ":\n";
            if (astNode->getStatements()) {
                Compile(output, context, astNode->getStatements());
            }
            *output << "\t\tj\t" << context.breakPoints.back() << "\n"
                    << "\t\tnop\n";
            *output << "\n"
                    << end << ":\n";
        } else if (astNode->getType() == "WHILE_LOOP") {
            std::string label = createLabel(context, "_");
            std::string start = "while_start" + label;
            std::string end = "while_end" + label;
            std::string continue_ = "while_continue" + label;
            context.continuePoints.push_back(continue_);
            context.breakPoints.push_back(end);
            if (astNode->getVal() == 1) {  //if loop is a do while loop - do an iteration before checking conditions
                Compile(output, context, astNode->getNext());
            }

            *output << "\n"
                    << start << ":\n";
            Compile(output, context, astNode->getCondition());  //result in t0
            *output << "\t\tbeq\t$t0, $0, " << end << "\n";     // condition returns 0 (false), exit while loop
            *output << "\t\tnop"
                    << "\n";
            Compile(output, context, astNode->getNext());
            *output << "\n"
                    << continue_ << ":\n";
            *output << "\t\tj\t" << start << "\n";  // unconditional jump to start
            *output << "\t\tnop"
                    << "\n";

            *output << "\n"
                    << end << ":\n";
            context.breakPoints.pop_back();     //popping end
            context.continuePoints.pop_back();  //popping continue_
        } else if (astNode->getType() == "FOR_LOOP") {
            std::string label = createLabel(context, "_");
            std::string start = "for_start" + label;
            std::string end = "for_end" + label;
            std::string continue_ = "for_continue" + label;
            context.continuePoints.push_back(continue_);
            context.breakPoints.push_back(end);

            context.scope++;
            if (astNode->getConditionOne()) {
                Compile(output, context, astNode->getConditionOne());  // Initialize the iterator
            }
            *output << "\n"
                    << start << ":\n";
            if (astNode->getConditionTwo()) {
                Compile(output, context, astNode->getConditionTwo());  // Evaluate condition, result in t0
            }
            *output << "\t\tbeq\t$t0, $0, " << end << "\n";
            *output << "\t\tnop\n";
            Compile(output, context, astNode->getNext());
            *output << "\n"
                    << continue_ << ":\n";
            if (astNode->getConditionThree()) {
                Compile(output, context, astNode->getConditionThree());  // Modifying the iterator
            }
            context.scope--;

            *output << "\t\tj\t" << start << "\n";
            *output << "\t\tnop\n";

            *output << "\n"
                    << end << ":\n";
            context.breakPoints.pop_back();     //popping end
            context.continuePoints.pop_back();  //popping continue
        } else if (astNode->getType() == "ASSIGNMENT_EXPRESSION") {
            std::string id = astNode->getLeft()->getId();        // LHS Variable ID
            evaluateExpression(output, context, astNode);        // $t0 = LHS, $t1 = RHS
            Compile(output, context, astNode->getIdentifier());  // Evaluate result in $t0
            // x += y
            // x = x + y
            std::pair<int, std::string> addressInfo = getOffsetAndReferenceRegister(context, astNode->getLeft());
            int offset = addressInfo.first;
            std::string ref = addressInfo.second;
            *output << "\t\tsw\t$t0, " << offset << ref << "\t\t\t\t# (assign expr) storing evaluated expression from $t0 to LHS variable in memory\n";

        } else if (astNode->getType() == "UNARY_EXPRESSION") {
            Compile(output, context, astNode->getRight());       // Identifier - stores result in t0
            Compile(output, context, astNode->getIdentifier());  // Operator - process t0 and restore it in t0
            if (astNode->getRight()->getType() == "VARIABLE" && (astNode->getIdentifier()->getId() == "--" || astNode->getIdentifier()->getId() == "++")) {
                std::pair<int, std::string> addressInfo = getOffsetAndReferenceRegister(context, astNode->getRight());
                int offset = addressInfo.first;
                std::string ref = addressInfo.second;
                *output << "\t\tsw\t$t0, " << offset << ref << "\t\t# (unary) storing to variable\n";
            }
        } else if (astNode->getType() == "MULTIPLICATIVE_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "*") {
                *output << "\t\tmult\t$t0, $t1\n";
                *output << "\t\tmflo\t$t0\n";
            } else if (astNode->getId() == "/") {
                *output << "\t\tdiv\t$t0, $t1\n";
                *output << "\t\tmflo\t$t0\n";
            } else if (astNode->getId() == "%") {
                *output << "\t\tdiv\t$t0, $t1\n";
                *output << "\t\tmfhi\t$t0\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
        } else if (astNode->getType() == "ADDITIVE_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "+") {
                *output << "\t\tadd\t$t0, $t0, $t1 \t\t# (add node) LHS + RHS\n";
            } else if (astNode->getId() == "-") {
                *output << "\t\tsub\t$t0, $t0, $t1 \t\t# (add node) LHS - RHS\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
        } else if (astNode->getType() == "BITWISE_AND_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            *output << "\t\tand\t$t0, $t0, $t1\n";
        } else if (astNode->getType() == "BITWISE_XOR_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            *output << "\t\txor\t$t0, $t0, $t1\n";
        } else if (astNode->getType() == "BITWISE_OR_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            *output << "\t\tor\t$t0, $t0, $t1\n";
        } else if (astNode->getType() == "BOOLEAN_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "and") {
                *output << "\t\tsltu\t$t0, $0, $t0\n";  //set t0 to 1 if t0 > 0
                *output << "\t\tsltu\t$t1, $0, $t1\n";  //set t1 to 1 if t1 > 0
                *output << "\t\tand\t$t0, $t0, $t1\n";  //set t0 to (t0 && t1)
            } else if (astNode->getId() == "or") {
                *output << "\t\tsltu\t$t0, $0, $t0\n";  //set t0 to 1 if t0 > 0
                *output << "\t\tsltu\t$t1, $0, $t1\n";  //set t1 to 1 if t1 > 0
                *output << "\t\tor\t$t0, $t0, $t1\n";   //set t0 to (t0 || t1)

            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
            *output << "\t\t"
                    << "andi\t$t0, $t0, 1\n";  // Extract bits
        } else if (astNode->getType() == "EQUALITY_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            *output << "\t\tslt\t$v0, $t0, $t1\n"
                    << "\t\tslt\t$v1, $t1, $t0\n"
                    << "\t\txor\t$t0, $v0, $v1\n"
                    << "\t\tsltiu\t$t0, $t0, 1\n";
        } else if (astNode->getType() == "SHIFT_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "<<") {
                *output << "\t\tsll\t$t0, $t0, $t1\n";
            } else if (astNode->getId() == ">>") {
                *output << "\t\tsra\t$t0, $t0, $t1\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
        } else if (astNode->getType() == "RELATIONAL_EXPRESSION") {
            context.variableAssignmentState = "NO_ASSIGN";
            evaluateExpression(output, context, astNode);
            if (astNode->getId() == "<") {
                *output << "\t\tslt\t$t0, $t0, $t1\n";
            } else if (astNode->getId() == ">") {
                *output << "\t\tslt\t$t0, $t1, $t0\n";
            } else if (astNode->getId() == "<=") {
                *output << "\t\tslt\t$t0, $t1, $t0\n"
                        << "\t\tsltiu\t$t0, $t0, 1\n";
            } else if (astNode->getId() == ">=") {
                *output << "\t\tslt\t$t0, $t0, $t1\n"
                        << "\t\tsltiu\t$t0, $t0, 1\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
        } else if (astNode->getType() == "POSTFIX_EXPRESSION") {
            Compile(output, context, astNode->getLeft());  //identifier
            std::string id = context.identifier;
            std::pair<int, std::string> addressInfo = getOffsetAndReferenceRegister(context, astNode->getLeft());
            int offset = addressInfo.first;
            std::string ref = addressInfo.second;
            *output << "\t\tlw\t$t0, " << offset << ref
                    << "\t\t# (postfix) store var result in " << context.variableBindings[id].back().varType << " variable \"" << id << "\"\n"
                    << "\t\tnop\n";

            *output << "\t\tmove\t$t1, $t0\n";
            if (astNode->getId() == "++") {
                *output << "\t\taddi\t$t0, $t0, 1\n";
            } else if (astNode->getId() == "--") {
                *output << "\t\taddi\t$t0, $t0, -1\n";
            } else {
                throw std::runtime_error("[ERROR] Invalid operator for " + astNode->getType());
            }
            *output << "\t\tsw\t$t0, " << offset << ref << "\n";
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
                Compile(output, context, astNode->getReturnValue());       // RV either $v0 or $t0
                if (context.variableAssignmentState != "FUNCTION_CALL") {  // From function call
                    *output << "\t\tmove\t$v0, $t0 \t\t# (return node) load $t0 to $v0 if not function call\n";
                }
            } else if (context.returnType == "VOID") {
                *output << "\t\tnop\n";
            } else {
                throw std::runtime_error("[ERROR] Int type function requires return type INT, got \"" + context.returnType + "\" instead");
            }
            *output << "\t\tj\t" << context.functionEnds.back() << "\n"
                    << "\t\tnop\n";
        } else if (astNode->getType() == "BREAK") {
            *output << "\t\tj\t" << context.breakPoints.back() << "\n"
                    << "\t\tnop\n";
        } else if (astNode->getType() == "CONTINUE") {
            *output << "\t\tj\t" << context.continuePoints.back() << "\n"
                    << "\t\tnop\n";
        } else if (astNode->getType() == "VOID") {
            context.typeSpecifier = "VOID";
        } else if (astNode->getType() == "SIZE_OF") {
			context.assignmentState = "NO_ASSIGN";
            Compile(output, context, astNode->getNext());
            if (context.typeSpecifier == "CHAR") {
                *output << "\t\tli\t$t0, 1\n";
            } else if (context.typeSpecifier == "SHORT") {
                *output << "\t\tli\t$t0, 2\n";
            } else if (context.typeSpecifier == "INT") {
                *output << "\t\tli\t$t0, 4\n";
            } else if (context.typeSpecifier == "LONG") {
                *output << "\t\tli\t$t0, 4\n";
            } else if (context.typeSpecifier == "FLOAT") {
                *output << "\t\tli\t$t0, 4\n";
            } else if (context.typeSpecifier == "DOUBLE") {
                *output << "\t\tli\t$t0, 8\n";
            } else if (context.typeSpecifier == "SIGNED") {
                *output << "\t\tli\t$t0, 4\n";
            } else if (context.typeSpecifier == "UNSIGNED") {
                *output << "\t\tli\t$t0, 4\n";
            } else if (context.typeSpecifier == "BOOL") {
                *output << "\t\tli\t$t0, 1\n";
            } else {
				*output << "\t\tli\t$t0, " << sizeof(astNode->getNext->getVal())
				<< "\n";
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
        } else if (astNode->getType() == "CUSTOM_TYPE") {
			std::string typeName = astNode->getId();
			if(context.enumerations[typeName]){
				context.typeSpecifier = typeName;
			} else {
				throw std::runtime_error (" Type not declared ");
			}

        } else if (astNode->getType() == "ASSIGNMENT_OPERATOR") {
            // $t0 = LHS, $t1 = RHS
            if (astNode->getId() == "*=") {
                *output << "\t\tmult\t$t0, $t1 \t\t\t# (assign op node) LHS *= RHS\n";
                *output << "\t\tmflo\t$t0\n";
            } else if (astNode->getId() == "/=") {
                *output << "\t\tdiv\t$t0, $t1 \t\t\t# (assign op node) LHS /= RHS\n";
                *output << "\t\tmflo\t$t0\n";
            } else if (astNode->getId() == "%=") {
                *output << "\t\tdiv\t$t0, $t1 \t\t\t# (assign op node) LHS %= RHS\n";
                *output << "\t\tmfhi\t$t0\n";
            } else if (astNode->getId() == "+=") {
                *output << "\t\tadd\t$t0, $t0, $t1 \t\t\t# (assign op node) LHS += RHS\n";
            } else if (astNode->getId() == "-=") {
                *output << "\t\tsub\t$t0, $t0, $t1 \t\t\t# (assign op node) LHS -= RHS\n";
            } else if (astNode->getId() == "<<=") {
                *output << "\t\tsll\t$t0, $t0, $t1 \t\t\t# (assign op node) LHS <<= RHS\n";
            } else if (astNode->getId() == ">>=") {
                *output << "\t\tsra\t$t0, $t0, $t1 \t\t\t# (assign op node) LHS >>= RHS\n";
            } else if (astNode->getId() == "&=") {
                *output << "\t\tand\t$t0, $t0, $t1 \t\t\t# (assign op node) LHS &= RHS\n";
            } else if (astNode->getId() == "^=") {
                *output << "\t\txor\t$t0, $t0, $t1 \t\t\t# (assign op node) LHS ^= RHS\n";
            } else if (astNode->getId() == "|=") {
                *output << "\t\tor\t$t0, $t0, $t1 \t\t\t# (assign op node) LHS |= RHS\n";
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
            } else if (astNode->getId() == "!") {       //logical NOT
                *output << "\t\tsltu\t$t0, $0, $t0\n";  //set t0 to 1 if t0 > 0
                *output << "\t\txori\t$t0, $t0, 1\n";   //inverse bits
                *output << "\t\tandi\t$t0, $t0, 1\n";   //extract lsb

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
                    std::pair<bool, int> varInfo = checkForVariableInFrame(context, id);  // (in-frame status, scope)
                    if (!varInfo.first) {                                                 // If false means variable not in the current frame. Non-shadowing
                        if (context.scope == 0) {
                            index = 0;  // For global variables
                        }
                        VariableContext newVariable;
                        newVariable.addressOffset = -context.frameTracker[index].variableBytes;  // Get next available memory address after vars
                        newVariable.varType = type;
                        newVariable.size = 8;
                        newVariable.scope = context.scope;
                        newVariable.frame = context.frameIndex;
                        newVariable.typeSpecifier = context.typeSpecifier;
                        context.variableBindings[id].push_back(newVariable);  // Append context to associated variiable in map
                        context.frameTracker[index].variableBytes += 8;       // Increment size of variable block in frame
                        // *output << "\t\taddiu\t$sp, $sp, -8 \t# (var) Decrement $sp for variable \"" << id << "\"\n";
                    } else {  // True means variable in the current frame
                        // Variable in current frame, check which scope it was found in
                        if (varInfo.second == context.scope) {
                            throw std::runtime_error("[ERROR] Variable \"" + id + "\" is already declared in this scope: " + std::to_string(context.scope) + "\n");
                        }

                        // context.frameTracker[index].addVariable(id);  // Track variable id
                        VariableContext newVariable;
                        newVariable.addressOffset = -context.frameTracker[index].variableBytes;  // Get next available memory address after vars
                        newVariable.varType = type;
                        newVariable.size = 8;
                        newVariable.scope = context.scope;
                        newVariable.frame = context.frameIndex;
                        newVariable.typeSpecifier = context.typeSpecifier;
                        context.variableBindings[id].push_back(newVariable);  // Append context to associated variiable in map
                        context.frameTracker[index].variableBytes += 8;       // Increment size of variable block in frame
                        // *output << "\t\taddiu\t$sp, $sp, -8 \t# (var) Decrement $sp for variable \"" << id << "\"\n";
                    }
                } else if (type == "ARRAY") {
                    int index = context.frameIndex;
                    if (context.scope == 0) {
                        index = 0;  // For global variables
                    }
                    int arrayBytes = 8 * evalArrayIndexOrSize(context, astNode->getStatements());
                    VariableContext newVariable;
                    // Array base offset is at the bottom of the array block in memory
                    newVariable.addressOffset = -context.frameTracker[index].variableBytes;  // Get next available memory address after vars
                    newVariable.varType = type;
                    newVariable.size = arrayBytes;
                    newVariable.scope = context.scope;
                    newVariable.typeSpecifier = context.typeSpecifier;
                    context.variableBindings[id].push_back(newVariable);      // Append context to associated variiable in map
                    context.frameTracker[index].variableBytes += arrayBytes;  // Increment number of variables in frame
                    // *output << "\t\taddiu\t$sp, $sp, " << -arrayBytes << " \t# (var) Decrement $sp for variable \"" << id << "\"\n";
                } else if (type == "POINTER") {
                    // int index = context.frameIndex;
                    // if (context.variableBindings.count(id) == 0) {  // Non-shadowing
                    //     if (context.scope == 0) {
                    //         index = 0;  // For global variables
                    //     }
                    //     context.frameTracker[index].variableBytes += 8;  // Increment size of variable block in frame
                    //     // context.frameTracker[index].addVariable(id);  // Track variable id
                    //     VariableContext newVariable;
                    //     newVariable.addressOffset = context.frameTracker[index].totalBytes - context.frameTracker[index].variableBytes;  // Get next available memory address after vars
                    //     newVariable.varType = type;
                    //     newVariable.size = 8;
                    //     newVariable.scope = context.scope;
                    //     newVariable.frame = context.frameIndex;
                    //     newVariable.typeSpecifier = context.typeSpecifier;
                    //     context.variableBindings[id].push_back(newVariable);  // Append context to associated variable in map

                    // } else {                                                        // shadowing
                    //     int lastScope = context.variableBindings[id].back().scope;  // check if variable has been declared in this scope
                    //     int lastFrame = context.variableBindings[id].back().frame;  // check if variable has been declared in this frame
                    //     if (lastScope == context.scope && lastFrame == context.frameIndex) {
                    //         throw std::runtime_error("[ERROR] Variable \"" + id + "\" is already declared in this scope: " + std::to_string(context.scope) + "\n");
                    //     }
                    //     context.frameTracker[index].variableBytes += 8;  // Increment size of variable block in frame
                    //     // context.frameTracker[index].addVariable(id);  // Track variable id
                    //     VariableContext newVariable;
                    //     newVariable.addressOffset = context.frameTracker[index].totalBytes - context.frameTracker[index].variableBytes;  // Get next available memory address after vars
                    //     newVariable.varType = type;
                    //     newVariable.size = 8;
                    //     newVariable.scope = context.scope;
                    //     newVariable.frame = context.frameIndex;
                    //     newVariable.typeSpecifier = context.typeSpecifier;
                    //     context.variableBindings[id].push_back(newVariable);  // Append context to associated variiable in map
                    // }
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
                    *output << "\t\tlw\t$t0, " << addrOffset << ref << "\t\t\t# (var: normal) Reading from variable \"" << id << "\"\n"
                            << "\t\tnop\n";

				 	context.typeSpecifier = context.variableBindings[id].back().typeSpecifier;
                } else if (type == "ARRAY") {                                                      // Reading from array
                    int addrOffset = 8 * evalArrayIndexOrSize(context, astNode->getStatements());  // Element index stored in $t0
                    int arrayBase = getVariableAddressOffset(context, id);
                    std::string ref = getReferenceRegister(context, id);
                    // Add element index to array base
                    *output << "\t\tlw\t$t0, " << arrayBase + addrOffset << ref
                            << "\t# (var: array) Reading from array \"" << id << "\" at index " << addrOffset / 8 << "\n"
                            << "\t\tnop\n";
                } else if (type == "POINTER") {
                    // int addrOffset = getVariableAddressOffset(context, id);
                    // std::string ref = getReferenceRegister(context, id);
                    // *output << "\t\tlw\t$t0, " << addrOffset << ref << "\t\t# (var: normal) Reading from variable \"" << id << "\"\n"
                    //         << "\t\tnop\n";

                } else {
                    throw std::runtime_error("[ERROR] Unknown variable type of " + type);
                }

            } else if (context.variableAssignmentState == "ASSIGNMENT_STATEMENT") {  // Writing to existing variable
                if (!context.variableBindings.count(id) &&
                    !context.functionBindings.count(id) &&
                    !context.declaredFunctions.count(id)) {  // Varibale does not exist
                    throw std::runtime_error("[ERROR] Assignment to undeclared variable " + id + "\n");
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
            *output << "\t\tli\t$t0, " << astNode->getVal() << "\t\t\t\t# (int const)\n";
        } else if (astNode->getType() == "FLOAT_CONSTANT") {
        } else if (astNode->getType() == "STRING_LITERAL") {
        } else if (astNode->getType() == "ENUMERATION") {

			EnumContext newEnum;
			newEnum.typeSpecifer = context.typeSpecifier;
			newEnum.val = 0;
			newNum.frame = context.frame;
			newNum.scope = context.scope;
			context.enumerations[astNode->getId()] = newEnum;
			context.allEnumerations.push_back(astNode->getId());

			Compile(output, context, astNode->getStatements());



        } else if (astNode->getType() == "MULTIPLE_ENUMERATORS") {
			Compile(output, context, astNode->getStatement());

			if(astNode->getNext()){
				Compile(output, context, astNode->getNext());
			}
        } else if (astNode->getType() == "SINGLE_ENUMERATOR") {
            std::string id = context.identifier = astNode->getId();
            int index = context.frameIndex;
			if (context.variableBindings.count(id) == 0) {  // Variable declaration
				if (context.scope == 0) {
					index = 0;  // For global variables
				}
				VariableContext newVariable;
				newVariable.addressOffset = context.frameTracker[index].totalBytes - context.frameTracker[index].variableBytes;  // Get next available memory address after vars
				newVariable.varType = type;
				newVariable.size = 8;
				newVariable.scope = context.scope;
				newVariable.frame = context.frameIndex;
				newVariable.typeSpecifier = context.typeSpecifier;
				context.variableBindings[id].push_back(newVariable);  // Append context to associated variiable in map
				context.frameTracker[index].variableBytes += 8;  // Increment size of variable block in frame
				context.enumerations[context.allEnumerations.back()].elements.insert(id);
                }
			else {
				throw std::runtime_error("Enumerator already declared");
			}
			//assignment
			int offset = getVariableAddressOffset(context, id);
			std::string ref = getReferenceRegister(ProgramContext &context, const std::string &id);
			context.variableAssignmentState = "ASSIGNMENT_STATEMENT";
			if (astNode->getStatements()) {  // Math or bitwise
				Compile(output, context, astNode->getStatements());        // output -> $t0 (var)
				if (context.variableAssignmentState == "FUNCTION_CALL") {  // From function call
					throw std::runtime_error("Cannot use functions for enumerators");
				} else {
					*output << "\t\tsw\t$t0, " << offset << ref
							<< "\t\t# (assign) store var result in " << context.variableBindings[id].back().varType << " variable \"" << id << "\n";
					context.enumerations[id].val = evalArrayIndexOrSize(context, astNode->getStatements());
				}
			} else {
				*output << "\t\tli\t$t0, " << ++context.enumerations[id].val << "\t\t# (enumerator) using value of previous + 1\n";
				*output << "\t\tsw\t$t0, " << offset << ref
						<< "\t\t# (assign) store var result in " << context.variableBindings[id].back().varType << " variable \"" << id << "\n";
			}
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

std::string createLabel(ProgramContext &context, const std::string &name) {
    return name + std::to_string(context.labelCount++);
}

int getSize(ProgramContext &context, NodePtr astNode) {
    // Base cases
    if (!astNode) {
        return 0;
    }

    int bytes = 0;
    if (astNode->getType() == "VARIABLE") {
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
        bytes += getSize(context, astNode->getStatements());
        bytes += getSize(context, astNode->getScope());
        bytes += getSize(context, astNode->getParameters());
    }
    return bytes;
}

// void removeVarsFromScope(ProgramContext &context) {
//     for (auto &keyValuePair : context.variableBindings) {
//         if (keyValuePair.second.back().scope > context.scope) {
//             context.variableBindings[keyValuePair.first].pop_back();  // Remove scope bindings
//         }
//         if (keyValuePair.second.size() == 0) {
//             context.variableBindings.erase(keyValuePair.first);  // Remove empty bindings
//         }
//     }
// }
// void removeVarsFromFrame(ProgramContext &context) {
//     for (auto &keyValuePair : context.variableBindings) {
//         if (keyValuePair.second.back().frame < context.frameIndex) {  // Remove previous
//             context.variableBindings[keyValuePair.first].pop_back();  // Remove scope bindings
//         }
//     }
// }
std::pair<bool, int> checkForVariableInFrame(ProgramContext &context, const std::string &id) {
    bool status = false;
    int scope = -1;
    int currentFrame = context.frameIndex;
    for (auto it = context.variableBindings[id].rbegin(); it != context.variableBindings[id].rend(); ++it) {
        // Matching frame
        if (it->frame == currentFrame) {
            status = true;
            scope = it->scope;
            break;
        }
        return std::make_pair(status, scope);  // (false, -1) means not found in frame
    }
}

std::pair<int, std::string> getOffsetAndReferenceRegister(ProgramContext &context, NodePtr identifierNode) {
    std::string id = context.identifier;
    std::string ref = getReferenceRegister(context, id);
    int offset;
    if (context.variableBindings[id].back().varType == "NORMAL") {
        offset = getVariableAddressOffset(context, id);
    } else if (context.variableBindings[id].back().varType == "ARRAY") {
        int addrOffset = 8 * evalArrayIndexOrSize(context, identifierNode->getStatements());
        int arrayBase = getVariableAddressOffset(context, id);
        offset = arrayBase + addrOffset;
    } else if (context.variableBindings[id].back().varType == "POINTER") {
        /* code */
    }
    return std::make_pair(offset, ref);
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
                }
            }
            // if (offset > 0) {
            //     throw std::runtime_error("[ERROR] Could not find variable binding that matches frame " + std::to_string(context.frameIndex) + ", scope " + std::to_string(context.scope) + "\n");
            // }
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
        Util::abort;
    }
}

void evaluateExpression(std::ostream *output, ProgramContext &context, NodePtr astNode) {
    *output << "\t\taddiu\t$sp, $sp, -8 \t\t# (eval expr) Expand stack for expression evaluation\n";
    Compile(output, context, astNode->getRight());             // identifier - RHS result are in virtual memory
    if (context.variableAssignmentState == "FUNCTION_CALL") {  // From function call
        *output << "\t\tsw\t$v0, 0($sp) \t\t# (eval expr) store RHS in memory\n";
    } else {  // Normal variable
        *output << "\t\tsw\t$t0, 0($sp) \t\t# (eval expr) store RHS in memory\n";
    }
    context.variableAssignmentState = "NO_ASSIGN";             // Reading var
    Compile(output, context, astNode->getLeft());              //expr - LHS result stored in $t0
    if (context.variableAssignmentState == "FUNCTION_CALL") {  // From function call
        *output << "\t\t"
                << "move\t$t0, $v0 \t\t# (eval expr) LHS from fn call\n";
    }
    *output << "\t\tlw\t$t1, 0($sp) \t\t# (eval expr) load RHS from memory to $t1, LHS in $t0\n"
            << "\t\tnop\n";
    *output << "\t\taddiu\t$sp, $sp, 8 \t\t# (eval expr) Shrinking stack after evaluation\n";
    context.variableAssignmentState = "NO_ASSIGN";  // Reading var
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

void functionPrologue(std::ostream *output, const int &bytes) {
    // Store address of previous frame on stack at 0($sp)
    // *output << "\t\tmove\t$t8, $sp \t\t# Save old $sp to restore in $fp later\n";
    *output << "\t\taddiu\t$sp, $sp, " << -12 << "\t\t# (fn def: frame start) Expand stack for saved registers\n";
    *output << "\t\tsw\t$fp, 4($sp) \t\t# (fn def)\n";
    *output << "\t\tsw\t$ra, 8($sp) \t\t# (fn def)\n";
    // if (Util::qemu) *output << "\t\t.cprestore 12\n";

    // *output << "\t\tsw\t$s0, 0($sp) \t\t# (fn def) Store save regs $s0-$s7 on stack\n";
    // *output << "\t\tsw\t$s1, 4($sp)\n";
    // *output << "\t\tsw\t$s2, 8($sp)\n";
    // *output << "\t\tsw\t$s3, 12($sp)\n";
    // *output << "\t\tsw\t$s4, 16($sp)\n";
    // *output << "\t\tsw\t$s5, 20($sp)\n";
    // *output << "\t\tsw\t$s6, 24($sp)\n";
    // *output << "\t\tsw\t$s7, 28($sp)\n";
    // *output << "\t\tsw\t$ra, 32($sp) \t\t# (fn def) Store ra on stack\n";
    // *output << "\t\tsw\t$gp, 36($sp) \t\t# (fn def) Store value of $gp on stack\n";
    // *output << "\t\tsw\t$fp, 40($sp) \t\t# (fn def) Store addr of old fp on stack\n";
    *output << "\t\tmove\t$fp, $sp \t\t# $fp is at the start of the variable section\n";
    // $sp now points to arg slots
}

void functionEpilogue(std::ostream *output, const int &bytes) {
    // *output << "\t\tlw\t$s0, 0($sp) \t\t# (fn def) Store save regs $s0-$s7 on stack\n";
    // *output << "\t\tlw\t$s1, 4($sp)\n";
    // *output << "\t\tlw\t$s2, 8($sp)\n";
    // *output << "\t\tlw\t$s3, 12($sp)\n";
    // *output << "\t\tlw\t$s4, 16($sp)\n";
    // *output << "\t\tlw\t$s5, 20($sp)\n";
    // *output << "\t\tlw\t$s6, 24($sp)\n";
    // *output << "\t\tlw\t$s7, 28($sp)\n";
    // *output << "\t\tlw\t$ra, 32($sp) \t\t# (fn def) Store ra on stack\n";
    // *output << "\t\tlw\t$gp, 36($sp) \t\t# (fn def) Store value of $gp on stack\n";
    // *output << "\t\tlw\t$fp, 40($sp) \t\t# (fn def) Store addr of old fp on stack\n";
    *output << "\t\tmove\t$sp, $fp \t\t# Restore sp to start of variable section\n";
    *output << "\t\tlw\t$fp, 4($sp) \t\t# (fn def)\n";
    *output << "\t\tlw\t$ra, 8($sp) \t\t# (fn def)\n";
    *output << "\t\taddiu\t$sp, $sp, " << 12 << "\t\t# (fn def: frame end) Shrink stack back to previous frame\n";
}
