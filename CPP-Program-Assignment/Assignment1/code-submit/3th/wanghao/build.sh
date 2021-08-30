#!/bin/bash
mkdir -p ./build
cd ./build
cmake ..
make
mv hello ..
echo "========== run './hello' to execute the program ==========“