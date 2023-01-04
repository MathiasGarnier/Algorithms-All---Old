# -*-coding:Latin-1 -*

import math

MAX = 35
i = 0
result = 0

float_phi = (1 + math.sqrt(5)) / 2
float_phiPrime = -(1 / float_phi)

def fibo(n):

    return 1 / math.sqrt(5) * (math.pow(float_phi, n) - math.pow(float_phiPrime, n))

while i < MAX:

    result += fibo(i)

    print(result)
    i += 1
    if i == MAX:
        print(1.0 + 2.0 + 4.0 + 7.0 + 12.0 + 20.0 + 33.0 + 54.0 + 88.0 + 143.0 + 232.0 + 376.0 + 609.0 + 986.0 + 1596.0 + 2583.0 + 4180.0 + 6764.0 + 10945.0 + 17710.0 + 28656.0 + 46367.0 + 75024.0 + 121392.0+ 196417.0 + 317810.0 + 514228.0 + 832039.0 + 1346268.0 + 2178308.0 + 3524577)
