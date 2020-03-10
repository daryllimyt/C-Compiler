#ifndef AST_STATEMENTS_HPP
#define AST_STATEMENTS_HPP

#include <string>
#include <iostream>

#include "ast_node.hpp"

class JumpStatement : public Node
{
protected:
    NodePtr res_;

public:
    JumpNode(const std::string &type, NodePtr res)
    {
        type_ = type;
        res_ = res;
    }
    NodePtr getResult() const
    {
        return res_;
    }
};

#endif