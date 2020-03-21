bin/c_compiler -S compiler_tests/functions/test_program.c -o compiler_tests/functions/test_program.s
mips-linux-gnu-gcc -mfp32 -o compiler_tests/functions/test_program.o -c compiler_tests/functions/test_program.s
mips-linux-gnu-gcc -mfp32 -static -o compiler_tests/functions/test_program compiler_tests/functions/test_program.o compiler_tests/functions/test_program_driver.c
qemu-mips compiler_tests/functions/test_program
echo $?