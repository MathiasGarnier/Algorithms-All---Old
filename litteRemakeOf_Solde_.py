try:
    import random as rand
    import os

except ImportError:
    print("Please retry.")

int_money = None
FIRST_PAY = rand.randrange(2000, 3000)
def getMoney():

    return int_money

def addMoney(nMoney):
    
    global int_money #Search int_money out of addMoney function

    nMoney = int(nMoney)
    newMoney = int_money + nMoney

    int_money = newMoney #Yeahhhh :3 That's OK. Used for add newMoney also on int_money variable !

    return newMoney

Loop = True

while Loop:

    int_money = FIRST_PAY

    print(getMoney()) #x
    print(addMoney(getMoney() * (2/4 * 3) - 1)) #x * (2/4 - 3) - 1
    print(getMoney()) #x * (2/4 - 3) - 1
    
    Loop = False #Don't forget !!
