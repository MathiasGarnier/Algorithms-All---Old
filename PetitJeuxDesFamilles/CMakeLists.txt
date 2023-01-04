cmake_minimum_required(VERSION 3.5)
project(PetitJeuxDesFamilles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game.cpp Game.h)
add_executable(PetitJeuxDesFamilles ${SOURCE_FILES} Game.cpp Game.h)