#ifndef AST_HPP
#define AST_HPP

// Include headers in ast that contains the classes for the tree nodes.
#include "ast/ast_node.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_expressions.hpp"
#include "ast/ast_functions.hpp"
#include "ast/ast_statements.hpp"
#include "ast/ast_enums.hpp"

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <map>
#include <vector>
#include <cmath>
#include <regex>
#include <fstream>
#include <stdexcept>

extern const Node *parseAST();
extern void yyset_in(FILE* fd);

struct InterpretContext
{
    std::vector<int> parameters;
    // Stuff for both
    int scope = 0;
    std::vector<std::string> totalVars; // List of variable keys
    std::string identifier;
    std::string specifier;
    std::string qualifier;
};

int32_t Interpret(std::ostream *output, InterpretContext &context, NodePtr program);
void Compile(std::ostream *output, InterpretContext &contxt, NodePtr program);



#endif