#ifndef AST_STATEMENTS_HPP_
#define AST_STATEMENTS_HPP_

#include <iostream>
#include <string>

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
    NodePtr current_;
    NodePtr next_;

   public:
    AssignmentStatement(NodePtr identifier, NodePtr current, NodePtr next) {
        type_ = "ASSIGNMENT_STATEMENT";
        identifier_ = identifier;
        current_ = current;  // math or bitwise expression
        next_ = next;        // Further assignment statements
    }
    NodePtr getIdentifier() const {
        return identifier_;
    }
    NodePtr getLeft() const {
        return current_;
    }
    NodePtr getRight() const {
        return next_;
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
    NodePtr current_;
    NodePtr next_;

   public:
    WrappedArguments(NodePtr current, NodePtr next) {
        type_ = "WRAPPED_ARGUMENTS";
        current_ = current;
        next_ = next;
    }
    NodePtr getLeft() const {
        return current_;
    }
    NodePtr getRight() const {
        return next_;
    }
};

class WrappedParameters : public Node {
   protected:
    NodePtr current_;
    NodePtr next_;

   public:
    WrappedParameters(NodePtr current, NodePtr next) {
        type_ = "WRAPPED_PARAMETERS";
        current_ = current;
        next_ = next;
    }
    NodePtr getLeft() const {
        return current_;
    }
    NodePtr getRight() const {
        return next_;
    }
};

class MultipleArguments : public Node {
   protected:
    NodePtr current_;
    NodePtr next_;

   public:
    MultipleArguments(NodePtr current, NodePtr next) {
        type_ = "MULTIPLE_ARGUMENTS";
        current_ = current;
        next_ = next;
    }
    NodePtr getLeft() const {
        return current_;  // Current argument
    }
    NodePtr getRight() const {
        return next_;  // Next argument
    }
};

class MultipleParameters : public Node {
   protected:
    NodePtr current_;
    NodePtr next_;

   public:
    MultipleParameters(NodePtr current, NodePtr next) {
        type_ = "MULTIPLE_PARAMETERS";
        current_ = current;
        next_ = next;
    }
    NodePtr getLeft() const {
        return current_;  // Current parameter
    }
    NodePtr getRight() const {
        return next_;  // Next parameter
    }
};

class MultipleStatements : public Node {
   protected:
    NodePtr current_;
    NodePtr next_;

   public:
    MultipleStatements(NodePtr current, NodePtr next) {
        type_ = "MULTIPLE_STATEMENTS";
        current_ = current;
        next_ = next;
    }
    NodePtr getLeft() const {
        return current_;  // Current argument
    }
    NodePtr getRight() const {
        return next_;  // Next arguments
    }
};

class VariableDeclaration : public Node {
   protected:
    NodePtr typeSpecifier_;
    NodePtr declarator_;

   public:
    VariableDeclaration(NodePtr typeSpecifier, NodePtr declarator) {
        type_ = "VARIABLE_DECLARATION";
        typeSpecifier_ = typeSpecifier;
        declarator_ = declarator;
    }
    NodePtr getLeft() const {
        return typeSpecifier_;  // Current statement
    }
    NodePtr getRight() const {
        return declarator_;  // Next statement
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
