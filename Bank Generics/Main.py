from Client import generate_client
from random import randint

SCORE_TO_REACH = 1e3
NB_CLIENT = 100

def f():

    i = randint(0, 1001)

    if i % 2 == 0:
        return 100
    else:
        return -100

a = generate_client(NB_CLIENT)
counter = 0

Running = True
while Running:

    for it in range(NB_CLIENT):
        a[it].sold += f()

        print("Client number {} have got {}$.".format(a[it].clientID, a[it].sold))

    for it in range(NB_CLIENT):
        if a[it].sold >= SCORE_TO_REACH:
            print("We've a winner ! This is client number : {}. (He needed {} steps.)".format(a[it].clientID, counter))
            Running = False

    counter += 1