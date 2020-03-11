// Main driver of the compiler. Parses and compiles the AST
// Creates an AST by calling parseAST()
// Traverses the AST by calling compile()

#include "include/ast.hpp"
int main(int argc, char *argv[])
{
  if (argc >= 3)
  {
    std::string flag = argv[1];
    FILE* infile;
    yyset_in(infile);

    // Identify flag
    if (flag == "-S") // C to MIPS compilation
    {
      const NodePtr astRoot = parseAST();
      std::ostream *output; // Output stream
      std::ofstream file;   // Output file

      ProgramContext context;
      Compile(output, context, astRoot);
    }
    else if (flag == "--translate") // C to Python translation
    {
      const NodePtr astRoot = parseAST();
      std::ostream *output; // Output stream
      std::ofstream file;   // Output file

      ProgramContext context;
      PyTranslate(output, context, astRoot);
    }
    else // Unidentified flag
    {
      std::cerr << "Error: Unidentified flag " << flag << "\n";
      return -1;
    }
  }
}