# -*-coding:Latin-1 -*

from tkinter import *

MAX = 500

gui = Tk()

canvas = Canvas(gui, width = MAX, height = MAX)

o = canvas.create_line(MAX / 2, 0, MAX / 2, MAX) #Ordonnées
a = canvas.create_line(0, MAX / 2, MAX, MAX / 2) #Abscisse
nullP = canvas.create_text(243, 259, text = "0", fill = "red")

//@TODO A finir

canvas.pack()

gui.mainloop()
