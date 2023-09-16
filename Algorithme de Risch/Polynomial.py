from Symbol import Symbol


class Polynomial(Symbol):

    def __init__(self, coeffs):

        # coeffs must have a symbol type
        self.coeffs = coeffs
        self.poly = Symbol()
        self.poly = coeffs[0]
        for i in range(1, len(coeffs)):
            x = Symbol()
            x.implement_variable('x')
            power = Symbol(i)
            self.poly += coeffs[i] * (x ** power)

        self.symX = x
        self.poly.print_status()
