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

class Node;

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

    // Pure virtual print node to the given stream
    virtual std::ostream &print(std::ostream &dst, std::string indent) const = 0;

    // Virtual functions for all types of nodes
    virtual NodePtr getLeft() const { return NULL; }
    virtual NodePtr getRight() const { return NULL; }
    virtual NodePtr getNext() const { return NULL; }
    virtual NodePtr getPointer() const { return NULL; }
    virtual NodePtr getIdentifier() const { return NULL; }
    virtual NodePtr getArguments() const { return NULL; }
    virtual NodePtr getCondition() const { return NULL; }
    virtual NodePtr getConditionOne() const { return NULL; }
    virtual NodePtr getConditionTwo() const { return NULL; }
    virtual NodePtr getConditionThree() const { return NULL; }
    virtual NodePtr getTruePath() const { return NULL; }
    virtual NodePtr getFalsePath() const { return NULL; }
    virtual NodePtr getResult() const { return NULL; }
    virtual NodePtr getIndex() const { return NULL; }
    virtual NodePtr getSpecifiers() const { return NULL; }
    virtual NodePtr getQualifiers() const { return NULL; }
    virtual NodePtr getStatements() const { return NULL; }
    virtual NodePtr getDeclarator() const { return NULL; }
    virtual const std::string getId() const { return NULL; }
    virtual const int64_t getValue() const { return NULL; }
    virtual const std::string getEllipsis() const { return NULL; }
};

class RootNode : public Node
{
protected:
    NodePtr next_;

public:
    RootNode(NodePtr next)
    {
        type_ = "ROOT";
        next_ = next;
    }
    NodePtr getNext() const
    {
        return next_;
    }
};

class Frame : public Node
{
protected:
    NodePtr left_;
    NodePtr right_;

public:
    Frame(NodePtr left, NodePtr right)
    {
        type_ = "FRAME";
        left_ = left; // Pointer to previous frame
        right_ = right; // Pointer to current frame
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

struct ProgramContext
{
    // General
    std::vector<int> parameters;

    // Contextual information for MIPS code generator
    int frameIndex = 0; // Frame index of current function/scope
    int scope = 0;
    std::vector<std::string> totalVars; // List of variable keys
    std::string identifier;
    std::string specifier;
    std::string qualifier;

    // Contextual information for Python translator
};

int32_t PyTranslate(std::ostream *output, ProgramContext &context, NodePtr astNode);
void Compile(std::ostream *output, ProgramContext &contxt, NodePtr astNode);


#endif