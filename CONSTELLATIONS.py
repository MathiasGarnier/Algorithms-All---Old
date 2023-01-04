import random
import math
import matplotlib.pyplot as plt
import matplotlib.colors
import numpy as np
np.random.seed(19680801)

N = 1000

fig, ax = plt.subplots()
dots = np.arange(N)


# Ici, Grid est pas super utile
class Grid:

    def __init__(self, size_x, size_y):

        self.size_x, self.size_y = size_x, size_y
        self.grid = [[ random.randrange(0,N) for x in range(size_x)] for y in range(size_y)]
        
    def see(self):
        
        # https://stackoverflow.com/a/17871279
        print('\n'.join([''.join(['{:4}'.format(item) for item in row]) for row in self.grid]))

    def get(self):

        return self.grid
    
a = Grid(N,1)
b = Grid(N,1)

data = [a.get(), b.get()]

ax.scatter(*data, c=data[1])
ax.plot(a.get(), b.get())

def onclick_bt1(event):
    # check
    for it in range(N):
        # l'inférieur ou égal à ln(N) est pas trop dégueulasse, sauf quand N est trop petit ou beaucoup trop grand. N = 1000 et autour c'est pas dégueu
        if abs(round(event.xdata) - a.get()[0][it]) <= math.log(N) and abs(round(event.ydata) - b.get()[0][it]) <= math.log(N):
            print("TOUCHE")
    
points = list(zip(a.get(), b.get()))
# https://stackoverflow.com/a/60241070
def distance(a,b):
    return(sum([(k[0]-k[1])**2 for k in zip(a,b)])**0.5)
def onclick_bt2(event):
    dists = [distance([event.xdata, event.ydata],k) for k in points]
    print(sorted(dists[0])[1]) # pour avoir le deuxième plus petit élément (donc faut au moins deux éléments)


def get_nearest_point_distance(point):

    dists = []
    
    for j in range(0, len(points[0][0])):
            #print([points[0][0][j], points[0][1][j]])
            dists.append(distance([point[0], point[1]], [points[0][0][j], points[0][1][j]]))
    return(sorted(dists)[1]) # pour avoir le deuxième plus petit élément (donc faut au moins deux éléments)


# tres bruteforce :    
for i in range(0, N):
    #plt.plot(a.get()[i], b.get()[i])
    #print([a.get()[i][i], b.get()[i][i]])
    #print([a.get()[i][i+1], b.get()[i][i+1]])
    #print(distance([a.get()[i][i], b.get()[i][i]], [a.get()[i][i+1], b.get()[i][i+1]]))
    #print(get_nearest_point_distance([a.get()[i][i], b.get()[i][i]]))

    for j in range(0, N):
        #print(str(a.get()[i][j]) + " " + str(b.get()[i][j]))
        # print(distance([a.get()[i][j], b.get()[i][j]], [a.get()[i][j+1], b.get()[i][j+1]])) essai : ça marche ça (sauf que pb à la fin d'index)
        #dists = [distance([a.get()[i][j], b.get()[i][j]],k) for k in points]

        #print([a.get()[i][j], b.get()[i][j]])
        #print([a.get()[i][j+1], b.get()[i][j+1]])
        #print(distance([a.get()[i][j], b.get()[i][j]], [a.get()[i][j+1], b.get()[i][j+1]]))
        #print(get_nearest_point_distance([a.get()[i][j], b.get()[i][j]])) # GNE

        #print("hello")
        if distance([a.get()[0][i], b.get()[0][i]], [a.get()[0][j], b.get()[0][j]]) == get_nearest_point_distance([a.get()[0][i], b.get()[0][i]]):
            plt.plot([a.get()[0][i], a.get()[0][j]], [b.get()[0][i], b.get()[0][j]])
            print("ON EN A TROUVE UN")
        print("?3")


fig.canvas.mpl_connect('button_press_event', onclick_bt1)
fig.canvas.mpl_connect('button_press_event', onclick_bt2)

plt.show()
