#ifndef AST_STATEMENTS_HPP_
#define AST_STATEMENTS_HPP_

#include <string>
#include <iostream>

#include "ast_node.hpp"

class AssignmentStatement : public Node {
   protected:
    NodePtr left_;   // Target
    NodePtr right_;  // Value

   public:
    AssignmentStatement(const std::string &type, NodePtr left, NodePtr right) {
        type_ = type;
        left_ = left;
        right_ = right;
    }
    NodePtr GetLeft() const {
        return left_;
    }
    NodePtr GetRight() const {
        return right_;
    }
};

class JumpStatement : public Node {
   protected:
    NodePtr returnValue_;

   public:
    JumpStatement(const std::string &type, NodePtr returnValue) {
        type_ = type;                // return, continue, break
        returnValue_ = returnValue;  // return value or NULL
    }
    NodePtr getResult() const {
        return returnValue_;
    }
};

#endif