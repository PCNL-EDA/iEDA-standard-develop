#!/bin/bash
# file          main.cpp
# brief         
# author        wanghao (harry0789@qq.com)
# date          2021-09-01
# copyright     Copyright (c) 2021 PCL IEDA

set -e
echo -e "\033[47;30m               program build start               \033[0m"
BASEPATH=$(pwd)

case_not_define_install_dir(){
  echo -e "\033[47;30m The executable will be installed in directory:  \033[0m"
  echo -e "\033[46;30m $BASEPATH/build/bin\033[0m"
  INSTALL_DIR="$BASEPATH/build"
}

if [ "$#" == 0 ]
then
  case_not_define_install_dir
elif [ "$#" == 1 ]
then
  echo -e "\033[47;30m build mode (default:debug): \033[0m"
  echo -e "\033[46;30m $1 \033[0m"
  if [ "$1" != "release" ]
  then
    if [ "$1" != "debug" ]
    then
      echo -e "Build mode only support"
      echo -e "\033[46;30m\"release\"\033[0m"
      echo -e "\033[46;30m\"debug\"\033[0m"
      exit 1
    fi
  fi
  BUILD_MODE="$1"
  case_not_define_install_dir
elif [ "$#" == 2 ]
then
  echo -e "\033[47;30m The executable will be installed in directory:  \033[0m"
  echo -e "\033[46;30m $2\033[0m"
  INSTALL_DIR="$BASEPATH/$2"
else
  echo -e "Please either provide an install directory path"
  echo -e "or this program will be installed in default directory:"
  echo -e "\033[47;30m./build/bin\033[0m"
  echo -e "\033[47;30m             program build failed              \033[0m"
  exit 1
fi

if [ "$BUILD_MODE" != "release" ]
then
  echo -e "\033[47;30m build mode: \033[0m"
  echo -e "\033[46;30m debug \033[0m"
  BUILD_MODE="debug"
fi

rm -rf $BASEPATH/build
mkdir -p $BASEPATH/build/cmake_cache
cd $BASEPATH/build/cmake_cache
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR $BASEPATH -DBUILD_MODE=$BUILD_MODE
make -j12
make install -j12
echo -e "\033[47;30m run '$INSTALL_DIR/bin/hello' to execute the program! \033[0m"
