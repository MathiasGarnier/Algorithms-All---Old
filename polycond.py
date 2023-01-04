# https://stackoverflow.com/a/19498432
# Générer les nombres premiers jusqu'à n
def primes(n): # simple sieve of multiples 
   odds = range(3, n+1, 2)
   sieve = set(sum([list(range(q*q, n+1, q+q)) for q in odds], []))
   return [2] + [p for p in odds if p not in sieve]
def primes1(n): # WAYYYY FASTER
    """ Returns  a list of primes < n """
    sieve = [True] * (n//2)
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = [False] * ((n-i*i-1)//(2*i)+1)
    return [2] + [2*i+1 for i in range(1,n//2) if sieve[i]]

#print(sum(primes1(2000)))


arr =    [[8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8],
          [49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0],
          [81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65],
          [52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91],
          [22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80],
          [24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50],
          [32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70],
          [67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21],
          [24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72],
          [21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95],
          [78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92],
          [16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57],
          [86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58],
          [19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40],
          [4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66],
          [88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69],
          [4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36],
          [20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16],
          [20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54],
          [1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48] ]


max_val = 0
for i in range(0, 20):
   for j in range(0, 20):

      # Right
      try:
         max_val = max(max_val, arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3])
      except IndexError:
         pass

      # Left
      try:
         max_val = max(max_val, arr[i][j] * arr[i][j - 1] * arr[i][j - 2] * arr[i][j - 3])
      except IndexError:
         pass

      # Up
      try:
         max_val = max(max_val, arr[i][j] * arr[i - 1][j] * arr[i - 2][j] * arr[i - 3][j])
      except IndexError:
         pass

      # Down
      try:
         max_val = max(max_val, arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j])
      except IndexError:
         pass

      # Diagonal UP LEFT to DOWN RIGHT
      try:
         max_val = max(max_val, arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3])
      except IndexError:
         pass
      
      # Diagonal DOWN LEFT to UP RIGHT
      try:
         max_val = max(max_val, arr[20 - i][20 - j] * arr[20 - i - 1][20 - j + 1] * arr[20 - i - 2][20 - j + 2] * arr[20 - i - 3][20 - j + 3])
      except IndexError:
         pass

print(max_val)

from sympy import Symbol, integrate, oo, sin, cos, atan, asinh, Sum, factorial
from sympy.abc import i

x = Symbol('x')

def u_partial_sin(k):
   return ((-1)**(k - 1) * x**(2*k - 1))/factorial(2*k - 1)

def u_total_sin(n):
   return sum(u_partial_sin(i) for i in range(1, n + 1))
   #return Sum(((-1)**(i - 1) * x**(2*i - 1))/factorial(2*i - 1), (i, 1, n)).doit()
def integrand_sin(n):
   return (u_total_sin(n) - sin(x))/(x**(2*n + 1))

def u_n_sin(n):
   return integrate(integrand_sin(n), (x, 0, oo))

#for i in range(1, 10):
#	print(str(i) + " " + str(u_n_sin(i)))

n = 3
print(Sum(((-1)**(i - 1) * x**(2*i - 1))/factorial(2*i - 1), (i, 1, n)).doit())
print(u_total_sin(n))

def u_n_sin(n):
   return integrate((Sum(((-1)**(i - 1) * x**(2*i - 1))/factorial(2*i - 1), (i, 1, n)).doit() - sin(x)) / (x**(2*n + 1)), (x, 0, oo))

def u_n_cos(n):
   return integrate((Sum(((-1)**(i - 1) * x**(2*i - 2))/factorial(2*i - 2), (i, 1, n)).doit() - cos(x)) / (x**(2*n)), (x, 0, oo))

def u_n_arctan(n):
   return integrate((Sum(((-1)**(i - 1) * x**(2*i - 1))/(2*i - 1), (i, 1, n)).doit() - atan(x)) / (x**(2*n + 1)), (x, 0, oo))

def u_n_asinh(n): # Ne converge que pour n = 1 (vers 1/2)?
   return integrate((Sum(((-1)**(i - 1) * factorial(2*i - 1) * x**(2*i - 1))/((2*i - 1) * 4**(i - 1) * factorial(i - 1)**2), (i, 1, n)).doit() - asinh(x)) / (x**(2*n + 1)), (x, 0, oo))

print((Sum(((-1)**(i - 1) * factorial(2*i - 1) * x**(2*i - 1))/((2*i - 1) * 4**(i - 1) * factorial(i - 1)**2), (i, 1, n)).doit()))
