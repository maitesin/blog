project(Google_test_example)
cmake_minimum_required(VERSION 2.8)

include(conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

INCLUDE_DIRECTORIES(src)
ADD_EXECUTABLE(run_test src/test.cpp)
TARGET_LINK_LIBRARIES(run_test ${CONAN_LIBS})
