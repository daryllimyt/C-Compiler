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
        left_ = left;    // math or bitwise expression
        right_ = right;  // Further assignment statements
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
        return left_;  // Current statement
    }
    NodePtr getRight() const {
        return right_;  // Next statement
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
        return left_;  // Current statement
    }
    NodePtr getRight() const {
        return right_;  // Next statement
    }
};

class WhileLoop : public Node {
   protected:
    NodePtr condition_;  //condition
    NodePtr next_;       //statement

   public:
    WhileLoop(NodePtr condition, NodePtr next) {
        type_ = "WHILE_LOOP";
        condition_ = condition;
        next_ = next;
    }
    NodePtr getCondition() const {
        return condition_;  // Current statement
    }
    NodePtr getNext() const {
        return next_;  // Next statement
    }
};

class ForLoop : public Node {
   protected:
    NodePtr condition1_;  //int i = 0
    NodePtr condition2_;  //i < 3
    NodePtr condition3_;  //i++
    NodePtr next_;        //{do smth;}

   public:
    ForLoop(NodePtr cond1, NodePtr cond2, NodePtr cond3, NodePtr next) {
        type_ = "FOR_LOOP";
        condition1_ = cond1;
        condition2_ = cond2;
        condition3_ = cond3;
        next_ = next;
    }
    NodePtr getConditionOne() const {
        return condition1_;  // //int i = 0
    }
    NodePtr getConditionTwo() const {
        return condition2_;  // //i < 3
    }
    NodePtr getConditionThree() const {
        return condition3_;  // //i++
    }
    NodePtr getNext() const {
        return next_;  //{do smth;}
    }
};

class IfStatement : public Node {
   protected:
    NodePtr expression_;
    NodePtr ifStatements_;
    NodePtr elseStatements_;
    NodePtr next_;

   public:
    IfStatement(NodePtr expression, NodePtr ifStatements, NodePtr elseStatements) {
        type_ = "IF_STATEMENT";
        expression_ = expression;
        ifStatements_ = ifStatements;
        elseStatements_ = elseStatements;
    }
    NodePtr getCondition() const {
        return expression_;
    }
    NodePtr getLeft() const {
        return ifStatements_;
    }
    NodePtr getRight() const {
        return elseStatements_;
    }
};

#endif
