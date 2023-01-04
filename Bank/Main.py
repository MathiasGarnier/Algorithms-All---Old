from Client import Client, ClientAccount, link
import random

def f():

    i = random.randint(0, 1001)

    if i % 2 == 0:
        return 100
    else:
        return -100

first = Client(12)
second = Client(211)
account0 = ClientAccount()
account1 = ClientAccount()

Russ = link(first, account0)
William = link(second, account1)

Running = True
while Running:

    William.__setattr__("sold", William.__getattribute__("sold") + f())
    Russ.__setattr__("sold", Russ.__getattribute__("sold") + f())

    if William.__getattribute__("sold") > Russ.__getattribute__("sold"):
        print("William is ahead({}) !".format(William.__getattribute__("sold")))
    elif William.__getattribute__("sold") == Russ.__getattribute__("sold"):
        print("William and Russ are tied.")
    else:
        print("Russ is ahead({}) !".format(Russ.__getattribute__("sold")))

    if William.__getattribute__("sold") == 1000 or Russ.__getattribute__("sold") == 1000:
        print("We've a winner !")
        Running = False

winner = "William" if William.__getattribute__("sold") > Russ.__getattribute__("sold") else "Russ"
print("The winner is : {}.".format(winner))