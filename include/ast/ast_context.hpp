#ifndef AST_CONTEXT_HPP_
#define AST_CONTEXT_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct VariableContext {
    // Unique to each variable, create a new VariableContext for each variable
    int address;       // Address in memory of where the variable is located
    int scope;         // Scope in which the variable was defined
    std::string type;  // Type specifier
};

struct FunctionContext {
    // Unique to each variable, create a new VariableContext for each variable
    int scope;         // Scope in which the variable was defined
    std::string type;  // Type specifier
    std::vector<std::string> args;
};

struct ProgramContext {
    // General
    

    /* Contextual information for MIPS code generator */
    // Frame
    int frameIndex = 0;  // Frame index of current function/scope
    std::string frameStart;
    std::string frameEnd;
    std::vector<int> frameSizes;     // Tracks requred space for each frame (index)
    std::vector<int> variableCount;  // Tracks # of vars in each frame (index)

    // Variables
    std::string identifier;
    std::string typeSpecifier;
    std::string typeQualifier; // const, volatile
    std::unordered_map<std::string, VariableContext> variableBindings;
    /* Variable assignment states (for variable nodes)
    None: NO_ASSIGN
    Variable declaration: VAR_DECLARATION
    Variable assignment to expression: VAR_ASSIGN_EXPR
    Function declaration: FUNCTION_DECLARATION
    Function definition: FUNCTION_DEFINITION
    Array declaration (sized): ARRAY_DECLARATION_SIZED
    Array declaration (unsized): ARRAY_DECLARATION_UNSIZED
    */
    std::string variableAssignmentState = "NO_ASSIGN";

    // Functions
    std::unordered_set<std::string> functionArgs;
    std::unordered_set<std::string> allFunctions;
    std::unordered_map<std::string, FunctionContext> functionBindings;

    // Contextual information for Python translator
    std::unordered_set<std::string> globalVariables;
    std::unordered_set<std::string> allVariables;

    // Others
    int scope = 0;
};
#endif
