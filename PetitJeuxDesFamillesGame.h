//
// Created by Mathias Garnier on 19/07/2016.
//

#ifndef PETITJEUXDESFAMILLES_GAME_H
#define PETITJEUXDESFAMILLES_GAME_H

#include <string>

unsigned int energieForAttack(std::string attackName);
bool isPlayerAttack();
void attack(std::string attackName); //attackName -> PetitJeuxDesFamilles::Attaques.
void defense(std::string defenseName); //defenseName -> PetitJeuxDesFamilles::Defense

class PetitJeuxDesFamilles {

    public:
        static constexpr char*  GAME_NAME = "PetitJeuxDesFamilles";
        static constexpr unsigned int MAX_ENERGIE = 80;
        static constexpr unsigned int MAX_LIFE = 100;
        static constexpr unsigned int MIN_LIFE = 0;

    class Attaques {

        public:
            static constexpr  char* ATTACK_NAME_qdf = "Queue de fer - 35 pv de degats, utilisation de 40 energies.";
            static constexpr char* ATTACK_NAME_l = "Lechouille - 30 pv de degats, utilisation de 20 energies.";
            static constexpr char* ATTACK_NAME_lcal = "La chatte a l'air - 25 pv de degats, utilisation de 10 energies.";
            static constexpr char* ATTACK_NAME_tltlcalv = "Toucher la, Toucher la chatte a la voisine - 30 pv de degats, utilisation de 20 energies.";

    };

    class Defense {

    public:
        static constexpr char* DEFENSE_NAME_c = "Carabistouille - 10 pv ajoute, utilisation de 30 energies.";
        static constexpr char* DEFENSE_NAME_is = "Infirmiere sexy - 15 pv ajoute, utilisation de 35 energies.";
        static constexpr char* DEFENSE_NAME_hc = "Hallucination collective - 20 pv ajoute, utilisation de 40 energies.";
        static constexpr char* DEFENSE_NAME_fhritp = "Fuck her right in the pussy - 15 pv ajoute, utilisation de 35 energies.";

    };
};


#endif //PETITJEUXDESFAMILLES_GAME_H
