from random import randint
import matplotlib.pyplot as plt
import time

def getRandomInteger():
    return randint(0, 3) + 1

BIteration = 1000000
RED     = 0 # id = 1
GREEN   = 0 # id = 2
YELLOW  = 0 # id = 3
BLUE    = 0 # id = 4
a = []

start_time = time.clock()

for i in range(BIteration):

    a.append(getRandomInteger())

RED    = a.count(1) / BIteration
GREEN  = a.count(2) / BIteration
YELLOW = a.count(3) / BIteration
BLUE   = a.count(4) / BIteration

print("Red\t\t-> \t", RED, "\nGreen\t-> \t", GREEN, "\nYellow\t-> \t", YELLOW,
      "\nBlue\t-> \t", BLUE, "\n",
      "Total : \t", RED + GREEN + YELLOW + BLUE, "/1.0\n",
      time.clock() - start_time, " seconds.")

x = [RED, GREEN, YELLOW, BLUE]

plt.bar(range(4), x)
plt.show()

