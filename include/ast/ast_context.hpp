#ifndef AST_CONTEXT_HPP_
#define AST_CONTEXT_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct VariableContext {
    // Single variable name can have different contexts in each scope
    int addressOffset;       // Address offset in memory of where the variable is located
    int scope;         // Scope in which the variable was defined
    std::string typeSpecifier;  // Type specifier
};

struct FunctionContext {
    int scope;         // Scope in which the variable was defined
    std::string typeSpecifier;  // Type specifier
    std::vector<std::string> args;
    FunctionContext(const int& scope_, const std::string &typeSpecifier_) {
        scope = scope_;
        typeSpecifier = typeSpecifier_;
    }
    void addArg(const std::string &arg) {
        args.push_back(arg);
    }
};

struct ProgramContext {
    // General
    

    /* Contextual information for MIPS code generator */
    // Frame
    int frameIndex = 0;  // Frame index of current function/scope
    std::string frameStart;
    std::string frameEnd;
    std::vector<int> frameSizes = {0};     // Tracks requred space for each frame (index)
    std::vector<int> variableCount = {0};  // Tracks # of vars in each frame (index)

    // Variables
    std::string identifier;
    std::string typeSpecifier;
    std::string typeQualifier; // const, volatile
    std::unordered_map<std::string, std::vector<VariableContext>> variableBindings; // Can be bound to different
    /* Variable assignment states (for variable nodes)
    None: NO_ASSIGN
    Variable declaration: VARIABLE_DECLARATION
    Variable assignment to expression: VARIABLE_ASSIGNMENT
    Function declaration: FUNCTION_DECLARATION
    Function definition: FUNCTION_DEFINITION
    Array declaration (sized): ARRAY_DECLARATION_SIZED
    Array declaration (unsized): ARRAY_DECLARATION_UNSIZED
    GLOBAL
    */
    std::string variableAssignmentState = "NO_ASSIGN";

    // Functions
    std::unordered_set<std::string> functionArgs;
    std::unordered_set<std::string> allFunctions;
    std::unordered_map<std::string, FunctionContext> functionBindings;

    // Labels
    int labelCount = 0;
    std::string endLabel = "end";


    // Contextual information for Python translator
    std::unordered_set<std::string> globalVariables;
    std::unordered_set<std::string> allVariables;

    // Others
    int scope = 0;
};
#endif
