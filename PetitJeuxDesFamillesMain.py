# -*-coding:Latin-1 -*

import Utils

u = Utils
p = u.Player()

gameLoop = True

#Le joueur joue contre lui même x)

while gameLoop:

    p.choiceActionState()

    if p.life <= 0:

        u.stopGame()

    elif p.life > 20:

        print("Opération impossible.\nVeuillez essayer une autre option.")
        p.life = 20
        print("Refresh de la vie...\nVie restante :", p.life, ".")
        pass
