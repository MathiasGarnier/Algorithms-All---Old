from random import randint
import warnings
from src.objects import Algue


class Poisson:

	def __init__(self, aquarium, id_poisson, sexe_poisson, race_poisson, age):

		self.aquarium = aquarium  # Si multiples.
		self.vie = 10
		self.age = age

		self.id_poisson = id_poisson
		# Si sexe_poisson = 0 : femelle, 1 : male
		self.sexe_poisson = sexe_poisson
		# 0 : Mérou, 1 : Thon, 2 : Poisson-Clown, 3 : Sole, 4 : Bar, 5 : Carpe
		self.race_poisson = race_poisson
		self.est_carnivore = race_poisson == 0 or race_poisson == 1 or race_poisson == 2
		self.est_herbivore = not self.est_carnivore

		self.est_monosexue = (self.race_poisson == 5) or (self.race_poisson == 1)
		self.est_herma_age = (self.race_poisson == 4) or (self.race_poisson == 0)
		self.est_herma_opport = (self.race_poisson == 3) or (self.race_poisson == 2)

	def get_poisson_id(self):

		return self.id_poisson

	def get_poisson_sexe(self):

		return self.sexe_poisson

	def changer_sexe(self):

		if self.sexe_poisson == 0:
			self.sexe_poisson = 1
		else:
			self.sexe_poisson = 0

	def get_poisson_race(self):

		return self.race_poisson

	def manger(self, cible):

		if (not isinstance(cible, Poisson)) and (not isinstance(cible, Algue.Algue)):
			warnings.warn("La cible ne peut pas être mangée (n'étant ni un Poisson ni une Algue).", UserWarning)

		if self.vie <= 5:
			if isinstance(cible, Algue.Algue) and self.est_herbivore:
				self.vie += 3
				cible.ajouter_pv(-2)
				if not cible.est_en_vie():
					self.aquarium.supprimer_algue(cible)
			if isinstance(cible, Poisson) and self.est_carnivore and (self.race_poisson != cible.get_poisson_race()):
				self.vie += 5
				cible.ajouter_pv(-4)
				if not cible.est_en_vie():
					self.aquarium.supprimer_poisson(cible)

	def reproduction(self):

		if self.vie > 5:
			ss_repr = randint(0, self.aquarium.get_nb_poissons() - 1)
			vers = self.aquarium.get_poisson_liste()[ss_repr]
			if (self != vers) and (self.race_poisson == vers.get_poisson_race()):
				if self.sexe_poisson != vers.get_poisson_sexe():
					self.aquarium.ajouter_poisson(len(self.aquarium.get_poisson_liste()), randint(0, 1),
					                              self.get_poisson_race(), 0)
				if (self.sexe_poisson == vers.get_poisson_sexe()) and self.b_est_herma_opport():
					self.aquarium.ajouter_poisson(len(self.aquarium.get_poisson_liste()), randint(0, 1),
					                              self.get_poisson_race(), 0)

	def est_en_vie(self):

		if self.vie >= 1 and self.age < 20:
			return True
		else:
			return False

	def ajouter_pv(self, inc):

		self.vie += inc

	def get_pv(self):

		return self.vie

	def ajouter_age(self, inc):

		self.age += inc

	def get_age(self):

		return self.age

	def b_est_monosexue(self):

		return self.est_monosexue

	def b_est_herma_age(self):

		return self.est_herma_age

	def b_est_herma_opport(self):

		return self.est_herma_opport
