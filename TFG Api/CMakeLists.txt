cmake_minimum_required(VERSION 3.5)
project(TFG_Api)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    crafting_recipe.cpp
    crafting_recipe.h
    item.cpp
    item.h
    item_stack.cpp
    item_stack.h
    main.cpp
    main.h
    player.cpp
    player.h
    server.cpp
    server.h
    world.cpp
    world.h)

add_executable(TFG_Api ${SOURCE_FILES})