from Symbol import Symbol


class Polynomial(Symbol):

    def __init__(self, coeffs=None):

        self.poly = Symbol()
        self.poly.implement_function('P')
        # self.symName = ""
        #self.poly.symType = '<class \'Polynomial.Polynomial\'>'

        self.composedOf = [self]
        # self.composedName = self.symName

        # coeffs must have a symbol type
        self.coeffs = coeffs

        if coeffs is not None:
            self.poly = coeffs[0]
            for i in range(1, len(coeffs)):
                x = Symbol()                    # different but the same...
                x.implement_variable('x')
                power = Symbol(i)
                self.poly += coeffs[i] * (x ** power)
            self.symX = x
            self.poly.print_status()
        else:
            self.poly = None

    def build_poly_from_coeffs(self, coeffs):

        self.coeffs = coeffs
        self.poly = Symbol()
        self.poly = coeffs[0]
        for i in range(1, len(coeffs)):
            x = Symbol()                    # different but the same...
            x.implement_variable('x')
            power = Symbol(i)
            self.poly += coeffs[i] * (x ** power)
        self.symX = x
        self.poly.print_status()

    def integrate(self):
        # sum(i = 0 to N) a_i X^i -> sum(i = 0 to N) a_i/(i + 1) X^(i + 1)
        pass

    def __add__(self, other):
        pass

    def __mul__(self, other):
        pass

    def __sub__(self, other):
        pass

    def __truediv__(self, other):
        pass
