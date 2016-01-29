project(clang_tools)
cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(src)
ADD_EXECUTABLE(old src/old.cpp)
