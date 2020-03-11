#ifndef AST_FUNCTIONS_HPP
#define AST_FUNCTIONS_HPP

#include <string>
#include <iostream>

#include "ast_node.hpp"

class FunctionDefinition : public Node
{
protected:
    NodePtr specifiers_;
    NodePtr identifier_;
    NodePtr args_;
    NodePtr scope_;

public:
    FunctionDefinition(NodePtr specifiers, NodePtr identifier, NodePtr args, NodePtr scope)
    {
        type_ = "FUNCTION_DEFINITION";
        specifiers_ = specifiers;
        identifier_ = identifier;
        args_ = args;
        statements_ = statements;
    }
    NodePtr getSpecifier() const
    {
        return specifiers_; // type specifiers
    }
    NodePtr getIdentifier() const
    {
        return identifier_; // variable name
    }
    NodePtr getArgs() const
    {
        return args_;
    }
    NodePtr getScope() const
    {
        return scope_;
    }
};

class FunctionDeclaration : public Node
{
protected:
    NodePtr specifiers_;
    NodePtr left_;
    NodePtr right_; // Parameter(s)

public:
    FunctionDeclaration(const std::string &specifiers, NodePtr left, NodePtr right) : 
    {
        type_ = "FUNCTION_DECLARATION";
        specifiers_ = specifiers;
        left_ = left;
        right_ = right;
    }
    NodePtr getSpecifier() const
    {
        return specifiers_; // type specifiers
    }
    NodePtr getLeft() const
    {
        return left_; // declarator
    }
    NodePtr getRight() const
    {
        return right_; // arguments
    }
};

#endif