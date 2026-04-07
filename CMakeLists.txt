cmake_minimum_required(VERSION 4.2)
project(seatingPlan)

set(CMAKE_CXX_STANDARD 20)

add_executable(seatingPlan main.cpp
        seating_functions.cpp)