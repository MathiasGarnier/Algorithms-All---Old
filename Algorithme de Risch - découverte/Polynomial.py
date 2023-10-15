from Symbol import Symbol
from math import fabs
from operator import add


def cauchy_product(seq_a, seq_b, index):
    return sum([seq_a[i] * seq_b[index - i] for i in range(0, index + 1)])


class Polynomial(Symbol):

    def __init__(self, coeffs=None):

        self.poly = Symbol()
        self.poly.implement_function('P')
        # self.symName = ""
        # self.poly.symType = '<class \'Polynomial.Polynomial\'>'

        self.isVar = False
        self.isFunc = True

        self.composedOf = [self]
        # self.composedName = self.symName

        # coeffs must have a symbol type
        self.coeffs = coeffs
        if self.coeffs is not None:
            self.deg = len(self.coeffs) - 1

        if coeffs is not None:
            self.poly += Symbol(coeffs[0])
            x = Symbol()
            for i in range(1, len(coeffs)):
                x = Symbol()                    # different but the same...
                x.implement_variable('x')
                power = Symbol(i)
                coco = Symbol(coeffs[i])
                if coeffs[i] != 0 and power not in self.composedOf:
                    self.composedOf.append(power)
                self.poly += coco * (x ** power)
            self.symX = x
            # self.poly.print_status()
        else:
            self.poly = None

    def build_poly_from_coeffs(self, coeffs):

        self.coeffs = coeffs
        self.poly = Symbol()
        self.poly = Symbol(coeffs[0])

        x = Symbol()
        x.implement_variable('x')

        for i in range(1, len(coeffs)):
            power = Symbol(i)
            coco = Symbol(coeffs[i])
            if coeffs[i] != 0 and power not in self.composedOf:
                self.composedOf.append(power)
            self.poly += coco * (x ** power)
        self.symX = x
        # self.poly.print_status()

    def integrate(self):
        # sum(i = 0 to N) a_i X^i -> sum(i = 0 to N) a_i/(i + 1) X^(i + 1)
        n_coeffs = []
        # for x in self.composedOf:
        #    if x.isFunc == False:
        #        print(x.get_value())
        for i in range(len(self.coeffs)):
            # print("IN")
            # print(i)
            self.coeffs[i].to_real()
            # print(self.coeffs[i].get_value())
            n_coeffs.append(self.coeffs[i].get_value() / (i + 1))

        self.build_poly_from_coeffs(n_coeffs)

    def get_coeffs(self):
        return self.coeffs

    def eval(self, valX):
        return sum([self.coeffs[i] * valX**i for i in range(len(self.coeffs))])

    def __add__(self, other):
        if len(self.coeffs) == len(other):
            self.build_poly_from_coeffs([x + y for x, y in zip(self.coeffs, other)])
        elif len(self.coeffs) > len(other):
            pass
        else:   # len(self.coeff) < len(other)
            pass

    def __mul__(self, other):
        if len(self.coeffs) == len(other.get_coeffs()):
            self.build_poly_from_coeffs([cauchy_product(self.coeffs, other, i) for i in range(0, len(self.coeffs) + 1)])
        # other cases are not important for the moment

    def __sub__(self, other):
        if len(self.coeffs) == len(other):
            self.build_poly_from_coeffs([x - y for x, y in zip(self.coeffs, other)])
        elif len(self.coeffs) > len(other):
            pass
        else:  # len(self.coeff) < len(other)
            pass

    def __pow__(self, power, modulo=None):
        pass

    def degree(self) -> int:
        # tmp = self.coeffs
        # while tmp and tmp[-1] == 0:
        #    tmp.pop()
        # return len(tmp) - 1
        if self.coeffs is not None:
            self.deg = len(self.coeffs) - 1
            return self.deg
        else:
            return int('-inf')

    def __truediv__(self, other):       # Décomposition en éléments simples
        # poly1 is an array of coeffs
        # poly2 is an array of coeffs
        # Boh hé assert (other.get_coeffs != [0])

        dP1, dP2 = self.deg, other.degree()
        q = [0] * dP1

        d = Polynomial()
        poly1 = Polynomial()

        while dP1 >= dP2:
            coeff_other = other.get_coeffs()
            print([0] * (dP1 - dP2))
            d.build_poly_from_coeffs(list(map(add, [0] * (dP1 - dP2), coeff_other)))    # Oops # No # Problem !

            m = q[dP1 - dP2] = self.coeffs[-1] / d.get_coeffs()[-1]
            d.build_poly_from_coeffs([x * m for x in d.get_coeffs()])

            poly1.build_poly_from_coeffs([fabs(x - y) for x, y in zip(self.coeffs, d.get_coeffs())])
            dP1 = poly1.degree()

        return q, poly1
