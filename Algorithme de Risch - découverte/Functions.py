from Symbol import Symbol


class Function(Symbol):

    def __init__(self, name):

        self.symName = name
        self.symType = '<class \'Functions.Function\'>'
        self.isVar = False
        self.isFunc = True

        self.composedOf = [self]
        # self.composedName = self.symName

        x = Symbol()
        x.implement_variable('x')
        self.fun = Symbol()
        self.fun.implement_function(self.symName)

        # self.print_status()


def build_relation(relation):
    # Eg. build_relation((sin * sin) << x + (cos * cos) << x - 1)   <=>   sin^2(x) + cos^2(x) - 1 = 0
    # print(str(type(relation)))
    assert(str(type(relation)) == '<class \'Functions.Function\'>')

    pass
