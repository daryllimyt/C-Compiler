// This file generates the MIPS assembly code

#include "include/ast.hpp"

void Compile(std::ostream *output, InterpretContext &context, NodePtr program)
{
    if (program == NULL)
    {
        throw std::runtime_error("Invalid AST node.\n");
    }
    else if (program->getType() == "root")
    {
        /* code */
    }
    else if(program->getType() == "program")
    {
        Compile(output, context, program->GetLeft());
        Compile(output, context, program->GetRight());
    }
    else if(program->GetType() == "int")
    {
        context.specifier = "int";
    }
    else if(program->getType() == "function declaration") 
    {
        
    }
    
    else
    {
        throw std::runtime_error("Unknown ast type: \"" + program->getType() + "\"\n");
    }
}
// The name of the register to put the result in
