from Symbol import Symbol

f, g = Symbol(), Symbol()

x = Symbol()
x.implement_variable('x')

nb_2 = Symbol(2)
nb_3 = Symbol(3)
nb_2.print_status()
fun_sin = Symbol()
fun_sin.implement_function('sin')

f = (nb_2 + x) + x
g = f + (fun_sin << x) + nb_3

for i in g.composedOfThose():
    print(i.symName)