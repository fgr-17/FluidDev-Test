#!/bin/bash
cwd=$(pwd)
OUTPUT_DIR=build
SOURCE_DIR=./
TEST_DIR=./test

if [ $# == 1 ]; then
    if [ $1 == "clean" ]; then
        echo "Deleting output files ..."
        rm -rf ${OUTPUT_DIR}
        cd ${SOURCE_DIR}
        make clean
        exit 0
    fi
fi

echo -e '\nBuilding the project ...'
cd ${cwd}
mkdir -p ${OUTPUT_DIR}
cd ${OUTPUT_DIR}
cmake ../
make