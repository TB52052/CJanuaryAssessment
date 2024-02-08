cmake_minimum_required(VERSION 3.26)
project(GoingAgain)

set(CMAKE_CXX_STANDARD 17)

add_executable(GoingAgain main.cpp
        Gene.h
        GeneTest.cpp
        Gene.cpp
)
