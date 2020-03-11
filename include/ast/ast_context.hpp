#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP

#include <string>
#include <iostream>
#include <vector>

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
};

#endif


