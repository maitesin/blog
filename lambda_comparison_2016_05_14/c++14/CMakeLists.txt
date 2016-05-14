project(lambdas_c++14)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

INCLUDE_DIRECTORIES(src)
ADD_EXECUTABLE(generic src/generic.cpp)
ADD_EXECUTABLE(capture src/capture.cpp)
