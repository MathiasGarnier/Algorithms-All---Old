import matplotlib.pyplot as plt
import numpy as np 
import re

"""
Méthodes : 
    - Runge Kutta (4)
    - Nonlinear shooting
"""
def plot_solution(method):

    time = np.array([])
    value = np.array([])

    match_number = re.compile('-?\ *[0-9]+\.?[0-9]*(?:[Ee]\ *-?\ *[0-9]+)?')


    f = open(method + '.txt','r')
    for row in f:
        nb = re.findall(match_number, row)

        time = np.append(time, float(nb[0].strip()))
        value = np.append(value, float(nb[1].strip()))

    print(time)

    print()
    print()
    print()

    print(value)


    plt.plot(time, value)

    plt.savefig(method + '.png')

plot_solution('runge_kutta')
plot_solution('nonlinear_shooting')