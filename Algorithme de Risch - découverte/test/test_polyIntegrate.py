from Symbol import Symbol
from Symbol import get_AST
from Polynomial import Polynomial
from Functions import Function
from Functions import build_relation

nb_2 = Symbol(2)
nb_8 = Symbol(8)
nb_3 = Symbol(3)
nb_9 = Symbol(9)
nb_9b = Symbol(9)

poly1 = Polynomial([nb_2, nb_8, nb_3, nb_9, nb_9b])
# print(get_AST('Polynomial([nb_2, nb_8, nb_3, nb_9, nb_9b])'))
poly1.integrate()
print(poly1.get_coeffs())
