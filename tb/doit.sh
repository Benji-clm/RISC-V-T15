#!/bin/bash

# This script runs the testbench
# Usage: ./doit.sh <file1.cpp> <file2.cpp>

# Constants
SCRIPT_DIR=$(dirname "$(realpath "$0")")
TEST_FOLDER=$(realpath "$SCRIPT_DIR/tests")
# RTL_FOLDER=$(realpath "$SCRIPT_DIR/../rtl")
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)

source "$SCRIPT_DIR/common.sh"

# Variables
passes=0
fails=0

# Handle terminal arguments
if [[ $# -eq 0 ]]; then
    # If no arguments provided, run all tests
    files=(${TEST_FOLDER}/*.cpp)
else
    # If arguments provided, use them as input files
    files=("$@")
fi

cd $SCRIPT_DIR

# Wipe previous test output
rm -rf test_out/*

# Iterate through files
for file in "${files[@]}"; do
    name=$(basename "$file" _tb.cpp | cut -f1 -d\-)

    # If one of the graph, ignore test
    if [[ "$file" == *"gaussian_mytb.cpp" || "$file" == *"noisy_mytb.cpp" || "$file" == *"triangle_mytb.cpp" || "$file" == *"vbuddy.cpp" || "$file" == *"f1_mytb.cpp" ]]; then
        continue
    fi
# 
    # If verify.cpp -> we are testing the top module
    if [ $name == "verify.cpp" ]; then
        name="top"
    fi

    # Translate Verilog -> C++ including testbench
    verilator -Wall --trace \
            -cc ${RTL_FOLDER}/${name}.sv \
            --exe "${file}" \
            ${RTL_Y_FLAGS} \
            --prefix "Vdut" \
            -o Vdut \
            -LDFLAGS "-lgtest -lgtest_main -lpthread"

    # Build C++ project with automatically generated Makefile
    make -j -C obj_dir/ -f Vdut.mk

    # Run executable simulation file
    ./obj_dir/Vdut

    # Check if the test succeeded or not
    if [ $? -eq 0 ]; then
        ((passes++))
    else
        ((fails++))
    fi

done

# Save obj_dir in test_out
mv obj_dir test_out/
