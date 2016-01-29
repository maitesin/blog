project(clang_tools)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

INCLUDE_DIRECTORIES(src)
ADD_EXECUTABLE(tidy src/tidy.cpp)
