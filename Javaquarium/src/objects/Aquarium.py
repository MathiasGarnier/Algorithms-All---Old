from src.objects import Algue, Poisson
from random import randint
import warnings


class Aquarium:
	""" Un aquarium qui pourra être bien utile à monsieur Shingshan, aquariophile accompli. """

	temps: int
	nb_algues: int
	nb_poissons: int

	def __init__(self, nb_algues, nb_poissons):

		# Le nombre de "tours"
		self.temps = 0

		self.nb_algues = nb_algues
		self.nb_poissons = nb_poissons

		self.tab_algues = []
		self.tab_poissons = []

		for i in range(self.nb_algues):
			self.tab_algues.append(Algue.Algue(self, i, 0))

		for j in range(self.nb_poissons):
			self.tab_poissons.append(Poisson.Poisson(self, j, randint(0, 1), randint(0, 5), 0))

	def ajouter_algue(self, id_algue, age, pv):

		for i in range(self.nb_algues):
			if id_algue == self.tab_algues[i].get_algue_id():
				warnings.warn("Impossible d'ajouter une algue, l'id existe déjà.", UserWarning)

		self.tab_algues.append(Algue.Algue(self, id_algue, age, pv))
		self.nb_algues += 1

	def supprimer_algue(self, algue):

		if not isinstance(algue, Algue.Algue):
			warnings.warn("Impossible de supprimer cette algue, elle n'existe pas.", UserWarning)

		cdn, i = True, 0
		while cdn:
			if algue.get_algue_id() == self.tab_algues[i].get_algue_id():
				self.tab_algues.pop(i)
				cdn = False
			i += 1

		self.nb_algues -= 1

	def ajouter_poisson(self, id_poisson, sexe, race, age):

		for j in range(self.nb_poissons):
			if id_poisson == self.tab_poissons[j].get_poisson_id():
				warnings.warn("Impossible d'ajouter un poisson, l'id existe déjà.", UserWarning)

		self.tab_poissons.append(Poisson.Poisson(self, id_poisson, sexe, race, age))
		self.nb_poissons += 1

	def supprimer_poisson(self, poisson):

		if not isinstance(poisson, Poisson.Poisson):
			warnings.warn("Impossible de supprimer ce poisson, il n'existe pas.", UserWarning)

		cdn, i = True, 0
		while cdn:
			if poisson.get_poisson_id() == self.tab_poissons[i].get_poisson_id():
				self.tab_poissons.pop(i)
				cdn = False
			i += 1

		self.nb_poissons -= 1

	def voir(self):

		print("Nombre de poissons %d \nListe des poissons :" % self.nb_poissons)
		for j in range(self.nb_poissons):
			print("\tId : %d - Sexe : %d - Race : %d - Age : %d -- PV : %d" % (self.tab_poissons[j].get_poisson_id(),
			                                                                 self.tab_poissons[j].get_poisson_sexe(),
			                                                                 self.tab_poissons[j].get_poisson_race(),
			                                                                 self.tab_poissons[j].get_age(),
			                                                                 self.tab_poissons[j].get_pv()))
		print("Nombre d'algues %d \nListe des algues :" % self.nb_algues)
		for i in range(self.nb_algues):
			print("\tId : %d - Age : % d -- PV : %d" % (self.tab_algues[i].get_algue_id(),
			                                            self.tab_algues[i].get_age(),
			                                            self.tab_algues[i].get_pv()))

	def incrementer_temps(self):

		self.temps += 1

	def get_temps(self):

		return self.temps

	def get_nb_algues(self):

		return self.nb_algues

	def get_nb_poissons(self):

		return self.nb_poissons

	def get_poisson_liste(self):

		return self.tab_poissons

	def get_algue_liste(self):

		return self.tab_algues

	def sauvegarder(self, file):

		f = open(file, "a+")
		f.write("__----- TOUR %d -----__\n\n" % self.temps)
		f.write("Nombre de poissons %d \nListe des poissons :\n" % self.nb_poissons)
		for j in range(self.nb_poissons):
			f.write("\tId : %d - Sexe : %d - Race : %d - Age : %d -- PV : %d\n" % (self.tab_poissons[j].get_poisson_id(),
			                                                                       self.tab_poissons[j].get_poisson_sexe(),
			                                                                       self.tab_poissons[j].get_poisson_race(),
			                                                                       self.tab_poissons[j].get_age(),
			                                                                       self.tab_poissons[j].get_pv()))
		f.write("\nNombre d'algues %d \nListe des algues :\n" % self.nb_algues)
		for i in range(self.nb_algues):
			f.write("\tId : %d - Age : % d -- PV : %d\n" % (self.tab_algues[i].get_algue_id(),
			                                                self.tab_algues[i].get_age(),
			                                                self.tab_algues[i].get_pv()))
		f.close()
