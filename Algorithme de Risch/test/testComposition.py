from Symbol import Symbol

x = Symbol()
x.implement_variable('x')

nb_2 = Symbol(2)
nb_3 = Symbol(3)

fun_sin, g = Symbol(), Symbol()
fun_sin.implement_function('sin')

g = fun_sin << (x + (nb_2 * nb_3))
g.implement_function('g')
