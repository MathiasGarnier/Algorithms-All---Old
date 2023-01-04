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
import matplotlib.pyplot as plt

def particule(t, X, Y, dX, dY):
        
    c = 1 #2.18769126364e6
    mass = 1 #5e-4
    alpha = 1 #1e-4
    q = 1
    B = 1 #6.38e-6

    gamma = 1 / (1 - (X**2 + Y**2)**(1/2)/c**2)**(1/2)
    
    #dxdt2 = - alpha / mass * y1 / gamma - gamma**2 * (y1**2 + y2**2)**(1/2) / c**2 + q * B / mass * x2 / gamma
    #dydt2 = - alpha / mass * y2 / gamma - gamma**2 * (y1**2 + y2**2)**(1/2) / c**2 - q * B / mass * x1 / gamma

    dxdt2 = (q * B * Y - alpha * X - mass * gamma**3 / c**2 * X * Y * dY) / (mass * gamma * (1 + gamma**2 / c**2 * X**2))
    dydt2 = (-q * B * X - alpha * Y - mass * gamma**3 / c**2 * Y * X * dX) / (mass * gamma * (1 + gamma**2 / c**2 * Y**2))
    
    return [dxdt2, dydt2]

"""
"""
initial = [0, 2.18769126364e6/10, 0, 2.18769126364e6/10]
t = [100 * float(i) / (25000 - 1) for i in range(25000)]

wsol = odeint(particule, initial, t, atol=1.0e-8, rtol=1.0e-6)

plt.plot(t, wsol)
plt.show()
"""
"""
def rk4():
# https://math.stackexchange.com/questions/146823/solving-coupled-2nd-order-odes-with-runge-kutta-4

    h = 0.1
    time = 0
    initial_time = 0
    final_time = 10

    step = 0
    number_of_steps = int((final_time - initial_time) / h)

    x = [0]*number_of_steps
    y = [0]*number_of_steps
    
    xp = [0]*number_of_steps
    yp = [0]*number_of_steps
    
    while time < final_time - 1:

        time = initial_time + step * h

        K0x = particule(time,x[step],y[step],xp[step],yp[step])[0]           
        K0y = particule(time,x[step],y[step],xp[step],yp[step])[1]
        Q1x = xp[step] + (h/2)*K0x            
        Q1y = yp[step] + (h/2)*K0y
        K1x = particule(time+h/2,x[step]+(h/2)*xp[step],y[step]+(h/2)*yp[step],Q1x,Q1y)[0]    
        K1y = particule(time+h/2,x[step]+(h/2)*xp[step],y[step]+(h/2)*yp[step],Q1x,Q1y)[1]
        Q2x = xp[step] + (h/2)*K1x           
        Q2y = yp[step] + (h/2)*K1y
        K2x = particule(time+h/2,x[step]+(h/2)*Q1x,y[step]+(h/2)*Q1y,Q2x,Q2y)[0]  
        K2y = particule(time+h/2,x[step]+(h/2)*Q1x,y[step]+(h/2)*Q1y,Q2x,Q2y)[1]
        Q3x = xp[step] + h*K2x         
        Q3y = yp[step] + h*K2y
        K3x = particule(time+h, x[step]+h*Q2x, y[step]+h*Q2y, Q3x,Q3y)[0]    
        K3y = particule(time+h, x[step]+h*Q2x, y[step]+h*Q2y, Q3x,Q3y)[1]

        x[step + 1] = x[step] + h*(xp[step]+(h/6)*(K0x + K1x + K2x))
        y[step + 1] = y[step] + h*(yp[step]+(h/6)*(K0y + K1y + K2y))
        
        xp[step + 1] = xp[step] + (h/6)*(K0x + 2*K1x + 2*K2x + K3x)
        yp[step + 1] = yp[step] + (h/6)*(K0y + 2*K1y + 2*K2y + K3y)

        time += h
        step += 1

    return xp, yp, x, y

wsol = rk4()
"""
"""
??????????????????????
x1 = 0.0
y1 = 0.0
x2 = 0.1
y2 = 0.1

abserr = 1.0e-8
relerr = 1.0e-6
stoptime = 100.0
numpoints = 25000

??????????????????????w0 = [x1, y1, x2, y2]
t = [stoptime * float(i) / (numpoints - 1) for i in range(numpoints)]


wsol = odeint(particule, w0, t,
              atol=abserr, rtol=relerr)

"""


#with open('two_springs.dat', 'w') as f:
#    # Print & save the solution.
#    for t1, w1 in zip(t, wsol):
#        f.write("{} {} {} {} {}\n".format(t1, w1[0], w1[1], w1[2], w1[3]))

#from numpy import loadtxt

#t, x1, xy, x2, y2 = np.loadtxt('two_springs.dat', unpack=True)


"""
#def eq_mvmt(z, t, alpha, mass, q, B, theta, v0):
def eq_mvmt(t, alpha, mass, q, B, theta, v0):
    
    #x, y = z
    #tau = alpha / mass
    #qBm = q * B / mass
    #sin_term = np.sin(qBm * t + theta)
    #cos_term = np.cos(qBm * t + theta)
    #exp_term = np.exp(-t * tau)
    #return [-v0 * qBm * sin_term * exp_term + v0 * tau * exp_term * cos_term,
    #         v0 * qBm * cos_term * exp_term + v0 * tau * exp_term * sin_term]

    omega = q * B / mass
    tau = mass / alpha
    return [-np.exp(-t/tau) * v0 * omega * np.sin(theta + omega * t) - 1/tau * v0 * np.cos(theta + omega * t) * np.exp(-t/tau),
            v0 * omega * np.cos(theta + omega * t) * np.exp(-t/tau) - 1/tau * v0 * np.sin(theta + omega * t) * np.exp(-t/tau)]
    #return [(mass * tau *(-(mass * np.cos((B * q * t)/mass + theta)) + B * q * tau * np.sin((B * q * t)/mass + theta))* v0)/((mass**2 + B**2 * q**2 * tau**2)) * np.exp(-t/tau),
    #        -((mass * tau * (B * q * tau * np.cos((B * q * t)/mass + theta) + mass * np.sin((B * q * t)/mass + theta)) * v0)/((mass**2 + B**2 * q**2 * tau**2))) * np.exp(-t/tau)]
#t0, tf = 0, 100
#y0 = 0.1, 0.1
#sol = solve_ivp(eq_mvmt, (t0, tf), y0, args=(1, 5e-4, 1, 6.38e-6, 1, 0.1), dense_output=True)
#sol = odeint(eq_mvmt, [w0[0], w0[2]], t,
#             args=(1e-4, 5e-4, 1, 6.38e-6, 0, 100), atol=abserr, rtol=relerr)
#with open('two_springs2.dat', 'w') as f:
#    # Print & save the solution.
#    for t1, w1 in zip(t, sol):
#        f.write("{} {} {}\n".format(t1, w1[0], w1[1]))
#
#_, X1, X2 = np.loadtxt('two_springs2.dat', unpack=True)
"""

"""  
import matplotlib.pyplot as plt
#plt.plot(t, z.T)


st = np.linspace(0, 100, 25000)


s = eq_mvmt(st, 1e-4, 5e-4, 1, 6.38e-6, 0, 100)
#plt.plot(t, s[0], color="b", label="classique")
#plt.plot(t, s[1], color="b")

plt.plot(s[0], s[1], label="classique")
plt.plot(x1, x2, label="relativiste")

#plt.plot(t, x1, color="red", label="relativiste")
#plt.plot(t, x2, color="red")
#plt.xlabel('t')
plt.grid()
plt.legend()

plt.show()
"""

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
"""

""" BROOOOOOKEN

import sympy as sp
import numpy as np
sp.init_printing() # math as latex


c = sp.Symbol('c')
t = sp.Symbol('t')
Y = sp.Function('Y')(t)
Y_ = sp.Derivative(Y, t)


equation = sp.Eq(1/2 * Y_ + Y*sp.sqrt(1 - sp.sqrt(Y) / c**2) + Y * sp.sqrt(Y) / c**2 - Y**2/c**4, 0)
#equation = sp.Eq(1/2 * Y_ + sp.sqrt(Y - sp.sqrt(Y)) + sp.sqrt(Y) + 1, 0)

solution = sp.dsolve(equation, hint='1st_power_series', ics={Y.subs(t,0):0}, n = 10)
print(solution)
"""

""" GOOOOO JUPYTER LAB
"""
from PIL import Image
import numpy as np

image_repo = 'C:\\Users\\mathi\\OneDrive\\Bureau\\phys\\ODEINT\\'
image_name = ['202540803.png', '202540803_test.png']

image_path = [image_repo + name for name in image_name]

#test = [np.array(Image.open(bubble_image).convert('RGB')) for bubble_image in image_path]
test = [np.array(Image.open(bubble_image).convert('RGB')) for bubble_image in image_path]

# Il va falloir écrire un "custom data loader" 
# https://detectron2.readthedocs.io/en/latest/tutorials/data_loading.html#write-a-custom-dataloader
# car l'image est trop grande


shapeX = test[1].shape[1]
shapeY = test[1].shape[0]

val_to_extra = []

for x in range(shapeX):
    for y in range(shapeY):
        if all(abs(test[1][y][x] - 240) < 20):
            val_to_extra.append([x, y])


import matplotlib.pyplot as plt

arr_test = np.array(val_to_extra)
arr_testX = [tmp_test[0] for tmp_test in arr_test]
arr_testY = [tmp_test[1] for tmp_test in arr_test]

#plt.plot(arr_testX, arr_testY, '.k')

to_interpolate = [[454, 294], [444, 200], [369, 156], [281, 192], [249, 259], [263, 333], [340, 386], [414, 369], [473, 272], [413, 124], [210, 97], [131, 189], [116, 300], [172, 406], [385, 434], [486, 320], [488, 213], [310, 23], [75, 96], [20, 205], [19, 331], [106, 471], [260, 521], [496, 529]]
arr_testX = [tmp_test[0] for tmp_test in to_interpolate]
arr_testY = [tmp_test[1] for tmp_test in to_interpolate]

from scipy.interpolate import UnivariateSpline

# Define some points:
points = np.array([arr_testX, arr_testY]).T
# Linear length along the line:
distance = np.cumsum( np.sqrt(np.sum( np.diff(points, axis=0)**2, axis=1 )) )
distance = np.insert(distance, 0, 0)/distance[-1]

# Build a list of the spline function, one for each dimension:
splines = [UnivariateSpline(distance, coords, k=3, s=.02) for coords in points.T]

# Computed the spline for the asked distances:
alpha = np.linspace(0, 1, 300)
points_fitted = np.vstack( spl(alpha) for spl in splines ).T

# Graph:
#plt.plot(*points.T, 'ok');
#plt.plot(*points_fitted.T, '-r');
#plt.axis('equal'); plt.legend(); plt.xlabel('x'); plt.ylabel('y');

fittedX = [tmp_test[0] for tmp_test in points_fitted]
fittedY = [tmp_test[1] for tmp_test in points_fitted]

# Calculer dérivée numérique :
tmpX, tmpY = np.array(fittedX), np.array(fittedY)
dX, dY = np.gradient(tmpX), np.gradient(tmpY)

#plt.plot([i for i in range(len(dX))], dX)
#plt.plot([i for i in range(len(dY))], dY)

Z = np.divide(dX, dY)
dZ = np.gradient(Z)

gamma = 1
B = 1.5

mQ = B/gamma * (1 + Z**2)/dZ

c = 3e8
gamma = 1/(1 - (np.multiply(tmpX, tmpX) + np.multiply(tmpY, tmpY))/c**2)**(1/2)
mQrelat = B/gamma * (1 + Z**2)/dZ

plt.plot([i for i in range(len(mQ))], mQ)
plt.plot([i for i in range(len(mQrelat))], mQrelat)
plt.show()

"""
from sympy import init_printing
init_printing() 

from sympy import Symbol, Function, Eq
from sympy import sqrt
from sympy import simplify

import numpy as np

m = Symbol('m')
c = Symbol('c')

t = Symbol('t')
vx = Function('vx')(t)
vy = Function('vy')(t)

v = Function('v')(t)

gamma = 1 / sqrt(1 - v**2 / c**2)
print(gamma.diff(t))

dpdt = (m * v * gamma).diff(t)
dpdt_simp = simplify(dpdt)

dpdt_res0 = m * gamma * v.diff(t) + m * v * gamma.diff(t)
print(dpdt_simp.equals(dpdt_res0)) # True

dpdt_res1 = m * gamma * v.diff(t) - 1/2 * m * v * 2 * v * v.diff(t) / c**2 * np.power(1 - v**2/c**2, -3/2)
print(dpdt_simp.equals(dpdt_res1))

dpdt_res = m * gamma * v.diff(t) + m * v**2 * v.diff(t) / c**2 * gamma**3
print(dpdt_simp.equals(dpdt_res))

v = sqrt(vx**2 + vy**2)
"""
