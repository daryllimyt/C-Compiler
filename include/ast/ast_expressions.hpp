#ifndef AST_EXPRESSIONS_HPP_
#define AST_EXPRESSIONS_HPP_

#include <string>
#include <iostream>

#include "ast_node.hpp"

class RelationalExpression : public Node {
   protected:
    NodePtr left_;   // Target
    std::string operator_;
    NodePtr right_;  // Value

   public:
    RelationalExpression(NodePtr left, const std::string& op, NodePtr right) {
        type_ = "RELATIONAL_EXPRESSION";
        left_ = left;
        operator_ = op;
        right_ = right;
    }
    NodePtr getLeft() const {
        return left_;
    }
    const std::string getId() const {
        return operator_;
    }
    NodePtr getRight() const {
        return right_;
    }
};

class PostfixExpression : public Node {
   protected:
    NodePtr left_;
    std::string operator_;

   public:
    PostfixExpression(NodePtr left, const std::string& op) {
        type_ = "POSTFIX_EXPRESSION";
        left_ = left;
        operator_ = op;

    }
    NodePtr getLeft() const {
        return left_;
    }
    const std::string getId() const {
        return operator_;
    }
};

#endif
