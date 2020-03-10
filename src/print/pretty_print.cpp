#include "include/ast.hpp"

#include <cstdlib>

void PrettyPrint(std::ostream &dst, NodePtr node, std::string indent)
{
    dst << indent << node->type;

    if (node->value.size() > 0)
    {
        dst << " : " << node->value;
    }

    if (node->branches.size() > 0)
    {
        dst << " [" << std::endl;
        for (unsigned i = 0; i < node->branches.size(); i++)
        {
            PrettyPrint(dst, node->branches[i], indent + "  ");
        }
        dst << indent << "]";
    }
    dst << std::endl;
}

int main(int argc, char *argv[])
{
    const NodePtr ast_compiler = parseAST(argv[2], argv[4]);
    
    PrettyPrint(std::cout, ast_compiler, "");
    
    return 0;
}


