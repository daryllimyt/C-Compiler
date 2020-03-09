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
    std::string &getType() const
    {
        return type_;
    };


    // Tell and node to print itself to the given stream.
    virtual std::ostream &print(std::ostream &destination, std::string indent) const = 0;


    // Virtual functions for all types of nodes
    virtual NodePtr getLeft() const{ return NULL; }
    virtual NodePtr getRight() const{ return NULL; }
    virtual NodePtr getNext() const{ return NULL; }
    virtual NodePtr getPointer() const{ return NULL; }
    virtual NodePtr getIdentifier() const{ return NULL; }
    virtual NodePtr getArguments() const{ return NULL; }
    virtual NodePtr getCondition() const{ return NULL; }
    virtual NodePtr getConditionOne() const{ return NULL; }
    virtual NodePtr getConditionTwo() const{ return NULL; }
    virtual NodePtr getConditionThree() const{ return NULL; }
    virtual NodePtr getTruePath() const{ return NULL; }
    virtual NodePtr getFalsePath() const{ return NULL; }
    virtual NodePtr getReturnValue() const{ return NULL; }
    virtual NodePtr getIndex() const{ return NULL; }
    virtual NodePtr getSpecifiers() const{ return NULL; }
    virtual NodePtr getQualifiers() const{ return NULL; }
    virtual NodePtr getStatements() const{ return NULL; }
    virtual NodePtr getDeclarator() const{ return NULL; }
    virtual const std::string getId() const{}
    virtual const double getValue() const{}
    virtual const std::string getEllipsis() const{}
};

class RootNode : public Tree
{
    protected:
    NodePtr next;

    public:
    RootNode(NodePtr _next){
        type = "root";
        next = _next;
    }
    NodePtr GetNext() const{
        return next;
    }
};

class ProgramNode : public Tree
{
    protected:
    NodePtr left;
    NodePtr right;

    public:
    ProgramNode(NodePtr _left, NodePtr _right){
        type = "program";
        left = _left;
        right = _right;
    }
    NodePtr GetLeft() const{
        return left;
    }
    NodePtr GetRight() const{
        return right;
    }
};

#endif