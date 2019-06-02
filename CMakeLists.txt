cmake_minimum_required (VERSION 2.6)
project(LeetCode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

add_library(LeetCode SHARED 1_Two_Sum.cpp 2_Add_Two_Numbers.cpp)