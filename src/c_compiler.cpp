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
            std::cerr << "Error: Cannot open source file '" << SRC_FILE << "'.\n";
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
            std::cerr << "Error: Unidentified flag " << MODE_FLAG << ", unable to set driver.\n";
            return -1;
        }
        std::cerr << "Info: Driver set to " << DRIVER << "\n";

        // Set output destination
        if (argc == 3) {
            std::cerr << "Warning: No destination file specified\nRedirecting " << DRIVER << " output to command line...\n";
            output = &std::cout;
        } else {
            std::string SECOND_FLAG = argv[3];
            if (SECOND_FLAG == "-o") {
                std::string destFilename = argv[4];
                {
                    std::ifstream tempOut;
                    tempOut.open(destFilename);
                    if (!tempOut.is_open()) {
                        std::cerr << "Warning: Output file \"" << destFilename << "\" was not found\n";
                        std::cerr << "Creating new file \"" << destFilename << "\"\n";
                    } else {
                        tempOut.close();
                    }
                }
                output = &outfile;
                outfile.open(destFilename);

                // Checking for extension .py
                if (destFilename[destFilename.size() - 2] != 'p' && destFilename[destFilename.size() - 1] != 'y') {
                    std::cerr << "Warning: Output file is not of type .py\n";
                }
            } else {
                std::cerr << "Warning: Unidentified flag \"" << SECOND_FLAG << "\"\n";
                std::cerr << "Redirecting " << DRIVER << " output to command line...\n";
                output = &std::cout;
            }
        }

        // Identify driver
        if (DRIVER == "compiler") {  // C to MIPS compilation
            std::cerr << "Info: Compilation in progress...\n";
            Compile(output, context, astRoot);
            std::cerr << "Info: Compilation complete\n";

        } else if (DRIVER == "translator") {  // C to Python translation
            std::cerr << "Info: Translation in progress...\n";
            context.scope = 0;
            PyTranslate(output, context, astRoot);
            *output << "\nif __name__ == \"__main__\":";
            *output << "\n\timport sys";
            *output << "\n\tret=main()";
            *output << "\n\tsys.exit(ret)\n";
            std::cerr << "Info: Translation complete\n";
        }
        // PRINTING PROGRAM CONTEXT
        if (Util::DEBUG) {
            std::cerr << "Info: *** Program Context ***\n";


            /* Contextual information for MIPS code generator */
            // Frame
            std::cerr << "Info: * frameIndex: " << context.frameIndex << "\n";
            std::cerr << "Info: * frameStart: " << context.frameStart << "\n";
            std::cerr << "Info: * frameEnd: " << context.frameEnd << "\n";
            std::cerr << "Info: * frameSizes: ";
            printIterable(context.frameSizes);  // Tracks requred space for each frame (index)
            std::cerr << "Info: * variableCount: ";
            printIterable(context.variableCount);  // Tracks # of vars in each frame (index)

            // // Variables
            std::cerr << "Info: * identifier: " << context.identifier << "\n";
            std::cerr << "Info: * typeSpecifier: " << context.typeSpecifier << "\n";
            std::cerr << "Info: * typeQualifier: " << context.typeQualifier << "\n";  // const, volatile
            std::cerr << "Info: * variableAssignmentState: " << context.variableAssignmentState << "\n";

            // Functions
            std::cerr << "Info: * functionArgs: ";
            printIterable(context.functionArgs);
            std::cerr << "Info: * allFunctions: ";
            printIterable(context.allFunctions);

            // Contextual information for Python translator
            std::cerr << "Info: * globalVariables: ";
            printIterable(context.globalVariables);
            std::cerr << "Info: * allVariables: ";
            printIterable(context.allVariables);

            // Others
            std::cerr << "Info: * identifier:\t" << context.scope << "\n";
        }

        return 0;  // Successful execution
    }
    std::cerr << "Error: Received " << argc << " arguments when minimum required is 3.\n";
    return -1;
}