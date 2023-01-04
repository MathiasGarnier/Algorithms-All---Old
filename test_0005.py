YEP = "Cette année est une année bisextile"
NAN = "Cette année n'est pas bisextile !"

annee = input("Saisissez une année :")
annee = int(annee)

if annee % 400 == 0:
    bissextile = True

elif annee % 100 == 0:
    bissextile = True

elif annee % 4 == 0:
    bissextile = True
else:
    bissextile = False

if bissextile:
    print (YEP)
else:
    print (NAN)
