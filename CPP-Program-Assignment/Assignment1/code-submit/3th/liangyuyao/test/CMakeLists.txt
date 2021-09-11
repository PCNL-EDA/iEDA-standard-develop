cmake_minimum_required(VERSION 3.16)

set(THIS EulerTest)
set (SOURCES 
    EulerTest.cpp
)

add_executable(${THIS} ${SOURCES})
target_link_libraries(${THIS} PUBLIC
    gtest_main
    Assignment1_pro
)

add_test(
    NAME ${THIS}
    COMMAND ${THIS}
)