// This file generates the MIPS assembly code

#include "include/ast.hpp"

void Compile(std::ostream *output, ProgramContext &context, NodePtr astNode)
{
    if (astNode == NULL)
    {
        throw std::runtime_error("Invalid AST node.\n");
    }
    else if (astNode->getType() == "ROOT")
    {
        // Calculate number of global variables for actual number, use CountGlobalVars(astNode->GetNext())
        // Push stack from by space needed for global variables
        // Set end label of astNode
        // Some flag for qemu
         Compile(output, context, astNode->GetNext());
    }
    else if(astNode->getType() == "FRAME")
    {
        Compile(output, context, astNode->GetLeft());
        Compile(output, context, astNode->GetRight());
    }
    else if(astNode->GetType() == "INT")
    {
        context.specifier = "INT";
    }
    else if(astNode->getType() == "FUNCTION_DEFINITION") 
    {

    }
    else if(astNode->getType() == "FUNCTION_DECLARATION") 
    {
        Compile(output, context, astNode->GetLeft()); // Get function identifier from left branch

    }
    
    else
    {
        throw std::runtime_error("Unknown ast type: \"" + astNode->getType() + "\"\n");
    }
}
// The name of the register to put the result in
