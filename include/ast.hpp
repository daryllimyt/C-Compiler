#ifndef AST_HPP
#define AST_HPP

// Include headers in ast that contains the classes for the tree nodes.
#include "ast/ast_node.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_expressions.hpp"
#include "ast/ast_functions.hpp"
#include "ast/ast_statements.hpp"
#include "ast/ast_enums.hpp"
#include "ast/ast_context.hpp"

extern const Node *parseAST();
extern void yyset_in(FILE* fd);

int32_t PyTranslate(std::ostream *output, ProgramContext &context, NodePtr astNode);
void Compile(std::ostream *output, ProgramContext &contxt, NodePtr astNode);



#endif