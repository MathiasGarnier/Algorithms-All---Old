import math, random
import matplotlib.pyplot as plt
import numpy as np

N, NB_POINTS = 1, 1000

fig, ax = plt.subplots()
dots = np.arange(N)
data = [[random.uniform(0, N) for idx in range(NB_POINTS)], [random.uniform(0, N) for idx in range(NB_POINTS)]]

ax.scatter(*data, c=data[1])

def get_nearest_point_distance(point):
    dists = []
    for j in range(0, len(data[0])):
        dists.append([((point[0] - data[0][j])**2 + (point[1] - data[1][j])**2)**(1/2), data[0][j], data[1][j]])
    return(sorted(dists)[1]) # avoir le deuxième plus petit élément (par ce que le premier c'est lui même)

for i in range(0, NB_POINTS):
    nearest = get_nearest_point_distance([data[0][i], data[1][i]])
    plt.plot([data[0][i], nearest[1]], [data[1][i], nearest[2]])
plt.show()
