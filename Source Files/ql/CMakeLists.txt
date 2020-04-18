cmake_minimum_required(VERSION 3.15)
project(ql)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS graphics REQUIRED)

add_executable(ql src/main.cpp src/Agent.cpp src/Agent.hpp src/Table.cpp src/Table.hpp src/Map.cpp src/Map.hpp)

target_link_libraries(ql sfml-graphics)