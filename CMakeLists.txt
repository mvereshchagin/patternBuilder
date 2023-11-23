cmake_minimum_required(VERSION 3.26)
project(createPatternsBuilder)

set(CMAKE_CXX_STANDARD 17)

add_executable(createPatternsBuilder main.cpp
        src/PlotBuilder.cpp
        headers/PlotBuilder.h)
