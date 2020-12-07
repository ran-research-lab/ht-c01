cmake_minimum_required(VERSION 3.17)
project(graph)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(graph
        HashTable.cpp
        HashTable.h
        main.cpp
        catch_amalgamated.cpp)
