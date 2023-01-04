xn = 2

for i in range(1, MAX):
    
    xnp1 = xn - (1 / xn)
    
    xn = xnp1
    
    print(xn > 0, xn)
