#ifndef AST_OPERATORS_HPP_
#define AST_OPERATORS_HPP_

#include <string>
#include <iostream>

#include "ast_node.hpp"

class AssignmentOperator : public Node {
   protected:
    std::string op_;

   public:
    AssignmentOperator(const std::string& op) {
        type_ = "ASSIGNMENT_OPERATOR";
        op_ = op;
    }
    const std::string getId() const{
        return op_;
    }
};

class UnaryOperator : public Node {
   protected:
    std::string op_;

   public:
    UnaryOperator(const std::string& op) {
        type_ = "UNARY_OPERATOR";
        op_ = op;
    }
    const std::string getId() const {
        return op_;
    }
};

#endif