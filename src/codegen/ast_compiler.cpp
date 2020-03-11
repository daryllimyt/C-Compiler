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
        // Calculate number of global variables for actual number, use CountGlobalVars(astNode->getNext())
        // Push stack from by space needed for global variables
        // Set end label of astNode
        // Output some flag for qemu
         Compile(output, context, astNode->getNext()); // First frame
    }
    else if(astNode->getType() == "FRAME")
    {
        Compile(output, context, astNode->getLeft()); // Previous frame
        Compile(output, context, astNode->getRight()); // Current frame
    }
    else if(astNode->getType() == "INT")
    {
        context.typeSpecifier = "INT";
    }
    else if(astNode->getType() == "FUNCTION_DEFINITION") 
    {
        // If function definition has no statements then it is a function declaration
    
        
        

    }
    else if(astNode->getType() == "FUNCTION_DECLARATION") 
    {
        context.variableAssignmentState = "FUNCTION_DECLARATION";
        Compile(output, context, astNode->getLeft());
        
    }
    
    else
    {
        throw std::runtime_error("Unknown ast type: \"" + astNode->getType() + "\"\n");
    }
}
// The name of the register to put the result in
