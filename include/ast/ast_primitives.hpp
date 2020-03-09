#ifndef AST_PRIMITIVES_HPP
#define AST_PRIMITIVES_HPP

#include <string>
#include <iostream>

#include "ast_node.hpp"

class Variable : public Node {
    // Normal, pointer, array
    protected:
    public:
    private:
        std::string id_;
};

class IntegerConstant : public Node {
    public:
        IntegerConstant(int64_t value) : value_(value) {
            type_ = "IntegerConstant";
        }

        int64_t getValue() const {
            return value_;
        }

        virtual std::ostream& print(std::ostream& os, std::string indent) const override {
            os << indent << type_ << " [ " << value_ << " ]";
            return os;
        }
    private:
        int64_t value_;
};

#endif