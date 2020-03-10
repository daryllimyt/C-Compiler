#ifndef AST_PRIMITIVES_HPP
#define AST_PRIMITIVES_HPP

#include <string>
#include <iostream>

#include "ast_node.hpp"

class Variable : public Node
{
    // Normal, pointer, array
private:
    std::string id_;

public:
    Variable(const std::string &id)
    {
        type_ = "variable";
        id_ = id;
    }
    const std::string getId() const
    {
        return id_;
    }
};

class IntegerConstant : public Node
{
private:
    int64_t val_;

public:
    IntegerConstant(int64_t val)
    {
        type_ = "integer constant"; 
        val_ = val;
    }
    const int64_t getVal() const
    {
        return val_;
    }
};

#endif