#!/bin/bash

PASSED=0
CHECKED=0
FAILED=0

declare -a FAILARRAY

echo "========================================"
echo "               TESTBENCH"
echo "========================================"
echo "[INFO] Cleaning directories and building compiler..."
make all
if [[ "$?" -ne "0" ]]; then
    echo "[ERROR] Could not build compiler."
    exit 1;
fi

mkdir -p translator_tests/extra_tests/b_compiler/assembly
mkdir -p translator_tests/extra_tests/b_compiler/objects
mkdir -p translator_tests/extra_tests/b_compiler/outputs

N=0

for i in translator_tests/extra_tests/b_compiler/inputs/* ; do

    N=$(( $N+1 ));
    
    echo ""
    echo "==========================="
    echo "          TEST $N      "
    echo "==========================="
    echo ""

    # Compile test function with compiler under test to assembly
    bin/c_compiler -S translator_tests/extra_tests/b_compiler/inputs/$N.c -o translator_tests/extra_tests/b_compiler/assembly/$N.s 
    if [[ $? -ne 0 ]]; then
        >&2 echo "[ERROR] Compiler returned error message."
        FAILED=$(( ${FAILED}+1 ));
        FAILARRAY[${FAILED}]=$N;
        continue
    fi

    # Compile driver with normal GCC
    mips-linux-gnu-gcc -mfp32 -o translator_tests/extra_tests/b_compiler/objects/$N.o -c translator_tests/extra_tests/b_compiler/assembly/$N.s
    if [[ $? -ne 0 ]]; then
        echo "[ERROR] Couldn't compile driver program using GCC."
        FAILED=$(( ${FAILED}+1 ));
        FAILARRAY[${FAILED}]=$N;
        continue
    fi

    # Link driver object and assembly into executable
    mips-linux-gnu-gcc -mfp32 -static -o translator_tests/extra_tests/b_compiler/outputs/${N}_exe translator_tests/extra_tests/b_compiler/objects/$N.o translator_tests/extra_tests/b_compiler/drivers/$N.c
    if [[ $? -ne 0 ]]; then
        echo "[ERROR] Linker returned error message."
        FAILED=$(( ${FAILED}+1 ));
        FAILARRAY[${FAILED}]=$N;
        continue
    fi

    # Run the linked and assembled executable
    qemu-mips translator_tests/extra_tests/b_compiler/outputs/${N}_exe
    ret=$?
    if [[ $ret -ne 0 ]]; then
        echo "FAILED! Testcase returned $ret, but expected 0."
        FAILED=$(( ${FAILED}+1 ));
        FAILARRAY[${FAILED}]=$N;
    else
        echo "PASSED!"
        PASSED=$(( ${PASSED}+1 ));
    fi

    CHECKED=$(( $CHECKED+1 ));

    echo""
done

echo "########################################"
echo "[INFO] Passed ${PASSED} out of ${N}."
echo "[INFO] Failed cases:"
for case in "${FAILARRAY[*]}"
do
   echo $FAILARRAY[${case}]
done 