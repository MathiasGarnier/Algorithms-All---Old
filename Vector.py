# -*-coding:Latin-1 -*

try:

    from tkinter import Tk
    from tkinter import Canvas

except ImportError:

    print("Erreur lors de l'importation")

class Vector:

    def __init__(self):

        self.length = 0             #In centimeter
        self.way = {}               #way[0] = 'A', way[1] = 'B'
        self.direction = {}         #Direction exemple : A->B

    def vector2DDraw(self):

        self.way["first"] = 'A'
        self.way["second"] = 'B'

        self.direction["first"] = 'A'
        self.direction["second"] = 'B'

        self.length = 10

        print(self.direction)
        #A FINIR


def mainLoop():

    gui = Tk()


    MAX = 500

    canvas = Canvas(gui, width = MAX, height = MAX)

    o = canvas.create_line(MAX / 2, 0, MAX / 2, MAX) #Ordonnées
    a = canvas.create_line(0, MAX / 2, MAX, MAX / 2) #Abscisse
    nullP = canvas.create_text(243, 259, text = "0", fill = "red")

    canvas.pack()

    gui.mainloop()
