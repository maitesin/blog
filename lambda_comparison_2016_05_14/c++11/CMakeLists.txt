project(lambdas_c++11)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

INCLUDE_DIRECTORIES(src)
ADD_EXECUTABLE(example1 src/example1.cpp)
ADD_EXECUTABLE(example2 src/example2.cpp)
