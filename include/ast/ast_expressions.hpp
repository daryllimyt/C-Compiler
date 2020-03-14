#ifndef AST_EXPRESSIONS_HPP_
#define AST_EXPRESSIONS_HPP_

#include <string>
#include <iostream>

#include "ast_node.hpp"

class RelationalExpression : public Node {
   protected:
    NodePtr left_;   // Target
    std::string op_;
    NodePtr right_;  // Value

   public:
    RelationalExpression(NodePtr left, const std::string& op, NodePtr right) {
        type_ = "RELATIONAL_EXPRESSION";
        left_ = left;
        op_ = op;
        right_ = right;
    }
    NodePtr getLeft() const {
        return left_;
    }
    const std::string getId() const {
        return op_;
    }
    NodePtr getRight() const {
        return right_;
    }
};

class ArithmeticExpression : public Node {
   protected:
    NodePtr left_;   // Target
    std::string op_;
    NodePtr right_;  // Value

   public:
    ArithmeticExpression(NodePtr left, const std::string& op, NodePtr right) {
        type_ = "ARITHMETIC_EXPRESSION";
        left_ = left;
        op_ = op;
        right_ = right;
    }
    NodePtr getLeft() const {
        return left_;
    }
    const std::string getId() const {
        return op_;
    }
    NodePtr getRight() const {
        return right_;
    }
};

class BooleanExpression : public Node {
   protected:
    NodePtr left_;
    std::string op_;
    NodePtr right_;  

   public:
    BooleanExpression(NodePtr left, const std::string &op, NodePtr right) {
        type_ = "BOOLEAN_EXPRESSION";
        left_ = left;
        op_ = op;
        right_ = right;
    }
    NodePtr getLeft() const {
        return left_;
    }
    const std::string getId() const {
        return op_;
    }
    NodePtr getRight() const {
        return right_;
    }
};

class EqualityExpression : public Node {
   protected:
    NodePtr left_;
    std::string op_;
    NodePtr right_;  

   public:
    EqualityExpression(NodePtr left, const std::string &op, NodePtr right) {
        type_ = "EQUALITY_EXPRESSION";
        left_ = left;
        op_ = op;
        right_ = right;
    }
    NodePtr getLeft() const {
        return left_;
    }
    const std::string getId() const {
        return op_;
    }
    NodePtr getRight() const {
        return right_;
    }
};

class PostfixExpression : public Node {
   protected:
    NodePtr left_;
    std::string op_;

   public:
    PostfixExpression(NodePtr left, const std::string& op) {
        type_ = "POSTFIX_EXPRESSION";
        left_ = left;
        op_ = op;

    }
    NodePtr getLeft() const {
        return left_;
    }
    const std::string getId() const {
        return op_;
    }
};

#endif
