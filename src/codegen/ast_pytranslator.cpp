#include "../../include/ast.hpp"

void indent(std::ostream *output, ProgramContext &context);
void addVarToGlobal(ProgramContext &context, const std::string &id);
void addVarToScope(ProgramContext &context, const std::string &id);

int32_t PyTranslate(std::ostream *output, ProgramContext &context, NodePtr astNode) {
    try {
        if (astNode == NULL) {
            throw std::runtime_error("Unhandled NULL-type ast node \n");
        } else if (astNode->getType() == "ROOT") {
            PyTranslate(output, context, astNode->getNext());

        } else if (astNode->getType() == "FRAME") {
            context.variableAssignmentState = "GLOBAL";
            PyTranslate(output, context, astNode->getLeft());
            PyTranslate(output, context, astNode->getRight());

        } else if (astNode->getType() == "FUNCTION_DECLARATION") {
            // Do nothing, function declarations not supported in Python
        } else if (astNode->getType() == "FUNCTION_DEFINITION") {
            context.variableAssignmentState = "FUNCTION_DEFINITION";
            // Function has arguments
            if (astNode->getArgs()) {
                *output << "def ";
                if (!context.allFunctionsTranslator.count(astNode->getIdentifier()->getId())) {  // Record function name in context
                    context.allFunctionsTranslator.insert(astNode->getIdentifier()->getId());
                }
                PyTranslate(output, context, astNode->getIdentifier());
                PyTranslate(output, context, astNode->getArgs());
                *output << ":\n";
                context.scope++;

                for (auto &it : context.globalVariables) {
                    indent(output, context);
                    *output << "global " << it << "\n";
                }

                PyTranslate(output, context, astNode->getScope());  // Scope of the function
                context.scope--;
                *output << "\n";
            }
        } else if (astNode->getType() == "FUNCTION_CALL") {
            PyTranslate(output, context, astNode->getIdentifier());
            PyTranslate(output, context, astNode->getParameters());

        } else if (astNode->getType() == "PARENTHESIS_WRAPPER") {
            *output << "(";
            if (astNode->getStatements()) {
                PyTranslate(output, context, astNode->getStatements());
            }
            if (astNode->getNext()) {
                PyTranslate(output, context, astNode->getNext());
            }
            *output << ")";

        } else if (astNode->getType() == "MULTIPLE_ARGUMENTS") {
            if (astNode->getArgs()) {
                if (!context.functionArgs.count(astNode->getArgs()->getStatements()->getId())) {  // Record function arg in context
                    context.functionArgs.insert(astNode->getArgs()->getStatements()->getId());
                }
                PyTranslate(output, context, astNode->getArgs());
            }
            if (astNode->getNext()) {
                *output << ", ";
                PyTranslate(output, context, astNode->getNext());
            }
        } else if (astNode->getType() == "MULTIPLE_PARAMETERS") {
            if (astNode->getStatements()) {
                PyTranslate(output, context, astNode->getStatements());
            }
            if (astNode->getNext()) {
                *output << ", ";
                PyTranslate(output, context, astNode->getNext());
            }
        } else if (astNode->getType() == "MULTIPLE_STATEMENTS") {  //most indentation happens here
            indent(output, context);
            PyTranslate(output, context, astNode->getStatements());  // Current statement
            *output << "\n";
            if (astNode->getNext()) {
                PyTranslate(output, context, astNode->getNext());  // Any further statements
            }

        } else if (astNode->getType() == "ASSIGNMENT_STATEMENT") {
            PyTranslate(output, context, astNode->getIdentifier());
            if (context.variableAssignmentState == "VARIABLE_DECLARATION") {
                // No current or next statements
                if (!astNode->getStatements() && !astNode->getNext()) {
                    *output << " = 0";
                }
            }
            if (astNode->getStatements()) {
                *output << " = ";
                PyTranslate(output, context, astNode->getStatements());
            }
            if (astNode->getNext()) {
                PyTranslate(output, context, astNode->getNext());
            }

        } else if (astNode->getType() == "IF_STATEMENT") {
            context.variableAssignmentState = "IF_STATEMENT";
            *output << "if(";
            PyTranslate(output, context, astNode->getCondition());
            *output << "):\n";

            context.scope++;
            PyTranslate(output, context, astNode->getStatements());
            context.scope--;

            if (astNode->getNext()) {
                indent(output, context);
                *output << "el";
                if (astNode->getNext()->getType() != "IF_STATEMENT") {  // If next node is not an IF
                    *output << "se:\n";
                    context.scope++;
                    PyTranslate(output, context, astNode->getNext());
                    context.scope--;
                } else {
                    PyTranslate(output, context, astNode->getNext());
                }
            }
        } else if (astNode->getType() == "WHILE_LOOP") {
			if(astNode->getVal = 1){ // its a do while loop so do one extra iteration before checking conditions
				PyTranslate(output, context, astNode->getNext());  //scope
			}
            context.variableAssignmentState = "WHILE_LOOP";
            *output << "while ";
            PyTranslate(output, context, astNode->getCondition());  //condition
            *output << ": \n";
            context.scope++;
            if (astNode->getNext()) {
                PyTranslate(output, context, astNode->getNext());  //scope
            }
            context.scope--;

        } else if (astNode->getType() == "FOR_LOOP") {
            context.variableAssignmentState = "FOR_LOOP";
            PyTranslate(output, context, astNode->getConditionOne());  //printing identifier
            *output << "\n";
            indent(output, context);
            *output << "while (";
            //cond1 points to variable_declaration which points right to assignment_statement
            //which points to the identifier
            PyTranslate(output, context, astNode->getConditionTwo());  //printing identifier
            *output << "):\n";
            //printing the MATH_OR_BITWISE_EXPRESSION (left) in assignment_statement
            context.scope++;
            PyTranslate(output, context, astNode->getNext());
            PyTranslate(output, context, astNode->getConditionThree());
            context.scope--;

        } else if (astNode->getType() == "ASSIGNMENT_EXPRESSION") {
            PyTranslate(output, context, astNode->getLeft());
            PyTranslate(output, context, astNode->getIdentifier());
            PyTranslate(output, context, astNode->getRight());

        } else if (astNode->getType() == "UNARY_EXPRESSION") {
            PyTranslate(output, context, astNode->getIdentifier());
            PyTranslate(output, context, astNode->getRight());

        } else if (astNode->getType() == "MULTIPLICATIVE_EXPRESSION" ||
                   astNode->getType() == "ADDITIVE_EXPRESSION" ||
                   astNode->getType() == "BITWISE_AND_EXPRESSION" ||
                   astNode->getType() == "BITWISE_XOR_EXPRESSION" ||
                   astNode->getType() == "BITWISE_OR_EXPRESSION" ||
                   astNode->getType() == "BOOLEAN_EXPRESSION" ||
                   astNode->getType() == "EQUALITY_EXPRESSION" ||
                   astNode->getType() == "SHIFT_EXPRESSION" ||
                   astNode->getType() == "RELATIONAL_EXPRESSION") {
            PyTranslate(output, context, astNode->getLeft());   //identifier
            *output << " " << astNode->getId() << " ";          //arithmetic operator
            PyTranslate(output, context, astNode->getRight());  //expr

        } else if (astNode->getType() == "POSTFIX_EXPRESSION") {
            PyTranslate(output, context, astNode->getLeft());  //identifier
            *output << astNode->getId();                       //operator

        } else if (astNode->getType() == "SCOPE") {
            // If not directly from either of the below states
            // if (!(context.variableAssignmentState == "FUNCTION_DEFINITION" ||
            //     context.variableAssignmentState == "FOR_LOOP" ||
            //     context.variableAssignmentState == "WHILE_LOOP" ||
            //     context.variableAssignmentState == "IF_STATEMENT")) {
            //     context.variableAssignmentState = "NESTED_SCOPE";
            // }
            if (astNode->getNext()) {  // Non-empty scope
                PyTranslate(output, context, astNode->getNext());
            } else {
                indent(output, context);
                *output << "pass\n";
            }

        } else if (astNode->getType() == "VARIABLE_DECLARATION") {
            std::string prevState = context.variableAssignmentState;
            context.variableAssignmentState = "VARIABLE_DECLARATION";
            PyTranslate(output, context, astNode->getStatements()); // Assignment statement
            if (prevState == "GLOBAL") {  // If not within a function definition
                *output << "\n";
            }

        } else if (astNode->getType() == "RETURN") {
            context.variableAssignmentState = "RETURN";
            *output << "return ";
            // Returning a value
            if (astNode->getReturnValue()) {
                PyTranslate(output, context, astNode->getReturnValue());
            }
        } else if (astNode->getType() == "BREAK") {
            *output << "break";
        } else if (astNode->getType() == "CONTINUE") {
            *output << "continue";
        } else if (astNode->getType() == "VOID") {   // Do nothing
        } else if (astNode->getType() == "CHAR") {   // Do nothing
        } else if (astNode->getType() == "SHORT") {  // Do nothing
        } else if (astNode->getType() == "INT") {    // Do nothing

        } else if (astNode->getType() == "LONG") {      // Do nothing
        } else if (astNode->getType() == "FLOAT") {     // Do nothing
        } else if (astNode->getType() == "DOUBLE") {    // Do nothing
        } else if (astNode->getType() == "SIGNED") {    // Do nothing
        } else if (astNode->getType() == "UNSIGNED") {  // Do nothing
        } else if (astNode->getType() == "ASSIGNMENT_OPERATOR" ||
                   astNode->getType() == "UNARY_OPERATOR") {
            if (astNode->getId() == "!") {
                *output << " not ";
            } else {
                *output << " " << astNode->getId() << " ";
            }
        } else if (astNode->getType() == "VARIABLE") {
            // If this variable is not a function declarator or a function argument
            if (!context.allFunctionsTranslator.count(astNode->getId()) &&
                !context.functionArgs.count(astNode->getId())) {
                if (context.scope == 0) {
                    addVarToGlobal(context, astNode->getId());  // Add all global variables at start of
                }                                               // function definition if in global scope
                addVarToScope(context, astNode->getId());       // Add to variable list of current scope
            }
            *output << astNode->getId();
        } else if (astNode->getType() == "INTEGER_CONSTANT") {
            *output << astNode->getVal();

        } else if (astNode->getType() == "FLOAT_CONSTANT") {
            *output << astNode->getFloat();

        } else if (astNode->getType() == "STRING_LITERAL") {
            *output << "\"" << astNode->getId() << "\"";

        } else {
            throw std::runtime_error("Unknown type of " + astNode->getType() + "\n");
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << "\n";
        exit(-1);
    }
}

void indent(std::ostream *output, ProgramContext &context) {
    for (int i = 0; i < context.scope; i++) {
        *output << "\t";
    }
}

void addVarToGlobal(ProgramContext &context, const std::string &id) {
    if (!context.globalVariables.count(id)) {
        context.globalVariables.insert(id);
    }
}

void addVarToScope(ProgramContext &context, const std::string &id) {
    if (!context.allVariables.count(id)) {
        context.allVariables.insert(id);
    }
}
