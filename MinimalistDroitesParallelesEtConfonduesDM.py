def fct(a, b): 
    
    tmp = (a[0] * b[1] == a[1] * b[0])
    return (tmp, True if tmp and (((a[0] and b[0] != 0) and (a[2] / a[0] == b[2] / b[0])) or ((a[0] == b[0] == 0) and (a[2] / a[1] == b[2] / b[1]))) else False)

f_coefficient = input("Les trois coefficients de f : ").split(',')
s_coefficient = input("Les trois coefficients de s : ").split(',')

print(fct([float(x.strip()) for x in f_coefficient], [float(x.strip()) for x in s_coefficient]))
