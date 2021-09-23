cmake_minimum_required(VERSION 3.16)

set(THIS ASearchTest)
set (SOURCES 
    ASearchTest.cpp
)

add_executable(${THIS} ${SOURCES})
target_link_libraries(${THIS} PUBLIC
    gtest_main
    Assignment2_pro
)

add_test(
    NAME ${THIS}
    COMMAND ${THIS}
)