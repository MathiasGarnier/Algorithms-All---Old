from Symbol import Symbol
from Polynomial import Polynomial
from Functions import Function

x = Symbol()
x.implement_variable('x')
one = Symbol(1)

sin = Function('sin')
cos = Function('cos')

sin.build_relation((sin * sin) << x + (cos * cos) << x - one)
