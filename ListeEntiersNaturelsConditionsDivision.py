# But : répondre au problème (un peu modifié) :
# Donner la liste des plus petits entiers naturels, qui, divisé par 8, 15, 18 et
# 24 donne pour restes respectifs 7, 14, 17 et 23.

MAX = 10000

def generate_array(n):

    arr = [n - 1]

    for i in range(1, MAX):

        arr.append(arr[i - 1] + n)

    return arr

arr_8 = gen(8)
arr_15 = gen(15)
arr_18 = gen(18)
arr_24 = gen(24)

# Check, bruteforce

def check_exercice():

    result = []
    
    for i in range(1, MAX):
        if arr_8[i] in arr_15 and arr_8[i] in arr_18 and arr_8[i] in arr_24:
            result.append(arr_8[i])

    return result

def generate_more_general_array(n, p):

    arr = [n - p]

    for i in range(1, MAX):

        arr.append(arr[n-1] + n)

    return arr
