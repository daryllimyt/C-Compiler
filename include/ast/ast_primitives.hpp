#ifndef AST_PRIMITIVES_HPP_
#define AST_PRIMITIVES_HPP_

#include <iostream>
#include <string>

#include "ast_node.hpp"



class Variable : public Node {
    // Normal, pointer, array
   private:
    std::string id_;
    std::string varType_;
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
    // const std::string get() const {
    //     return id_;
    // }
    NodePtr getStatements() const {
        return expression_;
    }
};

class IntegerConstant : public Node {
   private:
    int64_t val_;

   public:
    IntegerConstant(const int64_t &val) {
        type_ = "INTEGER_CONSTANT";
        val_ = val;
    }
    const int64_t getVal() const {
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

// class CharConstant : public Node {
//    private:
//     char val_;

//    public:
//     CharConstant(const char &val) {
//         type_ = "INTEGER_CONSTANT";
//         val_ = val;
//     }
//     const char getVal() const {
//         return val_;
//     }
// };

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
        type_ = type; // void, char, short, int ...
    }
};

#endif