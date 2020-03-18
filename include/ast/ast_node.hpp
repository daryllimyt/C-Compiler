#ifndef AST_NODE_HPP_
#define AST_NODE_HPP_

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
#include <unordered_set>

class Node;

typedef const Node *NodePtr;  // Pointer to Node

// Abstract Node class
class Node {
   protected:
    std::string type_;

   public:
    virtual ~Node() {}

    // Not sure if this needs to be virtual
    const std::string &getType() const {
        return type_;
    };

    // // Pure virtual print node to the given stream
    // virtual std::ostream &print(std::ostream &dst, std::string indent) const = 0;

    // Virtual functions for all types of nodes
    virtual NodePtr getLeft() const { return NULL; }
    virtual NodePtr getRight() const { return NULL; }
    virtual NodePtr getNext() const { return NULL; }
    virtual NodePtr getPointer() const { return NULL; }
    virtual NodePtr getIdentifier() const { return NULL; }
    virtual NodePtr getArgs() const { return NULL; }
    virtual NodePtr getCondition() const { return NULL; }
    virtual NodePtr getConditionOne() const { return NULL; }
    virtual NodePtr getConditionTwo() const { return NULL; }
    virtual NodePtr getConditionThree() const { return NULL; }
    virtual NodePtr getTruePath() const { return NULL; }
    virtual NodePtr getFalsePath() const { return NULL; }
    virtual NodePtr getReturnValue() const { return NULL; }
    virtual NodePtr getIndex() const { return NULL; }
    virtual NodePtr getTypeSpecifier() const { return NULL; }
    virtual NodePtr getQualifiers() const { return NULL; }
    virtual NodePtr getStatements() const { return NULL; }
    virtual NodePtr getDeclarator() const { return NULL; }
    virtual NodePtr getScope() const { return NULL; }
    virtual const std::string getId() const { return NULL; }
    virtual const int64_t getVal() const { return NULL; }
    virtual const double getFloat() const { return NULL; }
    virtual const std::string getEllipsis() const { return NULL; }
};

class RootNode : public Node {
   protected:
    NodePtr next_;

   public:
    RootNode(NodePtr next) {
        type_ = "ROOT";
        next_ = next;
    }
    NodePtr getNext() const {
        return next_;
    }
};

class Frame : public Node {
   protected:
    NodePtr left_;
    NodePtr right_;

   public:
    Frame(NodePtr left, NodePtr right) {
        type_ = "FRAME";
        left_ = left;    // Pointer to previous frame
        right_ = right;  // Pointer to current frame
    }
    NodePtr getLeft() const {
        return left_;
    }
    NodePtr getRight() const {
        return right_;
    }
};

#endif