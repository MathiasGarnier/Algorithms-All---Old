//
// Created by Yapix on 16/05/2016.
//
#include <iostream>
#include <cstdio>

#include "Menu.h"

void Menu::start() {

    std::cout << "Lancement..." << std::endl;
    Menu::selectMenu(/*SELECT OPTION*/);
}
void Menu::selectMenu()
{
    char menuOption;

    std::wcout << "Veuillez choisir una catégorie, parmis celle proposée :" << std::endl;
    menuOption = getchar();


    switch(menuOption){

        case 'M':
            std::cout << "Vous avez choisi : Math." << std::endl;

    }
}