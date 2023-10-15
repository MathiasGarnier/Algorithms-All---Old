from Symbol import Symbol


class GetLaurentSeriesPP(Symbol):       # PP for Principal Part

    # We use Bronstein's notations (p. 57)
    def __init__(self, A, D, F, n):
        # At that point, one understands why Haskell would be better than Python : we could define
        # LaurentSeries not only in terms of a finite array (which is problematic) but in terms of
        # an infinite sequence !
        # Here we only have a rough approximation
        # In fact, we are not interested in general Laurent series but just in the principal part
        # (cf. Bronstein, p. 57)

        self.poly = Symbol()
        self.poly.implement_function('LS')
        # self.symName = ""
        # self.poly.symType = '<class \'Polynomial.Polynomial\'>'

        self.isVar = False
        self.isFunc = True

        self.composedOf = [self, A, D, F, Symbol(n)]

        self.A = A
        self.D = D
        self.F = F
        self.n = Symbol(n)

    def generate(self):

        print(type(self.F))
        if self.F.degree() == 0:
            return
            
        # Need an implementation of differential fields to be finished.
        E = self.D / (self.F**self.n)   # problem at that time, need a better implementation of power operator

