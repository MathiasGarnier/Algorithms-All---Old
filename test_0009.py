import os
import random       #For random.randrange
import math         #For math.ceil

money = 100
nb_bet = 0
mise = 0
rand = random.randrange(50)

print("Bienvenue chez Zcasino !")
print("Vous avez ", money, " euros !")

print("Misez sur un nombre (compris entre 0 et 49: ")
nb_bet = input()
nb_bet = int (nb_bet)
print("Somme de la mise sur ", nb_bet, " :")
mise = input()
mise = int (mise)

nb_bet = int(nb_bet)
if nb_bet >= 0 and nb_bet <= 49:

    if nb_bet == rand:
        print("Bravo vous gagnez !")
        mise = mise * 2
        print("Vous avez : ", mise)

    else:
        print("Domage... Retentez votre chance une prochaine fois :p !")
        mise = money - (math.ceil(mise) / 2)
        print("Il vous reste :", mise)
        
else:
    os.system("pause")
