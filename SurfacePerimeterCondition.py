#!/usr/bin/python

isValueAccepted = True

largeur = int(input("Largeur >> "))
longueur = int(input("Longueur >> "))

while isValueAccepted:

	unite = str(input("En quelle unité souhaitez vous obtenir le périmètre(m ou cm) >> "))

	if unite == "m" or unite == "cm":

		isValueAccepted = False

print("Nous calculons le perimètre grâce à la formula (L + l) * 2")

if unite == "m":

	perimetre = ((largeur + longueur) * 2)

else:

	perimetre = ((largeur + longueur) * 2) * 100

print("Perimetre >>", perimetre, unite)
