# -*-coding:Latin-1 -*

import os

class Player:

    """
    :param: MAX_LIFE                        - Equals to 20.
            life                            - Dynamic variable for player level of life.

    :function:  getPlayerLife               - Get the Player life level (between 0 and 20).
                takeDamage                  - Decreases the player life level by damage level.
                selectAttack                - Select an attack to used it versus the ai.
    """

    def __init__(self):

        self.MAX_LIFE = 20 #Life when game start
        self.life = self.MAX_LIFE

    def takeDamage(self, damage):   #Return new player level of life.

        self.life -= damage

        return  self.life

    def addLife(self, num):

        self.life += num

        return self.life

    def attack(self):

        print("Choisi(e) ton attaque parmis les suivantes (veuillez utiliser les alias des attaques):")
        for i in attackList.values():
            print(i)

        choice = str(input())

        if choice == "1":

            print("Vie restante :", Player.takeDamage(self, 4), ".")

        elif choice == "2":

            print("Vie restante :", Player.takeDamage(self, 3), ".")

        elif choice == "3":

            print("Vie restante :", Player.takeDamage(self, 3), ".")

        elif choice == "4":

            print("Vie restante :", Player.takeDamage(self, 4), ".")

    def defense(self):

        print("Choisi(e) ton attaque de défense parmis les suivantes (veuillez utiliser les alias des défenses): ")

        for i in defenseList.values():
            print(i)

        choice = str(input())

        if choice == "1":

            print("Vie restante :", Player.addLife(self, 2), ".")

        elif choice == "2":

            print("Vie restante :", Player.addLife(self, 3), ".")

        elif choice == "3":

            print("Vie restante :", Player.addLife(self, 4), ".")

        elif choice == "4":

            print("Vie restante :", Player.addLife(self, 3), ".")

    def choiceActionState(self):

        choice = str(input("Veuillez choisir votre action parmis \"Attaque\" et \"Défense\": "))

        if choice == "Attaque":

            Player.attack(self)

        elif choice == "Défense":

            Player.defense(self)

        else:

            print("Essayez autre chose.")
            Player.choiceActionState(self)

#@TODO Make artificial intelligence

attackList = dict()
attackList[0] = "Queue de fer - 4 pv de degats, alias 1."
attackList[1] = "Léchouille - 3 pv de degats, alias 2."
attackList[2] = "La chatte à l'air - 3 pv de degats, alias 3."
attackList[3] = "Toucher la, Toucher la chatte à la voisine - 4 pv de degats, alias 4."

defenseList = dict()
defenseList[0] = "Carabistouille - Ajoute 2 pv, alias 1."
defenseList[1] = "Infirmière sexy - Ajoute 3 pv, alias 2."
defenseList[2] = "Hallucination collective - Ajoute 4 pv, alias 3."
defenseList[3] = "Fuck her right in the pussy - Ajoute 3 pv, alias 4."

def stopGame():
    print("Game over.")
    os._exit(1)
