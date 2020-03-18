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
                if (!context.allFunctions.count(astNode->getIdentifier()->getId())) {  // Record function name in context
                    context.allFunctions.insert(astNode->getIdentifier()->getId());
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
            PyTranslate(output, context, astNode->getArgs());

        } else if (astNode->getType() == "WRAPPED_PARAMETERS") {
            *output << "(";
            if (astNode->getLeft()) {
                PyTranslate(output, context, astNode->getLeft());
            }
            if (astNode->getRight()) {
                PyTranslate(output, context, astNode->getRight());
            }
            *output << ")";
        } else if (astNode->getType() == "WRAPPED_ARGUMENTS") {
            *output << "(";
            if (astNode->getLeft()) {
                PyTranslate(output, context, astNode->getLeft());
            }
            if (astNode->getRight()) {
                PyTranslate(output, context, astNode->getRight());
            }
            *output << ")";

        } else if (astNode->getType() == "MULTIPLE_ARGUMENTS") {
            if (astNode->getLeft()) {
                if (!context.functionArgs.count(astNode->getLeft()->getRight()->getId())) {  // Record function arg in context
                    context.functionArgs.insert(astNode->getLeft()->getRight()->getId());
                }
                PyTranslate(output, context, astNode->getLeft());
            }
            if (astNode->getRight()) {
                *output << ", ";
                PyTranslate(output, context, astNode->getRight());
            }
        } else if (astNode->getType() == "MULTIPLE_PARAMETERS") {
            if (astNode->getLeft()) {
                PyTranslate(output, context, astNode->getLeft());
            }
            if (astNode->getRight()) {
                *output << ", ";
                PyTranslate(output, context, astNode->getRight());
            }
        } else if (astNode->getType() == "MULTIPLE_STATEMENTS") {  //most indentation happens here
            indent(output, context);
            PyTranslate(output, context, astNode->getLeft());  // Current statement
            *output << "\n";
            if (astNode->getRight()) {
                PyTranslate(output, context, astNode->getRight());  // Any further statements
            }

        } else if (astNode->getType() == "ASSIGNMENT_STATEMENT") {
            PyTranslate(output, context, astNode->getIdentifier());
            if (context.variableAssignmentState == "VARIABLE_DECLARATION") {
                // context.variableAssignmentState = "VARIABLE_ASSIGNMENT";
                if (!astNode->getLeft() && !astNode->getRight()) {
                    *output << " = 0";
                }
            }
            if (astNode->getLeft()) {
                *output << " = ";
                PyTranslate(output, context, astNode->getLeft());
            }
            if (astNode->getRight()) {
                PyTranslate(output, context, astNode->getRight());
            }

        } else if (astNode->getType() == "IF_STATEMENT") {
            context.variableAssignmentState = "IF_STATEMENT";

            *output << "if(";
            PyTranslate(output, context, astNode->getCondition());
            *output << "):\n";
            context.scope++;
            PyTranslate(output, context, astNode->getLeft());
            context.scope--;
            if (astNode->getRight()) {
                indent(output, context);
                *output << "else:\n";
                context.scope++;
                PyTranslate(output, context, astNode->getRight());
                context.scope--;
            }

        } else if (astNode->getType() == "WHILE_LOOP") {
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
            if (astNode->getNext()) {
                PyTranslate(output, context, astNode->getNext());
            } else {
                indent(output, context);
                *output << "pass\n";
            }

        } else if (astNode->getType() == "VARIABLE_DECLARATION") {
            std::string prevState = context.variableAssignmentState;
            context.variableAssignmentState = "VARIABLE_DECLARATION";
            PyTranslate(output, context, astNode->getRight());
            if (prevState == "GLOBAL") {  // If not within a function definition
                *output << "\n";
            }

        } else if (astNode->getType() == "return") {
            context.variableAssignmentState = "RETURN";
            *output << "return ";
            // Returning a value
            if (astNode->getReturnValue()) {
                PyTranslate(output, context, astNode->getReturnValue());
            }
        } else if (astNode->getType() == "break") {
            *output << "break";
        } else if (astNode->getType() == "continue") {
            *output << "continue";
        } else if (astNode->getType() == "void") {   // Do nothing
        } else if (astNode->getType() == "char") {   // Do nothing
        } else if (astNode->getType() == "short") {  // Do nothing
        } else if (astNode->getType() == "int") {    // Do nothing

        } else if (astNode->getType() == "long") {      // Do nothing
        } else if (astNode->getType() == "float") {     // Do nothing
        } else if (astNode->getType() == "double") {    // Do nothing
        } else if (astNode->getType() == "signed") {    // Do nothing
        } else if (astNode->getType() == "unsigned") {  // Do nothing
        } else if (astNode->getType() == "ASSIGNMENT_OPERATOR" ||
                   astNode->getType() == "UNARY_OPERATOR") {
            *output << " " << astNode->getId() << " ";
        } else if (astNode->getType() == "VARIABLE") {
            // If this variable is not a function declarator or a function argument
            if (!context.allFunctions.count(astNode->getId()) &&
                !context.functionArgs.count(astNode->getId())) {
                if (context.scope == 0) {
                    addVarToGlobal(context, astNode->getId());  // Add all global variables at start of
                }                                               // function definition if in global scope
                addVarToScope(context, astNode->getId());       // Add to variable list of current scope
            }

            // If this variable is not a global variable or inside a scioe
            *output << astNode->getId();
            // if (!context.globalVariables.count(astNode->getId()) || context.scope > 0) {

            // } else {
            //     *output << astNode->getId() << " = 0\n";  // globalVar=0
            // }
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
        return -1;
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
