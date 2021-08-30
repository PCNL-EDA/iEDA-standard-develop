#!/bin/bash

echo -e "\033[47;30m               program build start               \033[0m"
set -e
rm -rf ./build
mkdir -p ./build
cd ./build
cmake ../src
make
mv hello ../bin
echo -e "\033[47;30m    run ./bin/hello' to execute the program!    \033[0m"