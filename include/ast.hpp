#ifndef AST_HPP_
#define AST_HPP_

// Include headers in ast that contains the classes for the tree nodes.
#include "ast/ast_node.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_expressions.hpp"
#include "ast/ast_functions.hpp"
#include "ast/ast_statements.hpp"
#include "ast/ast_enums.hpp"
#include "ast/ast_context.hpp"
#include "util.hpp"

#include <exception>

extern const Node *parseAST();
extern void yyset_in(FILE *fd);

template <class T>
void printIterable(const T &iterable) {
    std::cerr << "[ ";
    for (auto &it : iterable) {
        std::cerr << it << " ";
    }
    std::cerr << "]\n";
}

int32_t PyTranslate(std::ostream *output, ProgramContext &context, NodePtr astNode);
void Compile(std::ostream *output, ProgramContext &contxt, NodePtr astNode);
// void printContext(ProgramContext context) {
//     std::cerr << "Info: *** Program Context ***\n";
//     std::cerr << "Info: * parameters:\t";
//     printIterable(context.parameters);

//     /* Contextual information for MIPS code generator */
//     // Frame

//     std::cerr << "Info: * frameIndex:\t" << context.frameIndex << "\n";
//     std::cerr << "Info: * frameStart:\t" << context.frameStart << "\n";
//     std::cerr << "Info: * frameEnd:\t" << context.frameEnd << "\n";
//     std::cerr << "Info: * frameSizes:\t";
//     printIterable(context.frameSizes);  // Tracks requred space for each frame (index)
//     std::cerr << "Info: * variableCount:\t";
//     printIterable(context.variableCount);  // Tracks # of vars in each frame (index)

//     // // Variables
//     std::cerr << "Info: * identifier:\t" << context.identifier << "\n";
//     std::cerr << "Info: * typeSpecifier:\t" << context.typeSpecifier << "\n";
//     std::cerr << "Info: * typeQualifier:\t" << context.typeQualifier << "\n";  // const, volatile
//     std::cerr << "Info: * variableAssignmentState:\t" << context.variableAssignmentState << "\n";

//     // Contextual information for Python translator
//     std::cerr << "Info: * globalVariables:\t";
//     printIterable(context.globalVariables);
//     std::cerr << "Info: * scopeVariables:\t";
//     printIterable(context.scopeVariables);

//     // Others
//     std::cerr << "Info: * identifier:\t" << context.scope << "\n";
// }

#endif