#ifndef AST_CONTEXT_HPP_
#define AST_CONTEXT_HPP_

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <class T>
void printIterable(std::ostream& out, const T& iterable) {
    out << "[ ";
    for (auto& it : iterable) {
        out << it << " ";
    }
    out << "]";
}

struct VariableContext {
    // Single variable name can have different contexts in each scope
    int addressOffset;          // Address offset in memory of where the variable is located
    int scope;                  // Scope in which the variable was defined
	int value;                  // Value of the variable
    std::string typeSpecifier;  // Type specifier
    friend std::ostream& operator<<(std::ostream& out, const VariableContext& v) {
        out << "{addrOffset: " << v.addressOffset << ", scope: " << v.scope << ", type: " << v.typeSpecifier << " }";
        return out;
    }
};

struct FunctionContext {
    int scope;                  // Scope in which the variable was defined
    std::string typeSpecifier;  // Type specifier
    std::vector<std::string> args;
    void addArg(const std::string& arg) {
        args.push_back(arg);
    }
    friend std::ostream& operator<<(std::ostream& out, const FunctionContext& f) {
        out << "{scope: " << f.scope << ", type: " << f.typeSpecifier << ", args: ";
        printIterable(out, f.args);
        out << "}";
        return out;
    }
};

struct FrameContext {
    int bytes;
    int variableCount;
    // std::vector<std::string> frameVariables;
    // void addVariable(const std::string &id) {
    //     frameVariables.push_back(id);
    // }
    friend std::ostream& operator<<(std::ostream& out, const FrameContext& f) {
        out << "{bytes: " << f.bytes << ", vars: " << f.variableCount << " }";
        return out;
    }
};

/* Variable assignment states (for variable nodes)
    None: NO_ASSIGN
    Variable declaration: VARIABLE_DECLARATION
    Variable assignment to expression: VARIABLE_ASSIGNMENT
    Function declaration: FUNCTION_DECLARATION
    Function definition: FUNCTION_DEFINITION
    Array declaration (sized): ARRAY_DECLARATION
    GLOBAL
    */

class ProgramContext {
    // General
    public:
    ProgramContext(){}
    /* Contextual information for MIPS code generator */
    // Scope
    int scope = 0;

    // Frame
    int frameIndex = 0;  // Frame index of current function/scope
    std::string frameStart;
    std::string frameEnd;
    std::vector<FrameContext> frameTracker;  // Tracks requred bytes & num of vars for each frame (indexed by frameIndex)

    // Variables
    std::string identifier;
    std::string typeSpecifier;
    std::string typeQualifier;                                                       // const, volatile
    std::string variableAssignmentState = "NO_ASSIGN";
    std::unordered_map<std::string, std::vector<VariableContext>> variableBindings;  // Can be bound to different

    // Functions
    std::string returnType = "VOID";
    std::unordered_set<std::string> functionArgs;
    std::unordered_set<std::string> allFunctions;
    std::unordered_map<std::string, FunctionContext> functionBindings;

    // Registers
    int virtualRegister = 0;

    // Labels
    int labelCount = 0;
    std::string endLabel = "end";
    std::vector<std::string> functionEnds;

    // Contextual information for Python translator
    std::unordered_set<std::string> globalVariables;
    std::unordered_set<std::string> allVariables;

    friend std::ostream& operator<<(std::ostream& out, const ProgramContext& p) {
        out << "[INFO] *** Program Context ***\n";

        /* Contextual information for MIPS code generator */
        // Others
        out << "[INFO] * scope:\t" << p.scope << "\n";
        // Frame
        out << "[INFO] * frameIndex: " << p.frameIndex << "\n";
        out << "[INFO] * frameStart: " << p.frameStart << "\n";
        out << "[INFO] * frameEnd: " << p.frameEnd << "\n";
        out << "[INFO] * frameTracker: ";
        printIterable(out, p.frameTracker);  // Tracks requred space for each frame (index)
        out << "\n";

        // // Variables
        out << "[INFO] * identifier: " << p.identifier << "\n";
        out << "[INFO] * typeSpecifier: " << p.typeSpecifier << "\n";
        out << "[INFO] * typeQualifier: " << p.typeQualifier << "\n";  // const, volatile
        out << "[INFO] * variableAssignmentState: " << p.variableAssignmentState << "\n";
        out << "[INFO] * variableBindings: ";
        out << "[ ";
        for (auto& it : p.variableBindings) {
            out << "{" << it.first << "->";
            printIterable(out, it.second);
            out << "}";
        }
        out << "]\n";

        // Functions
        out << "[INFO] * functionArgs: ";
        printIterable(out, p.functionArgs);
        out << "\n";
        out << "[INFO] * allFunctions: ";
        printIterable(out, p.allFunctions);
        out << "\n";
        out << "[INFO] * functionBindings: ";
        out << "[ ";
        for (auto& it : p.functionBindings) {
            out << "{" << it.first << "->" << it.second << "} ";
        }
        out << "]\n";

        // Contextual information for Python translator
        out << "[INFO] * globalVariables: ";
        printIterable(out, p.globalVariables);
        out << "\n";
        out << "[INFO] * allVariables: ";
        printIterable(out, p.allVariables);
        out << "\n";
        return out;
    }

};
#endif
