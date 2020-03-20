// Main DRIVER of the compiler. Parses and compiles the AST
// Creates an AST by calling parseAST()
// Traverses the AST by calling compile()

#include "../include/ast.hpp"

int main(int argc, char *argv[]) {
    /*
    Command line args:
    1: mode flag
    2: source file
    3: compilation flag (second flag)
    4: destination file
    
    */
    if (argc >= 3) {
        std::string MODE_FLAG = argv[1];
        std::string SRC_FILE = argv[2];
        FILE *infile;

        if (!(infile = fopen(SRC_FILE.c_str(), "r"))) {
            std::cerr << "[ERROR] Cannot open source file '" << SRC_FILE << "'.\n";
            return -1;
        }
        yyset_in(infile);  // Sets the file for flex and bison to read

        const NodePtr astRoot = parseAST();
        std::ostream *output;   // Output stream
        std::ofstream outfile;  // Output file
        ProgramContext context;

        // Select driver
        std::string DRIVER;
        if (MODE_FLAG == "-S") {
            DRIVER = "compiler";
        } else if (MODE_FLAG == "--translate") {
            DRIVER = "translator";
        } else {
            // Unidentified MODE_FLAG, abort
            std::cerr << "[ERROR] Unidentified flag " << MODE_FLAG << ", unable to set driver.\n";
            return -1;
        }
        std::cerr << "[INFO] Driver set to " << DRIVER << "\n";

        // Set output destination
        if (argc == 3) {
            std::cerr << "[WARNING] No destination file specified\nRedirecting " << DRIVER << " output to command line...\n";
            output = &std::cout;
        } else {
            std::string SECOND_FLAG = argv[3];
            if (SECOND_FLAG == "-o") {
                std::string destFilename = argv[4];
                {
                    std::ifstream tempOut;
                    tempOut.open(destFilename);
                    if (!tempOut.is_open()) {
                        std::cerr << "[WARNING] Output file \"" << destFilename << "\" was not found\n";
                        std::cerr << "[INFO] Creating new file \"" << destFilename << "\"\n";
                    } else {
                        tempOut.close();
                    }
                }
                output = &outfile;
                outfile.open(destFilename);

                // Checking for extension .py
                if (DRIVER == "translator" && destFilename[destFilename.size() - 2] != 'p' && destFilename[destFilename.size() - 1] != 'y') {
                    std::cerr << "[WARNING] Output file is not of type .py\n";
                } else if (DRIVER == "compiler" && destFilename[destFilename.size() - 1] != 's') {
                    std::cerr << "[WARNING] Output file is not of type .s\n";
                }
            } else {
                std::cerr << "[WARNING] Unidentified flag \"" << SECOND_FLAG << "\"\n";
                std::cerr << "[INFO] Redirecting " << DRIVER << " output to command line...\n";
                output = &std::cout;
            }
        }

        // Identify driver
        if (DRIVER == "compiler") {  // C to MIPS compilation
            std::cerr << "[INFO] Compilation in progress...\n";
            Compile(output, context, astRoot);
            std::cerr << "[INFO] Compilation complete\n";

        } else if (DRIVER == "translator") {  // C to Python translation
            std::cerr << "[INFO] Translation in progress...\n";
            context.scope = 0;
            PyTranslate(output, context, astRoot);
            *output << "\nif __name__ == \"__main__\":";
            *output << "\n\timport sys";
            *output << "\n\tret=main()";
            *output << "\n\tsys.exit(ret)\n";
            std::cerr << "[INFO] Translation complete\n";
        }
        // PRINTING PROGRAM CONTEXT
        if (Util::DEBUG) {
            std::cerr << context;
        }

        return 0;  // Successful execution
    }
    std::cerr << "[ERROR] Received " << argc << " arguments when minimum required is 3.\n";
    return -1;
}