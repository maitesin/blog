project(Unity_example)
cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(lib)
ADD_EXECUTABLE(run_test unittest/test_both_even.c src/both.c)
