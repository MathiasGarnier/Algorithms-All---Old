//
// Created by Yapix on 13/11/2016.
//

#ifndef REEAPPRENTISSAGE_COMBAT_H
#define REEAPPRENTISSAGE_COMBAT_H

#include <iostream>

namespace Mj {

    class Attack {

        private:

            int HP;
            int enemyHP;

            int enemyAction;

            int yourReply;
            int reply;

            int SwordDamageHero;
            int FireDamageHero;
            int DaggerDamageHero;

            int SwordDamageEnemy;
            int FireDamageEnemy;
            int TridentDamageEnemy;

        public:

            void enemyAttack();
            void playerAttack();

            static int getMana();
    };
}
#endif //REEAPPRENTISSAGE_COMBAT_H
