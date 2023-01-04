class Algue:

	def __init__(self, aquarium, id_algue, age, pv=10):

		self.vie = pv
		self.age = age

		self.aquarium = aquarium
		self.id_algue = id_algue

	def get_algue_id(self):

		return self.id_algue

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

	def reproduction(self):

		if self.vie >= 10:
			self.aquarium.ajouter_algue(len(self.aquarium.tab_algues), 0, self.vie/2)
			self.aquarium.ajouter_algue(len(self.aquarium.tab_algues), 0, self.vie/2)
			self.vie /= 2
