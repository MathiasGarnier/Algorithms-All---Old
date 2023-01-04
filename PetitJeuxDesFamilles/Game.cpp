//
// Created by Mathias Garnier on 19/07/2016.
//

#include "Game.h"
namespace Game {
    static unsigned int playerLife = PetitJeuxDesFamilles::MAX_LIFE;
    unsigned int enemyLife = PetitJeuxDesFamilles::MAX_LIFE;

    unsigned int playerEnergie = PetitJeuxDesFamilles::MAX_ENERGIE;
    unsigned int enemyEnergie = PetitJeuxDesFamilles::MAX_ENERGIE;
}
unsigned int energieForAttack(std::string attackName) {

    if ((attackName == PetitJeuxDesFamilles::Attaques::ATTACK_NAME_l) && (Game::playerEnergie >= 40)) {
        return 40;
    } else if ((attackName == PetitJeuxDesFamilles::Attaques::ATTACK_NAME_l) && (Game::playerEnergie >= 20)) {
        return 20;
    } else if ((attackName == PetitJeuxDesFamilles::Attaques::ATTACK_NAME_l) && (Game::playerEnergie >= 10)) {
        return 10;
    } else if ((attackName == PetitJeuxDesFamilles::Attaques::ATTACK_NAME_l) && (Game::playerEnergie >= 20)) {
        return 20;
    } else {
        return 0;
    }
}

void attack(std::string attackName) {

    while ((Game::enemyLife >= PetitJeuxDesFamilles::MIN_LIFE + 1) && (Game::playerEnergie >= energieForAttack(attackName))) {

        if (attackName == PetitJeuxDesFamilles::Attaques::ATTACK_NAME_l) {
            Game::enemyLife -= 35;
            Game::playerEnergie -= 40;
        } else if (attackName == PetitJeuxDesFamilles::Attaques::ATTACK_NAME_lcal) {
            Game::enemyLife -= 30;
            Game::playerEnergie -= 20;
        } else if (attackName == PetitJeuxDesFamilles::Attaques::ATTACK_NAME_qdf) {
            Game::enemyLife -= 25;
            Game::playerEnergie -= 10;
        } else if (attackName == PetitJeuxDesFamilles::Attaques::ATTACK_NAME_tltlcalv) {
            Game::enemyLife -= 30;
            Game::playerEnergie -= 20;
        }
    }
}

void defense(std::string defenseName) {

}