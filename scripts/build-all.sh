#!/bin/bash

cd ..

cwd=$(pwd)
OUTPUT_DIR=build
SOURCE_DIR=./
TEST_DIR=./test
SCRIPTS_DIR=./scripts

if [ $# == 1 ]; then
    if [ $1 == "clean" ]; then
        echo "Deleting output files ..."
        rm -rf ${OUTPUT_DIR}
        cd ${SOURCE_DIR}
        make clean
        exit 0
    fi
fi

echo -e "\nChecking code style"
cd ${cwd}
cd ${SCRIPTS_DIR}
bash check-style.sh


echo -e '\nBuilding the project ...'
cd ${cwd}
mkdir -p ${OUTPUT_DIR}
cd ${OUTPUT_DIR}
cmake ../
make

echo -e '\nGenerating the docs ...'
cd ${cwd}
doxygen Doxyfile