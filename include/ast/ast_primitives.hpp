#ifndef AST_PRIMITIVES_HPP_
#define AST_PRIMITIVES_HPP_

#include <iostream>
#include <string>

#include "ast_node.hpp"

class Variable : public Node {
   private:
    std::string id_;
    std::string varType_;  // Normal, point64_ter, array
    NodePtr expression_;

   public:
    Variable(const std::string &id, const std::string &varType, NodePtr expression) {
        type_ = "VARIABLE";
        id_ = id;
        varType_ = varType;
        expression_ = expression;
    }
    const std::string getId() const {
        return id_;
    }
    const std::string getVarType() const {
        return varType_;
    }
    NodePtr getStatements() const {
        return expression_;
    }
};

class IntegerConstant : public Node {
   private:
    int val_;

   public:
    IntegerConstant(const int &val) {
        type_ = "INTEGER_CONSTANT";
        val_ = val;
    }
    const int getVal() const {
        return val_;
    }
};

class CharConstant : public Node {
   private:
    int val_;

   public:
    CharConstant(const std::string &val) {
        type_ = "CHAR_CONSTANT";
        val_ = std::atoi(&val[0]);
    }
    const int getVal() const {
        return val_;
    }
};

class FloatConstant : public Node {
   private:
    double val_;

   public:
    FloatConstant(const double &val) {
        type_ = "FLOAT_CONSTANT";
        val_ = val;
    }
    const double getFloat() const {
        return val_;
    }
};

class CharConstant : public Node {
   private:
    int val_;

   public:
    CharConstant(std::string val) {
        type_ = "CHAR_CONSTANT";
        std::string temp = val.substr(1,1);
        char temp2[1];
        strcpy(temp2, temp.c_str());
        val_ = temp2[0];
    }
    const int getVal() const {
        return val_;
    }
};

class StringLiteral : public Node {
   private:
    std::string str_;

   public:
    StringLiteral(std::string str) {
        type_ = "STRING_LITERAL";
        str_ = str;
    }
    const std::string getId() const {
        return str_;
    }
};

class TypeSpecifier : public Node {
   public:
    TypeSpecifier(const std::string &type) {
        type_ = type;  // void, char, short, int64_t ...
    }
};

class CustomType : public Node {
   protected:
    std::string id_;

   public:
    CustomType(const std::string &id) {
        type_ = "CUSTOM_TYPE";
        id_ = id;
    }

    const std::string getId() const {
        return id_;
    }
};

class TypeDef : public Node {
   protected:
    std::string id_;
    NodePtr parent_;

   public:
    TypeDef(const std::string &id, NodePtr parent) {
        type_ = "TYPE_DEF";
        id_ = id;
        parent_ = parent;
    }

    const std::string getId() const {
        return id_;
    }

    NodePtr getTypeSpecifier() const {
        return parent_;
    }
};

class Enumeration : public Node {
   protected:
    std::string id_;
    NodePtr typeSpecifier_;
    NodePtr statements_;

   public:
    Enumeration(std::string id, NodePtr typeSpecifier, NodePtr statements) {
        type_ = "ENUMERATION";
        id_ = id;
        typeSpecifier_ = typeSpecifier;
        statements_ = statements;
    }
    const std::string getId() const {
        return id_;
    }
    NodePtr getTypeSpecifier() {
        return typeSpecifier_;
    }
    NodePtr getStatements() const {
        return statements_;
    }
};

class MultipleEnumerators : public Node {
   protected:
    NodePtr statement_;
    NodePtr next_;

   public:
    MultipleEnumerators(NodePtr statement, NodePtr next) {
        type_ = "MULTIPLE_ENUMERATORS";
        statement_ = statement;
        next_ = next;
    }
    NodePtr getStatements() const {
        return statement_;
    }
    NodePtr getNext() const {
        return next_;
    }
};

class SingleEnumerator : public Node {
   protected:
    std::string id_;
    NodePtr expr_;

   public:
    SingleEnumerator(std::string id, NodePtr expr) {
        type_ = "SINGLE_ENUMERATOR";
        id_ = id;
        expr_ = expr;
    }
    const std::string getId() const {
        return id_;
    }
    NodePtr getStatements() const {
        return expr_;
    }
};

class StructDefinition : public Node {
   protected:
    std::string id_;
    NodePtr statements_;

   public:
    StructDefinition(const std::string& id, NodePtr statements) {
        type_ = "STRUCT_DEFINITION";
        id_ = id;
        statements_ = statements;
    }
    const std::string getId() const {
        return id_;
    }
    NodePtr getStatements() const {
        return statements_;
    }
};

class StructDeclaration: public Node {
   protected:
    std::string id_;
    NodePtr typeSpecifier_;

   public:
    StructDeclaration(NodePtr typeSpecifier, const std::string& id) {
        type_ = "STRUCT_DECLARATION";
        id_ = id;
        typeSpecifier_ = typeSpecifier;
    }
    const std::string getId() const {
        return id_;
    }
    NodePtr getTypeSpecifier() const {
        return typeSpecifier_;
    }
};

class MultipleAttributes : public Node {
   protected:
    NodePtr statements_;
    NodePtr next_;

   public:
    MultipleAttributes(NodePtr statements, NodePtr next) {
        type_ = "MULTIPLE_ATTRIBUTES";
        statements_ = statements;
        next_ = next;
    }
    NodePtr getStatements() const {
        return statements_;
    }
    NodePtr getNext() const {
        return next_;
    }
};

class SingleAttribute : public Node {
   protected:
    NodePtr typeSpec_;
    std::string id_;

   public:
    SingleAttribute(NodePtr typeSpec, const std::string &id) {
        type_ = "SINGLE_ATTRIBUTE";
        typeSpec_ = typeSpec;
        id_ = id;
    }
    NodePtr getTypeSpecifier() const {
        return typeSpec_;
    }
    const std::string getId() const {
        return id_;
    }
};

class StructAttribute : public Node {
   protected:
    std::string structName_;
    std::string attribute_;

   public:
    StructAttribute(const std::string &structName, const std::string &attribute) {
        type_ = "STRUCT_ATTRIBUTE";
        structName_ = structName;
        attribute_ = attribute;
    }
    const std::string getAttribute() const { // swapped these for overloads
        return attribute_;
    }
    const std::string getId() const {
        return structName_;
    }
};



#endif
