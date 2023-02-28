import matplotlib.pyplot as plt
import numpy as np
from math import comb

#plt.rcParams['text.usetex'] = True


def binomial_coefficient(n, k):
  return comb(n, k)

def bernstein_approx(function, n):

    # On reste sur [0, 1]
    X = np.linspace(0, 1, 10000)
    
    return sum(function(k/n) * binomial_coefficient(n, k) * X**k * (1 - X)**(n - k) for k in range(0, n + 1))

fun = lambda x: x*np.tan(np.log(1 + x**2))/ np.exp(x) + np.sin(x + np.cos(1/(0.00001 + x)**2))


t = np.linspace(0, 1, 10000)


#plt.plot(t, fun(t))

for i in range(10, 15):
    plt.plot(t, abs(fun(t) - bernstein_approx(fun, i*3)), label="n = " + str(3 * i))


plt.plot(t, t - t, label="n = " + str(r"$\infty$"))

plt.legend()
plt.show()
