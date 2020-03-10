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

    // Not sure if this needs to be virtual
    const std::string &getType() const
    {
        return type_;
    };

    // Print node to the given stream
    virtual std::ostream &print(std::ostream &dest, std::string indent) const = 0;

    // Virtual functions for all types of nodes
    virtual NodePtr getLeft() const {}
    virtual NodePtr getRight() const {}
    virtual NodePtr getNext() const {}
    virtual NodePtr getPointer() const {}
    virtual NodePtr getIdentifier() const {}
    virtual NodePtr getArguments() const {}
    virtual NodePtr getCondition() const {}
    virtual NodePtr getConditionOne() const {}
    virtual NodePtr getConditionTwo() const {}
    virtual NodePtr getConditionThree() const {}
    virtual NodePtr getTruePath() const {}
    virtual NodePtr getFalsePath() const {}
    virtual NodePtr getResult() const {} // Used to be getReturnValue
    virtual NodePtr getIndex() const {}
    virtual NodePtr getSpecifiers() const {}
    virtual NodePtr getQualifiers() const {}
    virtual NodePtr getStatements() const {}
    virtual NodePtr getDeclarator() const {}
    virtual const std::string getId() const {}
    virtual const double getValue() const {}
    virtual const std::string getEllipsis() const {}
};

class RootNode : public Node
{
protected:
    NodePtr next_;

public:
    RootNode(NodePtr next)
    {
        type_ = "root";
        next_ = next;
    }
    NodePtr getNext() const
    {
        return next_;
    }
};

class ProgramNode : public Node
{
protected:
    NodePtr left_;
    NodePtr right_;

public:
    ProgramNode(NodePtr left, NodePtr right)
    {
        type_ = "program";
        left_ = left;
        right_ = right;
    }
    NodePtr getLeft() const
    {
        return left_;
    }
    NodePtr getRight() const
    {
        return right_;
    }
};

#endif