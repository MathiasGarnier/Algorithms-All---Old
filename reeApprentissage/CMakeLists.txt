cmake_minimum_required(VERSION 3.6)
project(reeApprentissage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Attack.h Attack.cpp Util.cpp Util.h)
add_executable(reeApprentissage ${SOURCE_FILES} Attack.cpp Util.cpp Util.h)