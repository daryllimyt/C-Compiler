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
    NodePtr getLeft() const {
        return left_;
    }
    NodePtr getRight() const {
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
    NodePtr getReturnValue() const {
        return returnValue_;
    }
};

class WrappedArguments : public Node {
   protected:
    NodePtr left_;
    NodePtr right_;

   public:
    WrappedArguments(NodePtr left, NodePtr right) {
        type_ = "WRAPPED_ARGUMENTS";
        left_ = left;    
        right_ = right;  
    }
    NodePtr getLeft() const {
        return left_;
    }
    NodePtr getRight() const {
        return right_;
    }
};

class Scope : public Node {
   protected:
    NodePtr next_;

   public:
    Scope(NodePtr next) {
        type_ = "SCOPE";
        next_ = next;    
    }
    NodePtr getNext() const {
        return next_;
    }
};



#endif