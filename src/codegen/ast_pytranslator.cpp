#include "include/ast.hpp"

void indent(std::ostream *output, ProgramContext &context);
void addToGlobal(ProgramContext &context, std::string id);

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
            *output << ":\n";

            // Indentation
            indent(output, context);

            for (auto &it : context.globalVariables) {
                *output << "global " << it << "\n";
                indent(output, context);
            }
            PyTranslate(output, context, astNode->getArgs());
            context.scope -= 1;
            *output << "\n";
            indent(output, context);
        }
    } 
}

void indent(std::ostream *output, ProgramContext &context) {
    for (int i = 0; i < context.scope; i++) {
        *output << "\t";
    }
}

void addToGlobal(ProgramContext &context, std::string id) {
    if (!context.globalVariables.count(id)) {
        context.globalVariables.insert(id);
    }
}
