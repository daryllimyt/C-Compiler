// Main driver of the compiler. Parses and compiles the AST
// Creates an AST by calling parseAST()
// Traverses the AST by calling compile()

#include "include/ast.hpp"

int main(int argc, char *argv[]) {
    if (argc >= 3) {
        std::string flag = argv[1];
        std::string src = argv[2];
        FILE *infile;

        if (!(infile = fopen(src.c_str(), "r"))) {
            std::cerr << "Cannot open source file: '" << src << "'." << std::endl;
            return 1;
        }
        yyset_in(infile);  // Sets the file for flex and bison to read

        // Identify flag
        if (flag == "-S") {
            // C to MIPS compilation
            const NodePtr astRoot = parseAST();
            std::ostream *output;  // Output stream
            std::ofstream file;    // Output file

            ProgramContext context;
            Compile(output, context, astRoot);
        } else if (flag == "--translate") {
            // C to Python translation
            const NodePtr astRoot = parseAST();
            std::ostream *output;  // Output stream
            std::ofstream file;    // Output file

            ProgramContext context;
            context.scope = 0;
            PyTranslate(output, context, astRoot);

            *output << "\nif __name__ == \"__main__\":";
            *output << "\n\timport sys";
            *output << "\n\tret=main()";
            *output << "\n\tsys.exit(ret)\n";

        } else {
            // Unidentified flag
            std::cerr << "Error: Unidentified flag " << flag << "\n";
            return -1;
        }
    }
}