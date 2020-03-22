#ifndef AST_FUNCTIONS_HPP_
#define AST_FUNCTIONS_HPP_

#include <iostream>
#include <string>

#include "ast_node.hpp"

class FunctionDefinition : public Node {
   protected:
    NodePtr typeSpecifier_;
    NodePtr identifier_;
    NodePtr args_;
    NodePtr scope_;

   public:
    FunctionDefinition(NodePtr typeSpecifier, NodePtr identifier, NodePtr args, NodePtr scope) {
        type_ = "FUNCTION_DEFINITION";
        typeSpecifier_ = typeSpecifier;
        identifier_ = identifier;
        args_ = args;
        scope_ = scope;
    }
    NodePtr getTypeSpecifier() const {
        return typeSpecifier_;  // type specifier
    }
    NodePtr getIdentifier() const {
        return identifier_;  // variable name / declarator
    }
    NodePtr getArgs() const {
        return args_;
    }
    NodePtr getScope() const {
        return scope_;
    }
};

class FunctionDeclaration : public Node {
   protected:
    NodePtr typeSpecifier_;
    NodePtr identifier_;
    NodePtr args_;

   public:
    FunctionDeclaration(NodePtr typeSpecifier, NodePtr identifier, NodePtr args) {
        type_ = "FUNCTION_DECLARATION";
        typeSpecifier_ = typeSpecifier;
        identifier_ = identifier;
        args_ = args;
    }
    NodePtr getSpecifier() const {
        return typeSpecifier_;  // type specifier
    }
    NodePtr getIdentifier() const {
        return identifier_;  // variable name
    }
    NodePtr getArgs() const {
        return args_;
    }
};

class FunctionCall : public Node {
   protected:
    NodePtr identifier_;
    NodePtr args_;

   public:
    FunctionCall(NodePtr identifier, NodePtr args) {
        type_ = "FUNCTION_CALL";
        identifier_ = identifier;
        args_ = args;
    }
    NodePtr getIdentifier() const {
        return identifier_;  // variable name
    }
    NodePtr getParameters() const {
        return args_;
    }
};

#endif
