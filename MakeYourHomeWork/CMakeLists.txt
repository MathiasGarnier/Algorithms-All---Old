cmake_minimum_required(VERSION 3.5)
project(MakeYourHomeWork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Menu.cpp Menu.h)
add_executable(MakeYourHomeWork ${SOURCE_FILES})