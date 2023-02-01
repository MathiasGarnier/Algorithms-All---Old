import matplotlib.pyplot as plt
import numpy as np

def harmonique(n):

    # Valeurs série harmonique (k = 1..n)

    res = [0.]
    val = 0.
    for k in range(1, n):
        val += 1/k
        res.append(val)
    
    return res

def estim_1(n):

    # serie harmonique = log(n) + gamma + 1/(2n) + o(1/n)

    gamma = 0.5772156649015328

    return np.log(n) + gamma + 1/(2 * n)

def estim_2(n):

    # serie harmonique = log(n+1) + gamma - 1/(2n) + o(1/n)

    gamma = 0.5772156649015328
    
    return np.log(n + 1) + gamma - 1/(2 * n)

def plot_curves():
    
    BORNE = 1000
    t = np.arange(1, BORNE, 1)

    plt.plot(t, harmonique(BORNE - 1), label="série harmonique")
    plt.plot(t, estim_1(t), label="estim 1")
    plt.plot(t, estim_2(t), label="estim 2")

    leg = plt.legend(loc='lower right')

    plt.show()

def plot_diff_estim():

    BORNE = 1000
    t = np.arange(1, BORNE, 1)

    harm = harmonique(BORNE - 1)
    diff1 = abs(harm - estim_1(t))
    diff2 = abs(harm - estim_2(t))

    plt.plot(t, diff1, label="diff estim 1")
    plt.plot(t, diff2, label="diff estim 2")

    leg = plt.legend(loc='lower right')

    plt.show()

plot_diff_estim()

# Conclusion, mon estimation est un pequeño mieux
