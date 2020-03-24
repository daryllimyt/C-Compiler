#ifndef AST_STATEMENTS_HPP_
#define AST_STATEMENTS_HPP_

#include <iostream>
#include <string>

#include "ast_node.hpp"

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
    NodePtr getStatements() const {
        return current_;
    }
    NodePtr getNext() const {
        return next_;
    }
};

class JumpStatement : public Node {
   protected:
    NodePtr returnValue_;

   public:
    JumpStatement(const std::string& type, NodePtr returnValue) {
        type_ = type;                // return, continue, break
        returnValue_ = returnValue;  // return value or NULL
    }
    NodePtr getReturnValue() const {
        return returnValue_;
    }
};

class ParenthesisWrapper : public Node {
   protected:
    NodePtr current_;

   public:
    ParenthesisWrapper(NodePtr current) {
        type_ = "PARENTHESIS_WRAPPER";
        current_ = current;
    }
    NodePtr getStatements() const {
        return current_;
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
    NodePtr getStatements() const {
        return current_;
    }
    NodePtr getNext() const {
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
    NodePtr getArgs() const {
        return current_;  // Current argument
    }
    NodePtr getNext() const {
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
    NodePtr getStatements() const {
        return current_;  // Current parameter
    }
    NodePtr getNext() const {
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
    NodePtr getStatements() const {
        return current_;  // Current argument
    }
    NodePtr getNext() const {
        return next_;  // Next arguments
    }
};

class VariableDeclaration : public Node {
   protected:
    NodePtr typeSpecifier_;
    NodePtr statement_;

   public:
    VariableDeclaration(NodePtr typeSpecifier, NodePtr statement) {
        type_ = "VARIABLE_DECLARATION";
        typeSpecifier_ = typeSpecifier;
        statement_ = statement;
    }
    NodePtr getTypeSpecifier() const {
        return typeSpecifier_;  // Type specifier
    }
    NodePtr getStatements() const {
        return statement_;  // Assignment statement
    }
};

class WhileLoop : public Node {
   protected:
    NodePtr condition_;  //condition
    NodePtr next_;       //statement
    int64_t do_condition_;

   public:
    WhileLoop(NodePtr condition, NodePtr next, const int& do_condition) {
        type_ = "WHILE_LOOP";
        condition_ = condition;
        next_ = next;
        do_condition_ = do_condition;
    }
    NodePtr getCondition() const {
        return condition_;  // Current statement
    }
    NodePtr getNext() const {
        return next_;  // Next statement
    }
    const int64_t getVal() const {
        return do_condition_;  // 0 for while 1 for do while
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
    NodePtr getStatements() const {
        return ifStatements_;
    }
    NodePtr getNext() const {
        return elseStatements_;
    }
};

#endif
