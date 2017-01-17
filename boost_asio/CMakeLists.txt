project(Boost-ASIO-Basics)
cmake_minimum_required(VERSION 2.8)

include(conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread --std=c++11")

add_executable(simple src/scheduler/simple.cpp)
target_link_libraries(simple ${CONAN_LIBS})

add_executable(two_workers src/scheduler/two_workers.cpp)
target_link_libraries(two_workers ${CONAN_LIBS})

add_executable(client_sync src/sync/client.cpp)
target_link_libraries(client_sync ${CONAN_LIBS})

add_executable(server_sync src/sync/server.cpp)
target_link_libraries(server_sync ${CONAN_LIBS})
