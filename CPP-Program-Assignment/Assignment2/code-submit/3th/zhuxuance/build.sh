#!/bin/bash
set -e

BASE_PATH=$(pwd)
BUILD_PATH=$BASE_PATH/build
EXECUTABLE_NAME="findOptimalPath"

rm -rf $BUILD_PATH
mkdir -p $BUILD_PATH/cmake_cache $BUILD_PATH/bin
cd $BUILD_PATH/cmake_cache
cmake -DEXECUTABLE_NAME=$EXECUTABLE_NAME $BASE_PATH
make
mv $BASE_PATH/$EXECUTABLE_NAME $BUILD_PATH/bin/$EXECUTABLE_NAME