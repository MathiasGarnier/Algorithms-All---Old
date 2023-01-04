# -*-coding:Latin-1 -*

import random as rand
import os

def getMoney(money):

    return money

Loop = True

while Loop:

    addNewMoney = int(input())

    if addNewMoney > 100:
        Loop = False
        os.system("PAUSE")
        break

    solde = getMoney(int(addNewMoney + rand.randrange(50))) #Uniquement des entiers + la prime

    print(solde)
