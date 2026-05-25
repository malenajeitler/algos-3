cmake_minimum_required(VERSION 4.0)
project(find_path)

set(CMAKE_CXX_STANDARD 20)

add_executable(find_path main.cpp
        Edge.cpp
        Edge.h
        Station.cpp
        Station.h
        Graph.cpp
        Graph.h)
