cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  "Project"
  VERSION 0.1.0 
  LANGUAGES CXX
)

#
# Include .hpp files
#

include_directories("include")

#
# Add library
#

add_library(mylib src/libfile.cpp)

#
# Add exe
#

add_executable(myexe src/mainfile.cpp)

#
# Link library
#

target_link_libraries(myexe mylib)