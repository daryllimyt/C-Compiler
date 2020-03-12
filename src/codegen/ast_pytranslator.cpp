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
            context.scope += 1;
            *output << "def ";
            PyTranslate(output, context, astNode->getIdentifier());
            PyTranslate(output, context, astNode->getArgs());
            *output << ":\n";
            indent(output, context);

            for (auto &it : context.globalVariables) {
                *output << "global " << it << "\n";
                indent(output, context);
            }
            PyTranslate(output, context, astNode->getScope()); // Scope of the function
            context.scope -= 1;
            *output << "\n";
            indent(output, context);
        }
    }  else if (astNode->getType() == "WRAPPED_ARGUMENTS") {
        *output << "(";
        if (astNode->getLeft())
        {
            PyTranslate(output, context, astNode->getLeft());
        }
        if (astNode->getRight())
        {
            PyTranslate(output, context, astNode->getRight());
        }
        *output << ")";
    } else if (astNode->getType() == "MULTIPLE_STATEMENTS") {
        PyTranslate(output, context, astNode->getLeft());
        if(astNode->getRight()){
            PyTranslate(output, context, astNode->getRight());
        }
        else{
            *output<<"pass";
        }
    } else if (astNode->getType() == "return") {
        *output << "return ";
        // Returning a value
        if (astNode->getReturnValue()) {
            PyTranslate(output, context, astNode->getReturnValue());
        }
        *output << "\n";
        indent(output, context);
    } else if (astNode->getType() == "VARIABLE") {
        *output << astNode->getId();  // Write variable name to output
        if (context.scope == 0) {
            addVarToGlobal(context, astNode->getId()); // Add all global variables at start of 
        }                                           // function definition if in global scope
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