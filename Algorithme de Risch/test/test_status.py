from Symbol import Symbol

f, g, h, i = Symbol(), Symbol(), Symbol(), Symbol()

x = Symbol()
x.implement_variable('x')
#x.print_status()

nb_2 = Symbol(2)
nb_3 = Symbol(3)
#nb_2.print_status()

fun_sin = Symbol()
fun_sin.implement_function('sin')

f = (nb_2 + x) + x
g = fun_sin << x

#f.print_status()
g.print_status()
f.implement_function('f')
#f.print_status()

h = g << f
h.print_status()
h.implement_function('h')

i = h << (h << x)
i.print_status()
