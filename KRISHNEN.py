"""
from scipy.integrate import solve_ivp
import numpy as np

def eq_mvmt(t, z, alpha, mass, q, B, theta, v0):
    
    x, y = z
    tau = alpha / mass
    qBm = q * B / mass
    sin_term = np.sin(qBm * t + theta)
    cos_term = np.cos(qBm * t + theta)
    exp_term = np.exp(-t * tau)
    return [-v0 * qBm * sin_term * exp_term + v0 * tau * exp_term * cos_term,
             v0 * qBm * cos_term * exp_term + v0 * tau * exp_term * sin_term]

t0, tf = 0, 500
y0 = 1/2, 1/2
sol = solve_ivp(eq_mvmt, (t0, tf), y0, args=(1, 1, 1, 1, 1, 1), dense_output=True)


t = np.linspace(0, 15, 300)
z = sol.sol(t)
import matplotlib.pyplot as plt
#plt.plot(t, z.T)
plt.plot(z[0], z[1])
#plt.show()
"""

"""
from sympy import Symbol
from sympy import cos, sin, exp, series

B = Symbol('B')
v0 = Symbol('v_0')
theta = Symbol('theta')
alpha = Symbol('alpha')

m = Symbol('m')
q = Symbol('q')

t = Symbol('t')

qBm = q * B / m

exp_series = series(exp(-t * alpha / m), t, n=2)
sin_series = series(sin(qBm * t + theta), t, n=2)
cos_series = series(cos(qBm * t + theta), t, n=2)

x_proj = exp_series * (- qBm * sin_series + alpha / m * cos_series)
y_proj = exp_series * (qBm * cos_series + alpha / m * sin_series)


xi = t #[]
yi = 1 #[]


# Solutions en m et q des équations :
    # xi/v0 = x_proj
    # yi/v0 = y_proj
from sympy import solve
# pour plein de temps t différents calculer le bins en fonction du xi / yi
# associé audit temps t :
# x_projSub = x_proj.subs({B: XXX, v0: XXX, theta: XXX, alpha: XXX, t: XXX})
# y_projSub = y_proj.subs({B: XXX, v0: XXX, theta: XXX, alpha: XXX, t: XXX})
# solutions = solve([x_projSub - xi/v0.subs(v0, ???),
#                    y_projSub - yi/v0],
#                   [m, q], dict=True)

x_projSub = x_proj.subs({B: 1, v0: 1, theta: 1, alpha: 1, t: 1/2})
y_projSub = y_proj.subs({B: 1, v0: 1, theta: 1, alpha: 1, t: 1/2})
solutions = solve([x_projSub - xi/v0.subs(v0, 1),
                    y_projSub - yi/v0],
                   [m, q], dict=True, fast=True)
"""

"""
import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt

# function that returns dy/dt
def model(y,t):
    
    K = 1 - y**2
    dydt = -y / (1/K + y**2/(K * K**(1/2)))
    return dydt

# initial condition
y0 = 1.9/2

# time points
t = np.linspace(0,20)

# solve ODE
y = odeint(model,y0,t)

# plot results
plt.plot(t,y)
plt.xlabel('time')
plt.ylabel('y(t)')
plt.show()
"""
"""
import numpy as np
from scipy.integrate import solve_ivp

def deriv(t, y):
    x, y = y

    Kx = 1 - x**2
    Ky = 1 - y**2
    
    xdot = (y - x) / (1/Kx**(1/2) + x**2/(Kx * Kx**(1/2)))
    ydot = (-x - y) / (1/Ky**(1/2) + y**2/(Ky * Ky**(1/2)))
    return xdot, ydot

t0, tf = 0, 500
y0 = 1/2, 1/2
sol = solve_ivp(deriv, (t0, tf), y0, max_step=0.001)

#t = np.linspace(0, 15, 300)
#z = sol(t)
import matplotlib.pyplot as plt
plt.plot(sol.y[0], sol.y[1])
plt.show()
"""


from scipy.integrate import odeint
from scipy.integrate import solve_ivp
import numpy as np


"""
def eq_mvmt(t, z, alpha, mass, q, B, theta, v0):
    
    x, y = z
    tau = alpha / mass
    qBm = q * B / mass
    sin_term = np.sin(qBm * t + theta)
    cos_term = np.cos(qBm * t + theta)
    exp_term = np.exp(-t * tau)
    return [-v0 * qBm * sin_term * exp_term + v0 * tau * exp_term * cos_term,
             v0 * qBm * cos_term * exp_term + v0 * tau * exp_term * sin_term]

t0, tf = 0, 2
y0 = 10, 100
sol = solve_ivp(eq_mvmt, (t0, tf), y0, args=(1, 1, 1, 1, 1, 1), dense_output=True)


t = np.linspace(0, 15, 300)
z = sol.sol(t)
import matplotlib.pyplot as plt
#plt.plot(t, z.T)
plt.plot(z[0], z[1])
"""

"""
def particule(X, t):
    x1, x2, y1, y2 = X

    c = 1
    mass = 1
    alpha = 1
    q = 1
    B = 1
    
    dxdt2 = - alpha / mass * y1 - (y1**2 + y2**2)**(1/2) / c**2 + q * B / mass * x2
    dydt2 = - alpha / mass * y2 - (y1**2 + y2**2)**(1/2) / c**2 - q * B / mass * x1
    return [y1, dxdt2, y2, dydt2]

x1 = 0.0
y1 = 10
x2 = 0.0
y2 = 100

abserr = 1.0e-8
relerr = 1.0e-6
stoptime = 10.0
numpoints = 25000

w0 = [x1, y1, x2, y2]
t = [stoptime * float(i) / (numpoints - 1) for i in range(numpoints)]


wsol = odeint(particule, w0, t,
              atol=abserr, rtol=relerr)


with open('two_springs.dat', 'w') as f:
    # Print & save the solution.
    for t1, w1 in zip(t, wsol):
        f.write("{} {} {} {} {}\n".format(t1, w1[0], w1[1], w1[2], w1[3]))

from numpy import loadtxt

t, x1, xy, x2, y2 = np.loadtxt('two_springs.dat', unpack=True)


import matplotlib.pyplot as plt
#plt.plot(t, x1, 'b', label='theta(t)')
#plt.plot(t, x2, 'g', label='omega(t)')
plt.plot(x1, x2)
plt.legend(loc='best')
plt.xlabel('t')
plt.grid()
plt.show()
"""

import matplotlib.pyplot as plt

def particule(X, t):
    xU, xS, xN, yU, yS, yN = X

    G = 1

    masseUranus = 4
    masseNeptune = 6
    masseSoleil = 10
    
    dUdt2 = (-G * masseSoleil * masseUranus * (xU - xS) / abs(xU - xS)**3 -G * masseNeptune * masseUranus * (xU - xN) / abs(xU - xN)**3) / masseUranus
    dSdt2 = (-G * masseSoleil * masseUranus * (xS - xU) / abs(xS - xU)**3 -G * masseNeptune * masseSoleil * (xS - xN) / abs(xS - xN)**3) / masseSoleil
    dNdt2 = (-G * masseSoleil * masseNeptune * (xU - xS) / abs(xU - xS)**3 -G * masseNeptune * masseUranus * (xN - xU) / abs(xU - xN)**3) / masseNeptune
    return [yU, dUdt2, yS, dSdt2, yN, dNdt2]

xU = 0.1
yU = 0
xS = 0.6
yS = 0
xN = 2
yN = 0

abserr = 1.0e-8
relerr = 1.0e-6
stoptime = 10.0
numpoints = 25000

w0 = [xU, yU, xS, yS, xN, yN]
t = [stoptime * float(i) / (numpoints - 1) for i in range(numpoints)]


wsol = odeint(particule, w0, t,
              atol=abserr, rtol=relerr)


with open('two_springs.dat', 'w') as f:
    # Print & save the solution.
    for t1, w1 in zip(t, wsol):
        f.write("{} {} {} {} {} {} {}\n".format(t1, w1[0], w1[1], w1[2], w1[3], w1[4], w1[5]))

from numpy import loadtxt

t, x1, x2, y1, y2, z1, z2 = np.loadtxt('two_springs.dat', unpack=True)


import matplotlib.pyplot as plt
plt.plot(x1, y1)
plt.legend(loc='best')
plt.xlabel('t')
plt.grid()
plt.show()

#r = np.arange(0, 10000, 0.1)
#fig, ax = plt.subplots(subplot_kw={'projection': 'polar'})
#plt.show()
