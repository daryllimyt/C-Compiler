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
    NodePtr statements_;

public:
    FunctionDefinition(NodePtr specifiers, NodePtr identifier, NodePtr statements)
    {
        type_ = "FUNCTION_DEFINITION";
        specifiers_ = specifiers;
        identifier_ = identifier;
        statements_ = statements;
    }
    NodePtr getSpecifiers() const
    {
        return specifiers_;
    }
    NodePtr getIdentifier() const
    {
        return identifier_;
    }
    NodePtr getStatements() const
    {
        return statements_;
    }
};

class FunctionDeclaration : public Node
{
protected:
    NodePtr left_;
    NodePtr right_; // Parameter(s)

public:
    FunctionDeclaration(const std::string &specifier, NodePtr left, NodePtr right) : 
    {
        type_ = "FUNCTION_DECLARATION";
        left_ = left;
        right_ = right;
    }
    NodePtr getLeft() const
    {
        return left_;
    }
    NodePtr getRight() const
    {
        return right_;
    }
};

#endif