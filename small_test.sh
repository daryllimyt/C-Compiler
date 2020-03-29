INPUT_NAME="$1"

INPUT_PATH=translator_tests/extra_tests/b_compiler/inputs/${INPUT_NAME}.c
ASSEMBLY_PATH=translator_tests/extra_tests/b_compiler/reference/${INPUT_NAME}.s
DRIVER_PATH=translator_tests/extra_tests/b_compiler/drivers/${INPUT_NAME}.c

OBJECT_DIR=translator_tests/extra_tests/b_compiler/reference
OUTPUT_DIR=translator_tests/extra_tests/b_compiler/reference

echo "========================================"
echo -e "\e[95m            SMALL TESTBENCH\e[0m"
echo "========================================"
echo "[INFO] Removing directories and building compiler..."
make all

# Generate assembly using our compiler
bin/c_compiler -S ${INPUT_PATH} -o ${ASSEMBLY_PATH} 
if [[ $? -ne 0 ]]; then
    >&2 echo -e "[ERROR] \e[31m\e[1mFAILED! \e[33m\e[1mCompiler returned error message. \e[0m"
    exit 1;
fi

# Create object file with normal GCC
mips-linux-gnu-gcc -mfp32 -o ${OBJECT_DIR}/test_program.o -c ${ASSEMBLY_PATH} 
if [[ $? -ne 0 ]]; then
    echo -e "[ERROR] \e[31m\e[1mFAILED! \e[33m\e[1mCouldn't compile driver program using GCC. \e[0m"
    exit 1;
fi

# Link driver object and assembly into executable
mips-linux-gnu-gcc -mfp32 -static -o ${OUTPUT_DIR}/test_program_exe ${OBJECT_DIR}/test_program.o ${DRIVER_PATH}
if [[ $? -ne 0 ]]; then
    echo -e "[ERROR] \e[31m\e[1mFAILED! \e[33m\e[1mLinker returned error message. \e[0m"
    exit 1;
fi

# Run the linked and assembled executableqemu-mips ${OUTPUT_DIR}/test_program_exe
qemu-mips ${OUTPUT_DIR}/test_program_exe
ret=$?
if [[ $ret -ne 0 ]]; then
    >&2 echo -e "[INFO] \e[31m\e[1mFAILED!\e[33m Testcase returned $ret, but expected 0. \e[0m"
    exit 1;
else
    echo -e "[INFO] \e[32m\e[1mPASSED!\e[0m"
fi
echo $?