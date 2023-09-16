class Symbol:

    def __init__(self, sym=None):
        # Pay attention, this system is very naive :
        # each symbol is unique, if I want to use two times
        # the same symbol I need to define it two different times
        self.symName = sym
        self.symType = type(sym)

        self.isVar = False
        self.isFunc = False

        self.value = None

        self.composedOf = [self]

    def print_status(self):
        print("Symbol : " + str(self.symName) + "\n\ttype : " + str(self.symType))
        print("\tVar : " + str(self.isVar) + ", Func : " + str(self.isFunc))

    def composedOfThose(self):
        return self.composedOf

    def implement_variable(self, var_name):
        # Can only implement_variable "at the beginning"
        if self.symName is None:
            self.isVar = True

            self.symName = var_name
            self.symType = type(self)

    def implement_function(self, fun_name):
        # Can implement_function using a previous expression containing symbols
        if self.symName is None or str(self.symType) == '<class \'Symbol.Symbol\'>':
            self.isVar = False
            self.isFunc = True

            self.symName = fun_name
            self.symType = type(self)

    def to_int(self):
        print(type(self.symName))
        if isinstance(self.symName, int):
            self.value = int(self.symName)

    def get_value(self):
        return self.value

    def __add__(self, value):
        if value.isVar is True:
            self.isVar = False
            self.isFunc = True

        self.symName = "(" + str(self.symName) + "+" + str(value.symName) + ")"
        self.symType = type(self)
        self.composedOf.append(value)
        return self

    def __mul__(self, value):
        if value.isVar is True:
            self.isVar = True

        self.symName = "(" + str(self.symName) + "*" + str(value.symName) + ")"
        self.symType = type(self)
        self.composedOf.append(value)
        return self

    def __pow__(self, power, modulo=None):
        if power.isVar is True:
            self.isVar = True

        self.symName = "(" + str(self.symName) + "^" + str(power.symName) + ")"
        self.symType = type(self)
        self.composedOf.append(power)
        return self

    def __lshift__(self, other):

        if self.symType is type(self):  # Function or variable or expression involving symbol

            if other.isVar is True:
                self.symName = str(self.symName) + "(" + str(other.symName) + ")"
            if other.isFunc is True:
                # Correct for composition of more than two func
                # Or just implement_func and apply x
                tmp_index = len(self.symName) - 2
                print(other.symName)
                self.symName = self.symName[:tmp_index] + other.symName + "(" + self.symName[tmp_index:] + ")"

        self.composedOf.append(other)
        return self
