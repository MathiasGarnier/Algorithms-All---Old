import math
import numbers

class CartesianCoordinateSystem:

    def __init__(self, x, y):

        if not isinstance(x, numbers.Real): raise ValueError("There is an Error, please check the value of (CartesianCoordinateSystem) x")
        if not isinstance(y, numbers.Real): raise ValueError("There is an Error, please check the value of (CartesianCoordinateSystem) y")

        self.x = x
        self.y = y

    def distance(self, other):

        return math.sqrt(math.pow(other.x - self.x, 2) + math.pow(other.y - self.y, 2))

    def translate(self, by):

        self.x += by
        self.y += by

    def rotate(self, theta):

        x = self.x * math.cos(math.radians(theta)) - self.y * math.sin(math.radians(theta))
        y = self.x * math.sin(math.radians(theta)) + self.y * math.cos(math.radians(theta))

        self.x, self.y = x, y

    def scale(self, scaling):

        self.x *= scaling
        self.y *= scaling

    def __str__(self):
        """
            Overloading of __str__ function.
            Use while print(CartesianCoordinateSystem object)
        """
        return "x : {0}\ny : {1}".format(self.x, self.y)

    def __lt__(self, other):
        """
            Overloading of < operator
        """

        return self.x < other.x and self.y < other.y

    def __le__(self, other):
        """
            Overloading of <= operator
        """

        return self.x <= other.x and self.y <= other.y

    def __eq__(self, other):
        """
            Overloading of == operator
        """

        return self.x == other.x and self.y == other.y

    def __ne__(self, other):
        """
            Overloading of != operator
        """

        return self.x != other.x and self.y != other.y

    def __gt__(self, other):
        """
            Overloading of > operator
        """

        return self.x > other.x and self.y > other.y

    def __ge__(self, other):
        """
            Overloading of >= operator
        """

        return self.x >= other.x and self.y >= other.y
