import ast


def get_AST(expr):          # Must be used instead of the print_status statement
    return ast.dump(ast.parse(expr), indent=4)


class Symbol:

    def __init__(self, sym=None):
        # Pay attention, this system is very naive :
        # each symbol is unique, if I want to use two times
        # the same symbol I need to define it two different times
        self.symName = sym
        self.symType = type(sym)

        self.isVar = False
        self.isFunc = False

        self.value = sym

        # Nope, do not use this system !! USE AST !
        self.composedOf = [self]  # Must use copies ?
        #       self.composedName = self.symName  # Go POLISH NOTATION !!!
        #       But admit special rep for poly (for convenience)
        # Use expressions instead of composedNames ! An expression is just an AST of Symbols

    def print_status(self):
        # if len(self.composedOf) == 1 or str(self.symType) == '<class \'Polynomial.Polynomial\'>':
        print("Symbol : " + str(self.symName) + "\n\ttype : " + str(self.symType))
        print("\tVar : " + str(self.isVar) + ", Func : " + str(self.isFunc))
        # else:
        #    print("Symbol : {0}\n\tcomposed of : {1}".format(str(self.composedName), ''.join(
        #        [str(elm.symName) + ', ' for elm in self.composedOf])))
        #    print("\ttype : " + str(self.symType))
        #    print("\tVar : " + str(self.isVar) + ", Func : " + str(self.isFunc))

    def composedOfThose(self):
        return self.composedOf

    def implement_variable(self, var_name):
        # Can only implement_variable "at the beginning"
        if self.symName is None:
            self.isVar = True
            self.isFunc = False

            self.symName = var_name
            self.symType = type(self)  # ...

    def implement_function(self, fun_name):
        # Can implement_function using a previous expression containing symbols
        if self.symName is None or str(self.symType) == '<class \'Symbol.Symbol\'>':
            self.isVar = False
            self.isFunc = True

            self.symName = fun_name
            self.symType = type(self)

    def to_int(self):
        # print(type(self.symName))
        # if isinstance(self.symName, int):
        self.value = int(self.value)

    def to_real(self):
        # if self.symType is int:
        self.value = float(self.value)

    def get_value(self):
        return self.value

    def __add__(self, value):
        if value.isVar is True:
            self.isVar = False
            self.isFunc = True

        # if str(self.symType) == '<class \'Polynomial.Polynomial\'>':
        self.symName = "(" + str(self.symName) + "+" + str(value.symName) + ")"
        # else:
        #    self.composedName = "(+ " + str(self.composedName) + " " + str(value.symName) + ")"
        # self.symType = type(self) oops, never modify type !
        if value not in self.composedOf:
            self.composedOf.append(value)
        return self

    def __sub__(self, value):
        if value.isVar is True:
            self.isVar = False
            self.isFunc = True

        # if str(self.symType) == '<class \'Polynomial.Polynomial\'>':
        self.symName = "(" + str(self.symName) + "-" + str(value.symName) + ")"
        # else:
        #    self.composedName = "(- " + str(self.composedName) + " " + str(value.symName) + ")"
        self.symType = type(self)
        if value not in self.composedOf:
            self.composedOf.append(value)
        return self

    def __mul__(self, value):

        if isinstance(value, self.__class__):
            # if value.isVar is True:     # ???
            #    self.isVar = True

            # if str(self.symType) == '<class \'Polynomial.Polynomial\'>':
            self.symName = "(" + str(self.symName) + "*" + str(value.symName) + ")"
            # else:
            #    self.composedName = "(* " + str(self.composedName) + " " + str(value.symName) + ")"
            self.symType = type(self)
            if value not in self.composedOf:
                self.composedOf.append(value)
        elif isinstance(value, float):
            pass
        return self

    def __truediv__(self, value):
        # if value.isVar is True:
        #    self.isVar = True

        # if str(self.symType) == '<class \'Polynomial.Polynomial\'>':
        self.symName = "(" + str(self.symName) + "/" + str(value.symName) + ")"
        # else:
        #    self.composedName = "(/ " + str(self.composedName) + " " + str(value.symName) + ")"
        self.symType = type(self)
        if value not in self.composedOf:
            self.composedOf.append(value)
        return self

    def __pow__(self, power, modulo=None):
        # if power.isVar is True:
        #    self.isVar = True

        # if str(self.symType) == '<class \'Polynomial.Polynomial\'>':
        self.symName = "(" + str(self.symName) + "^" + str(power.symName) + ")"
        # else:
        #    self.composedName = "(^ " + str(self.composedName) + " " + str(power.symName) + ")"
        self.symType = type(self)
        if power not in self.composedOf:
            self.composedOf.append(power)
        return self

    def __lshift__(self, other):

        # dumb : if self.symType is type(self):  # Function or variable or expression involving symbol
        # if other.isVar is True:
        #    self.composedName = str(self.symName) + "(" + str(other.symName) + ")"
        # if other.isFunc is True:
        # Correct for composition of more than two func
        # Or just implement_func and apply x
        #     tmp_index = len(self.symName) - 2
        # print(other.symName)
        #     self.composedName = self.symName[:tmp_index] + other.symName + "(" + self.symName[tmp_index:] + ")"

        if self.isFunc is True:
            pass
        else:
            print("Need a function.")

        if other not in self.composedOf:
            self.composedOf.append(other)
        return self
