#ifndef AST_EXPRESSIONS_HPP_
#define AST_EXPRESSIONS_HPP_

#include <string>
#include <iostream>

#include "ast_node.hpp"

class AssignmentExpression : public Node {
   protected:
    NodePtr left_;  // Target
    NodePtr op_;
    NodePtr right_;  // Value

   public:
    AssignmentExpression(NodePtr left, NodePtr op, NodePtr right) {
        type_ = "ASSIGNMENT_EXPRESSION";
        left_ = left;
        op_ = op;
        right_ = right;
    }
    NodePtr getLeft() const {
        return left_;
    }
    NodePtr getIdentifier() const {
        return op_;
    }
    NodePtr getRight() const {
        return right_;
    }
};

class UnaryExpression : public Node {
   protected:
    NodePtr op_;
    NodePtr right_;  // Value

   public:
    UnaryExpression(NodePtr op, NodePtr right) {
        type_ = "UNARY_EXPRESSION";
        op_ = op;
        right_ = right;
    }
    NodePtr getIdentifier() const {
        return op_;
    }
    NodePtr getRight() const {
        return right_;
    }
};

class RelationalExpression : public Node {
   protected:
    NodePtr left_;  // Target
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

class MultiplicativeExpression : public Node {
   protected:
    NodePtr left_;  // Target
    std::string op_;
    NodePtr right_;  // Value

   public:
    MultiplicativeExpression(NodePtr left, const std::string& op, NodePtr right) {
        type_ = "MULTIPLICATIVE_EXPRESSION";
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

class AdditiveExpression : public Node {
   protected:
    NodePtr left_;  // Target
    std::string op_;
    NodePtr right_;  // Value

   public:
    AdditiveExpression(NodePtr left, const std::string& op, NodePtr right) {
        type_ = "ADDITIVE_EXPRESSION";
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

class ShiftExpression : public Node {
   protected:
    NodePtr left_;  // Target
    std::string op_;
    NodePtr right_;  // Value

   public:
    ShiftExpression(NodePtr left, const std::string& op, NodePtr right) {
        type_ = "SHIFT_EXPRESSION";
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

class BitwiseANDExpression : public Node {
   protected:
    NodePtr left_;  // Target
    std::string op_;
    NodePtr right_;  // Value

   public:
    BitwiseANDExpression(NodePtr left, NodePtr right) {
        type_ = "BITWISE_AND_EXPRESSION";
        left_ = left;
        op_ = "&";
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

class BitwiseXORExpression : public Node {
   protected:
    NodePtr left_;  // Target
    std::string op_;
    NodePtr right_;  // Value

   public:
    BitwiseXORExpression(NodePtr left, NodePtr right) {
        type_ = "BITWISE_XOR_EXPRESSION";
        left_ = left;
        op_ = "^";
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

class BitwiseORExpression : public Node {
   protected:
    NodePtr left_;  // Target
    std::string op_;
    NodePtr right_;  // Value

   public:
    BitwiseORExpression(NodePtr left, NodePtr right) {
        type_ = "BITWISE_OR_EXPRESSION";
        left_ = left;
        op_ = "|";
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
    BooleanExpression(NodePtr left, const std::string& op, NodePtr right) {
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
    EqualityExpression(NodePtr left, const std::string& op, NodePtr right) {
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

class SizeOf : public Node {
   protected:
    NodePtr expr_;

   public:
    SizeOf(NodePtr expr) {
        type_ = "SIZE_OF";
    	expr_ = expr;
    }
    NodePtr getNext() const {
        return expr_;
    }

};

#endif
