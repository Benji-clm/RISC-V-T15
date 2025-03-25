# common.sh
RTL_FOLDER=$(realpath "$SCRIPT_DIR/../rtl")
RTL_Y_FLAGS="
    -y ${RTL_FOLDER}
    -y ${RTL_FOLDER}/pipeline
    -y ${RTL_FOLDER}/core
    -y ${RTL_FOLDER}/memory
    -y ${RTL_FOLDER}/muxes
"
