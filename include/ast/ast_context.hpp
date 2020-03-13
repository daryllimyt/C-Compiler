#ifndef AST_CONTEXT_HPP_
#define AST_CONTEXT_HPP_

#include <string>
#include <iostream>
#include <vector>

struct VariableContext {
    // Unique to each variable, create a new VariableContext for each variable
    int address;       // Address in memory of where the variable is located
    int scope;         // Scope in which the variable was defined
    std::string type;  // Type specifier
};

struct ProgramContext {
    // General
    std::vector<int> parameters;

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

    // Contextual information for Python translator
    std::unordered_set<std::string> globalVariables;
    std::unordered_set<std::string> scopeVariables;

    // Others
    int scope = 0;
};

// template <class T>
// void printIterable(const T &iterable) {
//     for (auto &it : iterable) {
//         std::cerr << it << "\t";
//     }
//     std::cerr << "\n";
// }

// void printContext(ProgramContext context) {
//     std::cerr << "Info: *** Program Context ***\n";
//     std::cerr << "Info: * parameters: ";
//     printIterable(context.parameters);

//     /* Contextual information for MIPS code generator */
//     // Frame
    
//     std::cerr << "Info: * frameIndex: " << context.frameIndex << "\n";
//     // std::cerr << ::string frameStart;
//     // std::cerr << ::string frameEnd;
//     printIterable(context.frameSizes);     // Tracks requred space for each frame (index)
//     printIterable(context.variableCount);  // Tracks # of vars in each frame (index)

//     // // Variables
//     // std::string identifier;
//     // std::string typeSpecifier;
//     // std::string typeQualifier; // const, volatile
//     // std::string variableAssignmentState = "NO_ASSIGN";

//     // // Contextual information for Python translator
//     // std::unordered_set<std::string> globalVariables;
//     // std::unordered_set<std::string> scopeVariables;

//     // // Others
//     // int scope = 0;
// }

#endif
