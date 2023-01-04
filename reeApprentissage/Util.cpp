//
// Created by Yapix on 15/11/2016.
//

#include <cstdlib>
#include <time.h>
#include "Util.h"
#include "Attack.h"

namespace Util {

    int randomize(int maxValue) {

        srand(time(NULL));

        return (rand() % maxValue) + 1;
    }

    int addMana(int &x) {

        int _Mana = Mj::Attack::getMana();

        return _Mana += x;
    }

    int subMana(int &x) {

        int _Mana = Mj::Attack::getMana();

        return _Mana -= x;
    }

    void chooseAReply() {

        std::cout << "Choose a reply to your enemy attack!" << std::endl;
        std::cout << "1 - Dodge the attack" << std::endl;
        std::cout << "2 - Block the attack" << std::endl;
    }

    void chooseAttack() {

        std::cout << "You succesfully dodged your opponent attack , how do you want to reply to him?" << std::endl;
        std::cout << "1) Sword Smash" << std::endl;
        std::cout << "2) Fire Exploder (cost 20 MANA)" << std::endl;
        std::cout << "3) Sneaky Dagger" << std::endl;
        std::cout << "4) Regen (cost 50 MANA)" << std::endl;
        std::cout << "5) Draining (cost 100 MANA)" << std::endl;
    }
}