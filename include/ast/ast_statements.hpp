#ifndef AST_STATEMENTS_HPP_
#define AST_STATEMENTS_HPP_

#include <string>
#include <iostream>

#include "ast_node.hpp"

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

class AssignmentStatement : public Node {
   protected:
    NodePtr identifier_;
    NodePtr left_;
    NodePtr right_;

   public:
    AssignmentStatement(NodePtr identifier, NodePtr left, NodePtr right) {
        type_ = "ASSIGNMENT_STATEMENT";
        identifier_ = identifier;
        left_ = left; // math or bitwise expression
        right_ = right; // Further assignment statements
    }
    NodePtr getIdentifier() const {
        return identifier_;
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

class MultipleStatements : public Node {
   protected:
    NodePtr left_;
    NodePtr right_;

   public:
    MultipleStatements(NodePtr left, NodePtr right) {
        type_ = "MULTIPLE_STATEMENTS";
        left_ = left;
        right_ = right;
    }
    NodePtr getLeft() const {
        return left_; // Current statement
    }
    NodePtr getRight() const {
        return right_; // Next statement
    }
};

class VariableDeclaration : public Node {
   protected:
    NodePtr left_;
    NodePtr right_;

   public:
    VariableDeclaration(NodePtr left, NodePtr right) {
        type_ = "VARIABLE_DECLARATION";
        left_ = left;
        right_ = right;
    }
    NodePtr getLeft() const {
        return left_; // Current statement
    }
    NodePtr getRight() const {
        return right_; // Next statement
    }
};

class WhileStatement : public Node {
   protected:
    NodePtr condition_; //condition
    NodePtr scope_; //statement

   public:
    WhileStatement(NodePtr condition, NodePtr scope) {
        type_ = "WHILE_STATEMENT";
        condition_ = condition;
        scope_ = scope;
    }
    NodePtr getCondition() const {
        return condition_; 
    }
    NodePtr getScope() const {
        return scope_; 
    }
};
class IfStatement : public Node {
   protected:
    NodePtr condition_; //condition
    NodePtr scope_; //statement

   public:
    IfStatement(NodePtr condition, NodePtr scope) {
        type_ = "IF_STATEMENT";
        condition_ = condition;
        scope_ = scope;
    }
    NodePtr getCondition() const {
        return condition_; 
    }
    NodePtr getScope() const {
        return scope_; // Next statement
    }
};

#endif
