#!/usr/bin/python

# Not at all a beautiful code

isValueAccepted = True
isFrench = False

while isValueAccepted:

	langage = str(input("Quel est votre langage ? "))

	if langage == "fr" or langage == "français":

		isFrench = True
		isValueAccepted = False

	elif langage == "en" or langage == "english":

		isFrench = False
		isValueAccepted = False

isValueAccepted = True

largeur = int(input("Largeur >> "))
longueur = int(input("Longueur >> "))

while isValueAccepted:

	if isFrench:

		unite = str(input("En quelle unité souhaitez vous obtenir le périmètre(m ou cm) >> "))

	else:

		unite = str(input("What is your unity(meter or kilometer) >> "))

	if unite == "m" or unite == "cm" or unite == "meter" or unite == "kilometer":

		isValueAccepted = False

if isFrench:

	print("Nous calculons le perimètre grâce à la formula (L + l) * 2")

else:

	print("We want to calculus the perimeter with this formula (L + l) * 2")

if unite == "m" or unite == "meter":

	perimetre = ((largeur + longueur) * 2)

else:

	perimetre = ((largeur + longueur) * 2) * 100

if isFrench:

	print("Perimetre >>", perimetre, unite)

else:

	print("Perimeter >>", perimetre, unite)
