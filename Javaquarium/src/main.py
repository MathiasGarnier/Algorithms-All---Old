from random import randint
from src.objects import Aquarium

aqua = Aquarium.Aquarium(3, 10)
open("sauvegarde.poisson", "w").close()

enCoursDeRoute = True
while enCoursDeRoute:

	poisson_liste = aqua.get_poisson_liste()
	algue_liste = aqua.get_algue_liste()

	# On ajoute ou enlève des PV. Et met à jour l'âge. + Reproduction si possible.
	for a in algue_liste:

		a.ajouter_pv(1)
		a.reproduction()

	for b in poisson_liste:

		b.ajouter_pv(-1)
		b.ajouter_age(1)
		b.reproduction()

		# Changement sexe, hermaphrodite avec âge
		if b.b_est_herma_age() and b.get_age() == 10:
			b.changer_sexe()

		if not b.est_en_vie():
			aqua.supprimer_poisson(b)

	# Les poissons mangent.
	for k in poisson_liste:

		if ((len(poisson_liste) == 0) and (len(algue_liste) == 0)) or \
				(((len(poisson_liste) == 0) or (len(poisson_liste) == 1)) and (len(algue_liste) >= 0)):
			enCoursDeRoute = False
			if len(poisson_liste) == 1:
				aqua.supprimer_poisson(poisson_liste[0])  # On saute des tours en faisant ça, on supprime le dernier
			# poisson restant car dans tous les cas, il serait mort au bout d'un certain moment.
			# TODO Mettre à jour le compteur de tour du coup
		else:
			if randint(0, 1) == 0:
				k.manger(poisson_liste[randint(0, len(poisson_liste) - 1)])
			else:
				continuerAlg = True
				if len(algue_liste) != 0 and continuerAlg:
					k.manger(algue_liste[0 if len(algue_liste) == 1 else randint(0, len(algue_liste) - 1)])
				else:
					continuerAlg = False

	# Avant d'incrémenter le temps, on check l'état de notre aquarium.
	aqua.voir()
	aqua.sauvegarder("sauvegarde.poisson")
	# Dernière action à effectuer : on incrémente le temps. Un tour vient de se passer
	aqua.incrementer_temps()
	print("__----- TOUR %d -----__" % aqua.get_temps())
