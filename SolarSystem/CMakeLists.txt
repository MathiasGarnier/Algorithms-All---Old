cmake_minimum_required(VERSION 3.6)
project(SolarSystem___API)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Planet.cpp Planet.h Satellite.cpp Satellite.h)
add_executable(SolarSystem___API ${SOURCE_FILES} Planet.cpp Planet.h Satellite.cpp Satellite.h)