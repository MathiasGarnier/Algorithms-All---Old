cmake_minimum_required(VERSION 3.6)
project(cKeyProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES main.cpp Object/Key.cpp Object/Key.h Object/Place.cpp Object/Place.h Object/FileConfigurator.cpp Object/FileConfigurator.h)
add_executable(cKeyProject ${SOURCE_FILES} Object/Key.cpp Object/Key.h Object/Place.cpp Object/Place.h Object/FileConfigurator.cpp Object/FileConfigurator.h)