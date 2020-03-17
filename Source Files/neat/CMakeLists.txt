cmake_minimum_required(VERSION 3.15)
project(Project1)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS graphics REQUIRED)

add_executable(Project1 src/main.cpp src/Agent.cpp src/Agent.hpp src/Brain.cpp src/Brain.hpp src/Layers.cpp src/Layers.hpp src/Map.cpp src/Map.hpp)

target_link_libraries(Project1 sfml-graphics)