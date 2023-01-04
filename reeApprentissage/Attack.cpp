//
// Created by Yapix on 14/11/2016.
//

#include <cstdlib>
#include "Attack.h"
#include "Util.h"

namespace Mj {

    int Mj::Attack::getMana() {

        static int MANA(100);

        return MANA;
    }

    void Mj::Attack::playerAttack() {

        Util::chooseAReply;
        Util::chooseAttack;
    }

    void Mj::Attack::enemyAttack() {

        int n(10);
        int nS(50);
        int nE(20);

        int enemyChoice(Util::randomize(4)); // randomize(4)
        int chanceToBlock(Util::randomize(3)); //randomize(3)
        int chanceToDodge(Util::randomize(3)); //randomize(3)

        retry:
        switch (enemyChoice) {
                
            case 1:  //FIREBALL

                std::cout << "The enemy shoot fireballs at you!" << std::endl;            //ATTAQUE IA

                enemyAction = 1;

                Util::chooseAReply;

                std::cin >> yourReply;

                switch (yourReply) {

                    case 1 :   // DODGE SELECTED

                        if (chanceToDodge == 2) {

                            Util::chooseAttack;

                            std::cin >> reply;

                            switch (reply) {

                                case 1:

                                    std::cout << " You swing away with your sword!" << std::endl;

                                    enemyHP -= SwordDamageHero, Util::addMana(n);

                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 2:

                                    if (getMana() == 20) {

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;

                                        enemyHP -= FireDamageHero, Util::addMana(n);

                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << " You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;

                                    enemyHP -= DaggerDamageHero, Util::addMana(n);

                                    std::cout << "You are regening 10 mana , you now have " << getMana() << " mana." << std::endl;
                                    break;

                                case 4:

                                    if (getMana()> 50) {

                                        Util::subMana(nS), HP += 150, Util::addMana(n);

                                        std::cout << "You are regening 150 HP" << std::endl;

                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << " You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 5 :

                                    if (getMana()== 100) {

                                        std::cout << "You are draining enemy life" << std::endl;

                                        enemyHP -= 150, HP += 150, Util::addMana(n);

                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 100) {

                                        std::cout << " You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                default:

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    Util::addMana(n);

                                    break;
                            }

                        } else { //ELSE PART OF IA FIRE ATTACK

                            HP -= FireDamageEnemy;

                            std::cout << "You miss your dodge ";
                            std::cout << "the enemy burn you with his enchantment , you actually have " << HP << " HP"
                                      << std::endl;
                            std::cout << "You must respond to your enemy attack " << std::endl;
                            std::cout << "1) Sword Smash" << std::endl;
                            std::cout << "2) Fire Exploder (cost 20 MANA)" << std::endl;
                            std::cout << "3) Sneaky Dagger" << std::endl;
                            std::cout << "4) Regen (cost 50 MANA)" << std::endl;
                            std::cout << "5) Drainig (cost 100 MANA)" << std::endl;

                            std::cin >> reply;

                            switch (reply) {

                                case 1:

                                    std::cout << " You slice your enemy with your sword!" << std::endl;
                                    enemyHP -= SwordDamageHero;

                                    break;

                                case 2:

                                    if (getMana()> 20) {

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;

                                        Util::subMana(nE), Util::addMana(n), enemyHP -= FireDamageHero;

                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;

                                    enemyHP -= DaggerDamageHero, Util::addMana(n);

                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 4:

                                    if (getMana()> 50) {

                                        std::cout << "You are regening 150 HP" << std::endl;

                                        HP += 150, Util::addMana(n);

                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 5:

                                    if (getMana()== 100) {

                                        std::cout << "You are draining enemy life" << std::endl;

                                        enemyHP -= 75, HP += 75, Util::addMana(n);

                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 100) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }
                                    break;

                                default:

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    Util::addMana(n);

                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;
                                    break;
                            }

                        }
                        break;
                }
            case 2:

                if (chanceToBlock == 2) {

                    std::cout << "You succesfully blocked your opponent attack , how do you want to reply to him?"
                              << std::endl;

                } else {

                    HP -= FireDamageEnemy;

                    std::cout << "You miss your block";
                    std::cout << " the enemy burn you with his enchantment , you actually have " << HP << " HP"
                              << std::endl;
                    std::cout << "You must respond to your enemy attack !" << std::endl;
                    std::cout << "1) Sword Smash" << std::endl;
                    std::cout << "2) Fire Exploder (cost 20 MANA)" << std::endl;
                    std::cout << "3) Sneaky Dagger" << std::endl;
                    std::cout << "4) Regen (cost 50 MANA)" << std::endl;
                    std::cout << "5) Drainig (cost 100 MANA)" << std::endl;

                    std::cin >> reply;

                    switch (reply) {

                        case 1:

                            std::cout << " You slice your enemy with your sword!" << std::endl;

                            enemyHP -= SwordDamageHero, Util::addMana(n);

                            std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana." << std::endl;

                            break;

                        case 2:

                            if (getMana()> 20) {

                                std::cout << "You shoot a ton of fire out of your hands!" << std::endl;

                                Util::subMana(nE), Util::addMana(n), enemyHP -= FireDamageHero;

                                std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                          << std::endl;

                            } else if (getMana()< 20) {

                                std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                Mj::Attack::playerAttack();
                            }

                            break;

                        case 3:

                            std::cout << "You poke at the enemy with your dagger!" << std::endl;

                            enemyHP -= DaggerDamageHero, Util::addMana(n);

                            std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana." << std::endl;

                            break;

                        case 4:

                            if (getMana()> 50) {

                                std::cout << "You are regening 150 HP" << std::endl;

                                HP += 150, Util::addMana(n);

                                std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                          << std::endl;

                            } else if (getMana()< 50) {

                                std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                Mj::Attack::playerAttack();
                            }

                            break;

                        case 5 :

                            if (getMana()== 100) {

                                std::cout << "You are draining enemy life" << std::endl;

                                enemyHP -= 75, HP += 75, Util::addMana(n);

                                std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                          << std::endl;

                            } else if (getMana()< 100) {

                                std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                Mj::Attack::playerAttack();
                            }

                            break;

                        default:

                            std::cout << "You trip over your own feet and fall on the ground" << std::endl;
                            Util::addMana(n);

                            break;
                    }

                }
                break;

            case 3: //SWORD ONE

                std::cout << "The enemy run at you with his sword!" << std::endl;

                enemyAction = 2;

                Util::chooseAReply;

                std::cin >> yourReply;

                switch (yourReply) {

                    case 1:

                        if (chanceToDodge == 2) {

                            Util::chooseAttack;

                            std::cin >> reply;
                            std::cout << reply << std::endl;

                            switch (reply) {

                                case 1:

                                    std::cout << " You slice your enemy with your sword!" << std::endl;

                                    enemyHP -= SwordDamageHero;

                                    break;

                                case 2:

                                    if (getMana()> 20) {

                                        Util::subMana(nE), Util::addMana(n), enemyHP -= FireDamageHero;

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    enemyHP -= DaggerDamageHero, Util::addMana(n);

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;
                                    break;

                                case 4:

                                    if (getMana()> 50) {

                                        HP += 150, Util::addMana(n);

                                        std::cout << "You are regening 150 HP" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 5:

                                    if (getMana()== 100) {

                                        enemyHP -= 75, HP += 75, Util::addMana(n);

                                        std::cout << "You are draining enemy life" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 100) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                default:

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    Util::addMana(n);

                                    break;
                            }

                        } else {

                            HP -= SwordDamageEnemy;

                            std::cout << "You miss your dodge , ";
                            std::cout << "The enemy slice you , you lose some life you actually have " << HP << " HP"
                                      << std::endl;
                            std::cout << "You must respond to your opponent attack" << std::endl;
                            std::cout << "1) Sword Smash" << std::endl;
                            std::cout << "2) Fire Exploder (cost 20 MANA)" << std::endl;
                            std::cout << "3) Sneaky Dagger" << std::endl;
                            std::cout << "4) Regen (cost 50 MANA)" << std::endl;
                            std::cout << "5) Drainig (cost 100 MANA)" << std::endl;

                            std::cin >> reply;
                            std::cout << reply << std::endl;

                            switch (reply) {

                                case 1:

                                    enemyHP -= SwordDamageHero, Util::addMana(n);

                                    std::cout << " You slice your enemy with your sword!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;
                                    break;

                                case 2:

                                    if (getMana()> 20) {

                                        Util::subMana(nE), Util::addMana(n), enemyHP -= FireDamageHero;

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    enemyHP -= DaggerDamageHero, Util::addMana(n);

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 4:

                                    if (getMana()> 50) {

                                        HP += 150, Util::addMana(n);

                                        std::cout << "You are regening 150 HP" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 5:

                                    if (getMana() == 100) {

                                        enemyHP -= 75, HP += 75, Util::addMana(n);

                                        std::cout << "You are draining enemy life" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 100) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }
                                    break;

                                default:

                                    Util::addMana(n);

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    break;
                            }
                        }
                        break;

                    case 2:
                        if (chanceToBlock == 2) {

                            Util::chooseAttack;

                            std::cin >> reply;
                            std::cout << reply << std::endl;

                            switch (reply) {

                                case 1:

                                    enemyHP -= SwordDamageHero, Util::addMana(n);

                                    std::cout << " You slice your enemy with your sword!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 2:

                                    if (getMana()> 20) {

                                        Util::subMana(nE), Util::addMana(n), enemyHP -= FireDamageHero;

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    enemyHP -= DaggerDamageHero, Util::addMana(n);

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 4:

                                    if (getMana()> 50) {

                                        HP += 150, Util::addMana(n);

                                        std::cout << "You are regening 150 HP" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 5:

                                    if (getMana()== 100) {

                                        enemyHP -= 75, HP += 75, Util::addMana(n);

                                        std::cout << "You are draining enemy life" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 100) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                default:

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    Util::addMana(n);

                                    break;
                            }

                        } else {

                            HP -= SwordDamageEnemy;

                            std::cout << "You miss your block";
                            std::cout << "The enemy slice you , you lose some life you actually have " << HP << " HP"
                                      << std::endl;
                            std::cout << "You must respond to your opponent attack" << std::endl;
                            std::cout << "1) Sword Smash" << std::endl;
                            std::cout << "2) Fire Exploder (cost 20 MANA)" << std::endl;
                            std::cout << "3) Sneaky Dagger" << std::endl;
                            std::cout << "4) Regen (cost 50 MANA)" << std::endl;
                            std::cout << "5) Drainig (cost 100 MANA)" << std::endl;

                            std::cin >> reply;
                            std::cout << reply << std::endl;

                            switch (reply) {

                                case 1:

                                    enemyHP -= SwordDamageHero, Util::addMana(n);

                                    std::cout << " You swing away with your sword!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 2:

                                    if (getMana()> 20) {


                                        Util::subMana(nE), Util::addMana(n), enemyHP -= FireDamageHero;

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    enemyHP -= DaggerDamageHero, Util::addMana(n);

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 4:

                                    if (getMana()> 50) {

                                        HP = HP + 150, Util::addMana(n);

                                        std::cout << "You are regening 150 HP" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 5:

                                    if (getMana()== 100) {


                                        enemyHP -= 75, HP += 75, Util::addMana(n);

                                        std::cout << "You are draining enemy life" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 100) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                default:

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    Util::addMana(n);

                                    break;

                            }
                        }
                        break;

                }
                break;

            case 4: // TRIDENT ONE

                std::cout << "The enemy disapears to reapears next to you with his trident!" << std::endl;

                enemyAction = 3;

                Util::chooseAReply;

                std::cin >> yourReply;

                switch (yourReply) {

                    case 1:

                        if (chanceToDodge == 2) {

                            Util::chooseAttack;

                            std::cin >> reply;
                            std::cout << reply << std::endl;

                            switch (reply) {

                                case 1:

                                    enemyHP -= SwordDamageHero, Util::addMana(n);

                                    std::cout << " You swing away with your sword!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 2:

                                    if (getMana()> 20) {

                                        Util::subMana(nE), Util::addMana(n), enemyHP -= FireDamageHero;

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    enemyHP -= DaggerDamageHero, Util::addMana(n);

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 4:

                                    if (getMana()> 50) {

                                        HP += 150, Util::addMana(n);

                                        std::cout << "You are regening 150 HP" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();

                                    }

                                    break;

                                case 5:

                                    if (getMana() == 100) {

                                        enemyHP -= 75, HP += 75, Util::addMana(n);

                                        std::cout << "You are draining enemy life" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;
                                    } else if (getMana()< 100) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }
                                    break;

                                default:

                                    Util::addMana(n);

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    break;
                            }
                        } else {

                            HP -= TridentDamageEnemy;

                            std::cout << "You miss your dodge";
                            std::cout << "The enemy hit you with his trident , you lose some life you actually have "
                                      << HP
                                      << " HP" << std::endl;
                            std::cout << "You must respond to your opponent attack" << std::endl;
                            std::cout << "1) Sword Smash" << std::endl;
                            std::cout << "2) Fire Exploder (cost 20 MANA)" << std::endl;
                            std::cout << "3) Sneaky Dagger" << std::endl;
                            std::cout << "4) Regen (cost 50 MANA)" << std::endl;
                            std::cout << "5) Drainig (cost 100 MANA)" << std::endl;

                            std::cin >> reply;
                            std::cout << reply << std::endl;

                            switch (reply) {

                                case 1:

                                    std::cout << " You swing away with your sword!" << std::endl;

                                    enemyHP -= SwordDamageHero, Util::addMana(n);

                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 2:

                                    if (getMana()> 20) {

                                        Util::subMana(nE), Util::addMana(n), enemyHP -= FireDamageHero;

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    enemyHP -= DaggerDamageHero, Util::addMana(n);

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 4:

                                    if (getMana()> 50) {

                                        HP += 150, Util::addMana(n);

                                        std::cout << "You are regening 150 HP" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();

                                    }

                                    break;
                                case 5:

                                    if (getMana() == 100) {


                                        enemyHP -= 75, HP += 75, Util::addMana(n);

                                        std::cout << "You are draining enemy life" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 100) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }
                                    break;

                                default:

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    Util::addMana(n);

                                    break;
                            }
                        }
                        break;


                    case 2:

                        if (chanceToBlock == 2) {

                            Util::chooseAttack;

                            std::cin >> reply;
                            std::cout << reply << std::endl;

                            switch (reply) {

                                case 1:

                                    enemyHP -= SwordDamageHero, Util::addMana(n);

                                    std::cout << " You swing away with your sword!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 2:
                                    if (getMana()> 20) {

                                        Util::subMana(nE), enemyHP -= FireDamageHero, Util::addMana(n);

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    enemyHP -= DaggerDamageHero, Util::subMana(nS);

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 4:

                                    if (getMana()> 50) {

                                        HP += 150, Util::subMana(nS), Util::addMana(n);

                                        std::cout << "You are regening 150 HP" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 5 :

                                    if (getMana()== 100) {


                                        enemyHP -= 75, HP += 5, Util::addMana(n);

                                        std::cout << "You are draining enemy life" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 100) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                default :

                                    Util::addMana(n);

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    break;
                            }

                        } else {
                            HP -= TridentDamageEnemy;

                            std::cout << "You miss your block";
                            std::cout << "The enemy hit you with his trident , you lose some life you actually have "
                                      << HP
                                      << " HP" << std::endl;
                            std::cout << "You must respond to your opponent attack" << std::endl;
                            std::cout << "1) Sword Smash" << std::endl;
                            std::cout << "2) Fire Exploder (cost 20 MANA)" << std::endl;
                            std::cout << "3) Sneaky Dagger" << std::endl;
                            std::cout << "4) Regen (cost 50 MANA)" << std::endl;
                            std::cout << "5) Drainig (cost 100 MANA)" << std::endl;

                            std::cin >> reply;
                            std::cout << reply << std::endl;

                            switch (reply) {

                                case 1:

                                    enemyHP -= SwordDamageHero, Util::addMana(n);

                                    std::cout << " You swing away with your sword!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 2:

                                    if (getMana()> 20) {

                                        Util::subMana(nS), enemyHP -= FireDamageHero, Util::addMana(n);

                                        std::cout << "You shoot a ton of fire out of your hands!" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 20) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 3:

                                    enemyHP -= DaggerDamageHero, Util::addMana(n);

                                    std::cout << "You poke at the enemy with your dagger!" << std::endl;
                                    std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                              << std::endl;

                                    break;

                                case 4:

                                    if (getMana() > 50) {

                                        HP += 150, Util::addMana(n);

                                        std::cout << "You are regening 150 HP" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 50) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }

                                    break;

                                case 5:

                                    if (getMana()== 100) {

                                        enemyHP -= 75, HP += 75, Util::addMana(n);

                                        std::cout << "You are draining enemy life" << std::endl;
                                        std::cout << "You are regening 10 mana , you now have " << getMana()<< " mana."
                                                  << std::endl;

                                    } else if (getMana()< 100) {

                                        std::cout << "You don\'t have enought mana to make this attack" << std::endl;
                                        Mj::Attack::playerAttack();
                                    }
                                    break;

                                default:

                                    Util::addMana(n);

                                    std::cout << "You trip over your own feet and fall on the ground" << std::endl;

                                    break;
                            }
                        }
                        break;
            case 5: //ENEMY ATTACK MISSED

                enemyAction = 4;

                std::cout << "The enemy miss his attack" << std::endl;

                Mj::Attack::playerAttack();

                break;

            default:

                std::cout << "Retry";

                goto retry;
            }
        }
    }
}