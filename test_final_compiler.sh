#!/bin/bash

PASSED=0
CHECKED=0
FAILED=0

declare -a FAILARRAY

echo "========================================"
echo -e "\e[95m            COMPILER TESTBENCH\e[0m"
echo "========================================"
echo "[INFO] Cleaning directories and building compiler..."
make all
if [[ "$?" -ne "0" ]]; then
    echo -e "[ERROR] \e[31m\e[1mCould not build compiler."
    exit 1;
fi

mkdir -p translator_tests/extra_tests/b_compiler/assembly
mkdir -p translator_tests/extra_tests/b_compiler/objects
mkdir -p translator_tests/extra_tests/b_compiler/outputs

N=0

for path in translator_tests/extra_tests/b_compiler/inputs/* ; do

    COUNT=$(( $COUNT+1 ));
    file=${path##*/};
    N=${file%.*};

    echo ""
    echo "========================================"
    echo -e "\e[1m    TEST $N      \e[0m"
    echo "========================================"
    echo ""

    # Compile test function with compiler under test to assembly
    bin/c_compiler -S translator_tests/extra_tests/b_compiler/inputs/$N.c -o translator_tests/extra_tests/b_compiler/assembly/$N.s 
    if [[ $? -ne 0 ]]; then
        >&2 echo -e "[ERROR] \e[31m\e[1mFAILED! \e[33m\e[1mCompiler returned error message. \e[0m"
        FAILED=$(( ${FAILED}+1 ));
        FAILARRAY[${FAILED}]=$N;
        continue
    fi

    # Compile driver with normal GCC
    mips-linux-gnu-gcc -mfp32 -o translator_tests/extra_tests/b_compiler/objects/$N.o -c translator_tests/extra_tests/b_compiler/assembly/$N.s
    if [[ $? -ne 0 ]]; then
        echo -e "[ERROR] \e[31m\e[1mFAILED! \e[33m\e[1mCouldn't compile driver program using GCC. \e[0m"
        FAILED=$(( ${FAILED}+1 ));
        FAILARRAY[${FAILED}]=$N;
        continue
    fi

    # Link driver object and assembly into executable
    mips-linux-gnu-gcc -mfp32 -static -o translator_tests/extra_tests/b_compiler/outputs/${N}_exe translator_tests/extra_tests/b_compiler/objects/$N.o translator_tests/extra_tests/b_compiler/drivers/$N.c
    if [[ $? -ne 0 ]]; then
        echo -e "[ERROR] \e[31m\e[1mFAILED! \e[33m\e[1mLinker returned error message. \e[0m"
        FAILED=$(( ${FAILED}+1 ));
        FAILARRAY[${FAILED}]=$N;
        continue
    fi

    # Run the linked and assembled executable
    qemu-mips translator_tests/extra_tests/b_compiler/outputs/${N}_exe
    ret=$?
    if [[ $ret -ne 0 ]]; then
        echo -e "[INFO] \e[31m\e[1mFAILED!\e[33m Testcase returned $ret, but expected 0. \e[0m"
        FAILED=$(( ${FAILED}+1 ));
        FAILARRAY[${FAILED}]=$N;
    else
        echo -e "[INFO] \e[32m\e[1mPASSED!\e[0m"
        PASSED=$(( ${PASSED}+1 ));
    fi

    CHECKED=$(( $CHECKED+1 ));

    echo""
done

echo "########################################"
echo -e "[INFO] \e[32m\e[1mPassed ${PASSED} out of ${COUNT}.\e[0m"
echo -e "[INFO] \e[31m\e[1mFailed cases:\e[0m"
for case in "${FAILARRAY[*]}"
do
   echo $FAILARRAY[${case}]
done 