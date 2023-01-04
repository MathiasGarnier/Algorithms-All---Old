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
#plt.xlabel('t')
#plt.legend(['x', 'y'], shadow=True)
#plt.title('Lotka-Volterra System')
plt.show()
