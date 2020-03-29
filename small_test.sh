make all
bin/c_compiler -S translator_tests/extra_tests/b_compiler/inputs/106.c -o compiler_tests/functions/test_program.s
mips-linux-gnu-gcc -mfp32 -o compiler_tests/functions/test_program.o -c compiler_tests/functions/test_program.s
mips-linux-gnu-gcc -mfp32 -static -o compiler_tests/functions/test_program compiler_tests/functions/test_program.o translator_tests/extra_tests/b_compiler/drivers/106.c
qemu-mips compiler_tests/functions/test_program
echo $?