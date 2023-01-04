def make_matrix(largeur, hauteur, content): 
    mat = []

    for i in range(largeur):
        mat.append([])
        for j in range(hauteur):
            mat[i].append(content)
    return mat

