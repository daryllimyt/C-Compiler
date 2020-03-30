#ifndef AST_CONTEXT_HPP_
#define AST_CONTEXT_HPP_

#include <iostream>
#include <map>
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

template <typename T>
std::pair<bool, int> findInVector(const std::vector<T>& vecOfElements, const T& element) {
    std::pair<bool, int> result;

    // Find given element in vector
    auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);

    if (it != vecOfElements.end()) {
        result.second = distance(vecOfElements.begin(), it);
        result.first = true;
    } else {
        result.first = false;
        result.second = -1;
    }

    return result;
}

struct VariableContext {
    // Single variable name can have different contexts in each scope
    int addressOffset;  // Address offset in memory of where the variable is located relative to $fp
    int scope;          // Scope in which the variable was defined
    int frame;          // Frame in which variable was defined
    int intValue = 0;
    int size;  // Size of the variable, default is 8 for regular variables, arrays 8*arraysize
    std::string varType;
    std::string typeSpecifier;  // Type specifier
    friend std::ostream& operator<<(std::ostream& out, const VariableContext& v) {
        out << "{varType: " << v.varType << ", size: " << v.size << ", addrOffset: " << v.addressOffset << ", scope: "
            << v.scope << ", frame: " << v.frame << ", typeSpec: " << v.typeSpecifier << ", intValue: " << v.intValue << " }";
        return out;
    }
};

struct EnumContext {
	int frame;
	int scope;
	std::string typeSpecifier;
	std::vector<std::string> elements;
	int val;

}

struct FunctionContext {
    int frame;              // Frame associated to function
    int scope;                  // Scope in which the function was defined
    std::string typeSpecifier;  // Type specifier
    std::vector<std::string> args;
    void addArg(const std::string& arg) {
        args.push_back(arg);
    }
    friend std::ostream& operator<<(std::ostream& out, const FunctionContext& f) {
        out << "{frame: " << f.frame << ", scope: " << f.scope << ", type: " << f.typeSpecifier << ", args: ";
        printIterable(out, f.args);
        out << "}";
        return out;
    }
};

struct FrameContext {
    int totalBytes;
    int variableBytes;
    friend std::ostream& operator<<(std::ostream& out, const FrameContext& f) {
        out << "{totalBytes: " << f.totalBytes << ", varBytes: " << f.variableBytes << " }";
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

struct ProgramContext {
    // General

    /* Contextual information for MIPS code generator */
    // Scope
    int scope = 0;

    // Frame
    int frameIndex = 0;  // Frame index of current function/scope
    std::string frameStart;
    std::string frameEnd;
    std::vector<FrameContext> frameTracker;  // Tracks requred totalBytes & num of vars for ecah frame (global = 0, current = 1)

    // Variables
    std::string identifier;
    std::string typeSpecifier;
    std::string typeQualifier;  // const, volatile
    std::string variableAssignmentState = "NO_ASSIGN";
    std::unordered_map<std::string, std::vector<VariableContext>> variableBindings;  // Can be bound to different

    // Functions
    std::string returnType = "VOID";
    std::vector<int> functionArgs;
    std::vector<std::string> allFunctions;
    std::unordered_set<std::string> declaredFunctions;
    std::unordered_map<std::string, FunctionContext> functionBindings;

    // Registers
    int virtualRegisters = 0;

    // Labels
    int labelCount = 0;
    std::string endLabel = "end";
    std::vector<std::string> functionEnds;
	std::vector<std::string> breakPoints;
	std::vector<std::string> continuePoints;

	std::unordered_map<std::string, EnumContext> enumerations;

    // Contextual information for Python translator
    std::unordered_set<std::string> globalVariables;
    std::unordered_set<std::string> allVariables;
    std::unordered_set<std::string> allFunctionsTranslator;
    std::unordered_set<std::string> functionArgsTranslator;

    // Helper methods
    int getVariableIntValue(const std::string& id) {
        if (!variableBindings.count(id)) {
            throw std::runtime_error("[ERROR] Unable to retrieve intValue for undeclared variable \"" + id + "\"\n");
        }
        return variableBindings[id].back().intValue;
    }
    void setVariableIntValue(const std::string& id, const int& val) {
        if (!variableBindings.count(id)) {
            throw std::runtime_error("[ERROR] Unable to set intValue for undeclared variable \"" + id + "\"\n");
        }
        variableBindings[id].back().intValue = val;
    }

    friend std::ostream& operator<<(std::ostream& out, const ProgramContext& p) {
        out << "\n[INFO] *** Program Context ***\n";

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
        out << "[INFO] * virtualRegisters: " << p.virtualRegisters << "\n";
        out << "[INFO] * identifier: " << p.identifier << "\n";
        out << "[INFO] * typeSpecifier: " << p.typeSpecifier << "\n";
        out << "[INFO] * typeQualifier: " << p.typeQualifier << "\n";  // const, volatile
        out << "[INFO] * variableAssignmentState: " << p.variableAssignmentState << "\n";
        out << "[INFO] * variableBindings:\n";
        for (auto& it : p.variableBindings) {
            out << "[INFO] | {" << it.first << "->";
            printIterable(out, it.second);
            out << "}\n";
        }
        out << "[INFO] *\n";

        // Functions
        out << "[INFO] * functionArgs: ";
        printIterable(out, p.functionArgs);
        out << "\n";
        out << "[INFO] * declaredFunctions: ";
        printIterable(out, p.declaredFunctions);
        out << "\n";
        out << "[INFO] * allFunctions: ";
        printIterable(out, p.allFunctions);
        out << "\n";
        out << "[INFO] * functionBindings:\n";

        for (auto& it : p.functionBindings) {
            out << "[INFO] | {" << it.first << "->" << it.second << "}\n";
        }
        out << "[INFO] *\n";

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
