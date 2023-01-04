#include <iostream>
#include <cstdio>
#include "Game.h"

/*
 *
 * A FINIR UN JOUR OU L'AUTRE
 *
 * Cmake :
 *              cmake_minimum_required(VERSION 3.5)
 *              project(PetitJeuxDesFamilles)
 *
 *              set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 *
 *              set(SOURCE_FILES main.cpp Game.cpp Game.h)
 *              add_executable(PetitJeuxDesFamilles ${SOURCE_FILES} Game.cpp Game.h)
 *
 */

int main() {

    std::string playerName = "x";

    std::cout << "Bienvenue dans " << PetitJeuxDesFamilles::GAME_NAME << " !" << std::endl << "Quel est votre nom ?" << std::endl;

    std::cin >> playerName;
    getchar();

    std::cout << "Bienvenue " << playerName << "." << std::endl << "Ohhhhh il semblerait que vous soyez provoque en duel !" << std::endl << "Le duel peut commencer !" << std::endl;

    return 0;
}