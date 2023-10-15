from Symbol import Symbol
from Symbol import get_AST
from Polynomial import Polynomial
from Functions import Function
from Functions import build_relation
from LaurentSeries import GetLaurentSeriesPP


# Most of the code must be refactored and redesigned !
# Really... really hard. Need an implementation of differential fields! 

nb_2 = Symbol(2)
nb_8 = Symbol(8)
nb_3 = Symbol(3)
nb_9 = Symbol(9)
nb_9b = Symbol(9)

poly1 = Polynomial([nb_2, nb_8, nb_3, nb_9, nb_9b])
# print(get_AST('Polynomial([nb_2, nb_8, nb_3, nb_9, nb_9b])'))
poly1.integrate()
# print(poly1.get_coeffs())

#  -2 + x + 4 x^2 - 2 x^3 - 2 x^4 + x^5
LS = GetLaurentSeriesPP(Polynomial([Symbol(36)]),
                        Polynomial([Symbol(-2), Symbol(1), Symbol(4), Symbol(-2), Symbol(-2), Symbol(1)]),
                        Polynomial([Symbol(-1), Symbol(0), Symbol(1)]),
                        2)
LS.generate()
