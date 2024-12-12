SCRIPT_DIR=$(dirname "$(realpath "$0")")
TEST_FOLDER=$(realpath "$SCRIPT_DIR")
RTL_FOLDER=$(realpath "$SCRIPT_DIR/../rtl")
name="top"
test_name="f1_mytb"

rm -rf obj_dir
rm -f top.vcd

verilator -Wall --cc --trace -I${RTL_FOLDER} ${RTL_FOLDER}/${name}.sv --exe ${TEST_FOLDER}/${test_name}.cpp

make -j -C obj_dir/ -f V${name}.mk V${name}

obj_dir/V${name}