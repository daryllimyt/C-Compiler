// Main driver of the compiler. Parses and compiles the AST
// Creates an AST by calling parseAST()
// Traverses the AST by calling compile()

#include "include/ast.hpp"
int main(int argc, char *argv[])
{
  if (argc >= 3)
  {
    std::string flag = argv[1];

    // Identify flag
    if (flag == "-S") // C to MIPS compilation
    {
      const NodePtr ast_compiler = parseAST(argv[2], argv[4]);
      std::ostream *output; // Output stream
      std::ofstream file;   // Output file
    }
    else if (flag == "--translate") // C to Python translation
    {
      return 0;
    }
    else // Unidentified flag
    {
      std::cerr << "Error: Unidentified flag " << flag << "\n";
      return -1;
    }
  }
}