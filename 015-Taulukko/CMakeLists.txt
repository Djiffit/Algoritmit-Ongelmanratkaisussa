cmake_minimum_required(VERSION 3.6)
project(15_Taulukko)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp herkoperk.cpp)
add_executable(15_Taulukko ${SOURCE_FILES})