cmake_minimum_required(VERSION 3.23)
project(06_Try_it_out___Expression_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(06_Try_it_out___Expression_Tree
        ExpressionTree.h
        ExpressionTreeTest.cpp)
