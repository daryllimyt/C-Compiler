make all
bin/c_compiler -S translator_tests/extra_tests/b_compiler/inputs/82.c -o compiler_tests/functions/test_program.s
mips-linux-gnu-gcc -mfp32 -o compiler_tests/functions/test_program.o -c compiler_tests/functions/test_program.s
mips-linux-gnu-gcc -mfp32 -static -o compiler_tests/functions/test_program compiler_tests/functions/test_program.o compiler_tests/general/basic_function_driver.c
qemu-mips compiler_tests/functions/test_program
echo $?