# iEDA-standard-develop
一、目录结构：
  1、文件夹include存放头文件headfile.hpp
  2、文件夹src中放函数库文件libfile.cpp和包含mian函数的文件mainfile.cpp
二、运行方法：
  通过根目录下的CMakeLists.txt生成makefile文件，通过make的方式生成可执行文件myexe。
  命令行步骤如下：
  $cd build
  $cmake ..
  $make
  $./myexe
