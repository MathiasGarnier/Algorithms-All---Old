# Bronstein, PolyDivide, page 8.

from Polynomial import Polynomial
from math import fabs


def degree(poly: object) -> int:       # Needed help for a good def of degree
    while poly and poly[-1] == 0:
        poly.pop()
    return len(poly)-1


def polynomialDivision(poly1, poly2):
    # poly1 is an array of coeffs
    # poly2 is an array of coeffs
    assert(poly2 != [0])

    dP1, dP2 = degree(poly1), degree(poly2)
    q = [0]*dP1

    while dP1 >= dP2:
        d = [0] * (dP1 - dP2) + poly2
        m = q[dP1 - dP2] = poly1[-1] / d[-1]
        d = [x * m for x in d]

        poly1 = [fabs(x - y) for x, y in zip(poly1, d)]
        dP1 = degree(poly1)

    return q, poly1


def symbolicPolyDivide(poly1: Polynomial, poly2: Polynomial):
    return poly1 / poly2  # works due to "/" operator overload


def symbolicExtendedEuclidean(poly1, poly2, n):
    pass    # Equivalent of Lean's 'sorry'
