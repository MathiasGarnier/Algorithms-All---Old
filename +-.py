# -*-coding:Latin-1 -*

import random as rand

gameLoop = True
randomNum = rand.randrange(1000)

while gameLoop:

    print(randomNum)
    choice = int(input("Nombre choisi :"))

    if choice > randomNum: print("<")
    elif choice < randomNum: print(">")
    elif choice == randomNum: gameLoop = False

        
#VERSUS : new version : (beautiful :o but equals lolilolilol)

try:
    import random as rand
    import os

except ImportError:
    print("Please retry")
    os.system("PAUSE")

secret = rand.randrange(0, 100)
GAME_LOOP = True

while GAME_LOOP:

    choice = int(input())

    print(secret)

    if choice == secret: 
        print("WIN")
        GAME_LOOP = False

    elif secret > choice: print(">")
    elif secret < choice: print("<")
