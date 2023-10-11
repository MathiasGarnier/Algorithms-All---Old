from Symbol import Symbol
from Polynomial import Polynomial
from Functions import Function
from Functions import build_relation

x = Symbol()
x.implement_variable('x')
one = Symbol(1)
two = Symbol(2)

sin = Function('sin')
cos = Function('cos')


t = (sin**two + cos - sin)**two + one
t.print_status()

build_relation(t - one)

nb_2 = Symbol(2)
nb_3 = Symbol(3)
nb_8 = Symbol(8)
nb_9 = Symbol(9)
nb_9b = Symbol(9)

poly1 = Polynomial([nb_2, nb_8, nb_3, nb_9, nb_9b])
