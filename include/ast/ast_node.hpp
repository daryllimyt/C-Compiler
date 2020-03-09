#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <map>
#include <vector>
#include <cmath>
#include <regex>
#include <fstream>
#include <stdexcept>


typedef const Node *NodePtr; // Pointer to Node


// Abstract Node class
class Node
{
protected:
    std::string type_;

public:
    virtual ~Node() {}

    virtual const std::string &getType() const
    {
        return type_;
    };

    // Tell and node to print itself to the given stream.
    virtual std::ostream &print(std::ostream &destination, std::string indent) const = 0;
};

#endif