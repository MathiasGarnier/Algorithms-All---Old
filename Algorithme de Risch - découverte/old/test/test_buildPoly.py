from Symbol import Symbol
from Polynomial import Polynomial

x = Symbol()
x.implement_variable('x')

nb_2 = Symbol(2)
nb_3 = Symbol(3)
nb_8 = Symbol(8)
nb_9 = Symbol(9)
nb_9b = Symbol(9)
nb_9b.print_status()
nb_9b.to_int()

poly1 = Polynomial([nb_2, nb_8, nb_3, nb_9, nb_9b])

poly_2 = Polynomial()
poly_2.build_poly_from_coeffs([nb_2, nb_8, nb_3, nb_9, nb_9b])


nb_16 = Symbol(16)
nb_30 = Symbol(30)
nb_7058 = Symbol(7058)
nb_neg9 = Symbol(-9)
nb_90 = Symbol(90)
nb_13 = Symbol(13)
poly2 = Polynomial([nb_16, nb_30, nb_7058, nb_neg9, nb_90, nb_13])

poly3 = poly1 + poly2
