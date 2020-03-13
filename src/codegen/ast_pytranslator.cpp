#include "../../include/ast.hpp"

void indent(std::ostream *output, ProgramContext &context);
void addVarToGlobal(ProgramContext &context, const std::string &id);
void addVarToScope(ProgramContext &context, const std::string &id);

int32_t PyTranslate(std::ostream *output, ProgramContext &context, NodePtr astNode) {
    if (astNode == NULL) {
        throw std::runtime_error("Unhandled NULL-type ast node \n");
    } else if (astNode->getType() == "ROOT") {
        PyTranslate(output, context, astNode->getNext());
    } else if (astNode->getType() == "FRAME") {
        PyTranslate(output, context, astNode->getLeft());
        PyTranslate(output, context, astNode->getRight());
    } else if (astNode->getType() == "FUNCTION_DECLARATION") {
        // Do nothing, function declarations not supported in Python
    } else if (astNode->getType() == "FUNCTION_DEFINITION") {
        // Function has arguments
        if (astNode->getArgs()) {
            *output << "def ";
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
    } else if (astNode->getType() == "WRAPPED_ARGUMENTS") {
        *output << "(";
        if (astNode->getLeft()) {
            PyTranslate(output, context, astNode->getLeft());
        }
        if (astNode->getRight()) {
            PyTranslate(output, context, astNode->getRight());
        }
        *output << ")";
    } else if (astNode->getType() == "MULTIPLE_STATEMENTS") {  //most indentation happens here
        indent(output, context);
        PyTranslate(output, context, astNode->getLeft());  // Current statement
        *output << "\n";
        if (astNode->getRight()) {
            PyTranslate(output, context, astNode->getRight());  // Any further statements
        }
        // else{
        //     *output<<"pass";
        // }
    } else if (astNode->getType() == "ASSIGNMENT_STATEMENT") {
        PyTranslate(output, context, astNode->getIdentifier());
        if (astNode->getLeft()) {
            *output << " = ";
            PyTranslate(output, context, astNode->getLeft());
        }
        if (astNode->getRight()) {
            PyTranslate(output, context, astNode->getRight());
        }

    } else if (astNode->getType() == "IF_STATEMENT") {
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

    } else if (astNode->getType() == "WHILE_STATEMENT") {
        *output << "while ";
        PyTranslate(output, context, astNode->getCondition());  //condition
        *output << ": \n";
        context.scope++;
        if (astNode->getNext()) {
            PyTranslate(output, context, astNode->getNext());  //scope
        }
        *output << "\n";
        context.scope--;
    } else if (astNode->getType() == "FOR_STATEMENT") {
        PyTranslate(output, context, astNode->getConditionOne());  //printing identifier
        *output << "while(";
        //cond1 points to variable_declaration which points right to assignment_statement
        //which points to the identifier
        PyTranslate(output, context, astNode->getConditionTwo());  //printing identifier
        *output << " )\n";
        //printing the MATH_OR_BITWISE_EXPRESSION (left) in assignment_statement
        context.scope++;
        PyTranslate(output, context, astNode->getNext());
        PyTranslate(output, context, astNode->getConditionThree());
        context.scope--;
        *output << "\n";

    } else if (astNode->getType() == "SCOPE") { // Redundant?
        if (astNode->getNext()) {
            PyTranslate(output, context, astNode->getNext());
        }
    } else if (astNode->getType() == "VARIABLE_DECLARATION") {
        PyTranslate(output, context, astNode->getRight());
    } else if (astNode->getType() == "return") {
        *output << "return ";
        // Returning a value
        if (astNode->getReturnValue()) {
            PyTranslate(output, context, astNode->getReturnValue());
        }
    } else if (astNode->getType() == "void") {      // Do nothing
    } else if (astNode->getType() == "char") {      // Do nothing
    } else if (astNode->getType() == "short") {     // Do nothing
    } else if (astNode->getType() == "int") {       // Do nothing
    } else if (astNode->getType() == "long") {      // Do nothing
    } else if (astNode->getType() == "float") {     // Do nothing
    } else if (astNode->getType() == "double") {    // Do nothing
    } else if (astNode->getType() == "signed") {    // Do nothing
    } else if (astNode->getType() == "unsigned") {  // Do nothing
    } else if (astNode->getType() == "VARIABLE") {
        *output << astNode->getId();  // Write variable name to output
        // if (context.scope == 0) {
        //     addVarToGlobal(context, astNode->getId());  // Add all global variables at start of
        // }                                               // function definition if in global scope
        addVarToScope(context, astNode->getId());  // Add to variable list of current scope
    } else if (astNode->getType() == "INTEGER_CONSTANT") {
        *output << astNode->getVal();
    } else if (astNode->getType() == "STRING_LITERAL") {
        *output << "\"" << astNode->getId() << "\"";
    } else {
        std::cerr << "Error: Unknown type of " << astNode->getType() << "\n";
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
    if (!context.scopeVariables.count(id)) {
        context.scopeVariables.insert(id);
    }
}
