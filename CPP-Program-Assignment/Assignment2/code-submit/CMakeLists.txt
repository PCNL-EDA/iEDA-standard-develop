cmake_minimum_required(VERSION 3.0.0)
project(liujikang-std VERSION 0.1.0)


aux_source_directory(src DIR_SRCS)
include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin/)

add_executable(main ${DIR_SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

