import matplotlib.animation as animation
import matplotlib.pyplot as plt
import numpy as np

##############
# CONSTANTES #
##############
road_size = 10
time_length = 10
precision_mesh = 10e-4 
precision_time = 10e-4

#################################
# DISCRÉTISATION (route, temps) #
#################################
nb_cells = int(1/precision_mesh) + 1
mesh = np.linspace(0, road_size, nb_cells)
time_slices = np.linspace(0, time_length, int(1/precision_time) + 1)

dx = mesh[1] - mesh[0]
dt = time_slices[1] - time_slices[0] # On verra plus tard pour CFL etc ...

def initial_density(option):
    # donner une liste d'option pour la densité initiale!
    # feu rouge etc...

    lst = []
    if option == "FEU_ROUGE":
        mid_mesh = int(nb_cells / 2) # int(nb_cells / 2 if nb_cells % 2 == 0 else (nb_cells - 1) / 2)
        print(mid_mesh)
        for i in range(0, mid_mesh): lst.append(1.0)
        for i in range(mid_mesh, nb_cells): lst.append(0.0)
    elif option == "DOUBLE_FEU_ROUGE":  # 2 feux rouges F
                                        # voiture F      personne        voiture F       personne
        meshcut = int(nb_cells / 4)
        for i in range(0, meshcut): lst.append(1.0)
        for i in range(meshcut, 2 * meshcut): lst.append(0.0)
        for i in range(2 * meshcut, 3 * meshcut): lst.append(1.0)
        for i in range(3 * meshcut, nb_cells): lst.append(0.0)
    elif option == "FREINAGE_BRUTAL":
        sigma = 0.1
        lst = [1/np.sqrt(4*np.pi*sigma)*np.exp(-(x - road_size / 2)**2/(4*sigma**2)) for x in mesh]
    elif option == "ALEATOIRE_UNIFORME":
        lst = np.random.uniform(size=nb_cells)
    else:
        lst = [1]
    
    return lst

def flux(x):
    # Dans l'équation drho/dt + d{f(rho)}/dx = 0, le "flux" est la fonction f.
    return x * (1 - x)

def LaxFriedrich(solution, cpt_flux, idx, jth_elem):
    bilan_flux_jplus = 1/2 * (cpt_flux[jth_elem] + cpt_flux[jth_elem + 1]) - 1/2 * dx / dt * (solution[idx][jth_elem + 1] - solution[idx][jth_elem])
    bilan_flux_jminus = 1/2 * (cpt_flux[jth_elem - 1] + cpt_flux[jth_elem]) - 1/2 * dx / dt * (solution[idx][jth_elem] - solution[idx][jth_elem - 1])

    return bilan_flux_jminus, bilan_flux_jplus

t, idx = 0, 0
solution = [initial_density("ALEATOIRE_UNIFORME")]

while t <= time_length:
    # À chaque pas de temps, on calcule les nouvelles positions
    new_pos = []

    # c'est le fait de périodiciser qui fout toalement la merde!!!
    #circle_solution = np.concatenate(([solution[idx][-1]], solution[idx], [solution[idx][0]]))
    
    # On calcule les flux par la gauche (par rapport à la solution de l'itération précédente)
    cpt_flux = flux(np.array(solution[idx]))
    #cpt_flux = flux(circle_solution)

    #last_bilan_flux = 0
    jth_elem = 0
    for elem in solution[idx]:

        # Lax-Friedrich totalement naïf (sans corrélation avec Vmax et sans correction du pas de temps)
        if jth_elem + 1 == len(solution[idx]): pass
        else:
            # bilan_flux = 1/2 * (cpt_flux[jth_elem] + cpt_flux[jth_elem + 1]) - 1 / 2 * (solution[idx][jth_elem + 1] - solution[idx][jth_elem])
            # bilan_flux_jplus = 1/2 * (cpt_flux[jth_elem] + cpt_flux[jth_elem + 1]) - 1 / 2 * dx / dt * (solution[idx][jth_elem + 1] - solution[idx][jth_elem])
            # bilan_flux_jminus = 1/2 * (cpt_flux[jth_elem - 1] + cpt_flux[jth_elem]) - 1 / 2 * dx / dt * (solution[idx][jth_elem] - solution[idx][jth_elem - 1])
                # C'est pas du tiouot cpt flux mais flux!!
            #bilan_flux_jplus = 1/2 * (cpt_flux[jth_elem] + cpt_flux[jth_elem + 1]) - 1/2 * dx / dt * (solution[idx][jth_elem + 1] - solution[idx][jth_elem])
            #bilan_flux_jminus = 1/2 * (cpt_flux[jth_elem - 1] + cpt_flux[jth_elem]) - 1/2 * dx / dt * (solution[idx][jth_elem] - solution[idx][jth_elem - 1])
            # Ça c'est pour f(rho) = u_max rho (1 - rho / rho_max)
            #u_max, rho_max = 1, 1
            #bilan_flux_jplus = dx/(2*dt)*(solution[idx][jth_elem] - solution[idx][jth_elem + 1]) + 1/2*(u_max*solution[idx][jth_elem]*(1 - solution[idx][jth_elem]/rho_max) + u_max*solution[idx][jth_elem + 1]*(1 - solution[idx][jth_elem + 1]/rho_max))
            #bilan_flux_jminus = dx/(2*dt)*(solution[idx][jth_elem - 1] - solution[idx][jth_elem]) + 1/2*(u_max*solution[idx][jth_elem - 1]*(1 - solution[idx][jth_elem - 1]/rho_max) + u_max*solution[idx][jth_elem]*(1 - solution[idx][jth_elem]/rho_max))
            bilan_flux_jminus, bilan_flux_jplus = LaxFriedrich(solution, cpt_flux, idx, jth_elem)
            elem = elem - dt/dx * (bilan_flux_jplus - bilan_flux_jminus)

            #last_bilan_flux = bilan_flux

        new_pos.append(elem)
        jth_elem += 1

    solution.append(new_pos)

    print(t)
    t += dt 
    idx += 1           

fig, ax = plt.subplots()


ax.set_xlim(0, time_length)
ax.set_ylim(0, 1.1)
        
plt_sol, = plt.plot([], []) 

def animate(i):
    plt_sol.set_data(mesh, solution[i])
    return plt_sol,
            
ani = animation.FuncAnimation(fig, animate, repeat=True, frames=len(mesh) - 1, interval=0.0001)

plt.show()









"""
import matplotlib.animation as animation
import matplotlib.pyplot as plt
import numpy as np

##############
# CONSTANTES #
##############
road_size = 10
time_length = 10
precision_mesh = 10e-4 
precision_time = 10e-4

#################################
# DISCRÉTISATION (route, temps) #
#################################
nb_cells = int(1/precision_mesh) + 1
mesh = np.linspace(0, road_size, nb_cells)
time_slices = np.linspace(0, time_length, int(1/precision_time) + 1)

dx = mesh[1] - mesh[0]
dt = time_slices[1] - time_slices[0] # On verra plus tard pour CFL etc ...

def initial_density(option):
    # donner une liste d'option pour la densité initiale!
    # feu rouge etc...

    lst = []
    if option == "FEU_ROUGE":
        mid_mesh = int(nb_cells / 2) # int(nb_cells / 2 if nb_cells % 2 == 0 else (nb_cells - 1) / 2)
        print(mid_mesh)
        for i in range(0, mid_mesh):
            lst.append(1.0)
        for i in range(mid_mesh, nb_cells):
            lst.append(0.0)
    elif option == "FREINAGE_BRUTAL":
        sigma = 0.1
        lst = [1/np.sqrt(4*np.pi*sigma)*np.exp(-(x - road_size / 2)**2/(4*sigma**2)) for x in mesh]
    else:
        lst = [1]
    
    return lst

def flux(x):
    # Dans l'équation drho/dt + d{f(rho)}/dx = 0, le "flux" est la fonction f.
    return np.exp(x)

t, idx = 0, 0
solution = [initial_density("FREINAGE_BRUTAL")]

while t <= time_length:
    # À chaque pas de temps, on calcule les nouvelles positions
    new_pos = []

    # sssss
    torus_solution = np.concatenate(([solution[idx][-1]], solution[idx], [solution[idx][0]]))
    # On calcule les flux par la gauche (par rapport à la solution de l'itération précédente)
    #cpt_flux = flux(solution[idx])
    cpt_flux = flux(torus_solution)

    #last_bilan_flux = 0
    jth_elem = 0
    for elem in solution[idx]:

        # Lax-Friedrich totalement naïf (sans corrélation avec Vmax et sans correction du pas de temps)
        if jth_elem + 1 == len(solution[idx]): pass
        else:
            # bilan_flux = 1/2 * (cpt_flux[jth_elem] + cpt_flux[jth_elem + 1]) - 1 / 2 * (solution[idx][jth_elem + 1] - solution[idx][jth_elem])
#            bilan_flux_jplus = 1/2 * (cpt_flux[jth_elem] + cpt_flux[jth_elem + 1]) - 1 / 2 * dt / dx * (solution[idx][jth_elem + 1] - solution[idx][jth_elem])
#            bilan_flux_jminus = 1/2 * (cpt_flux[jth_elem - 1] + cpt_flux[jth_elem]) - 1 / 2 * dt / dx * (solution[idx][jth_elem] - solution[idx][jth_elem - 1])
            u_max, rho_max = 1, 1
            bilan_flux_jplus = dx/(2*dt)*(solution[idx][jth_elem] - solution[idx][jth_elem + 1]) + 1/2*(u_max*solution[idx][jth_elem]*(1 - solution[idx][jth_elem]/rho_max) + u_max*solution[idx][jth_elem + 1]*(1 - solution[idx][jth_elem + 1]/rho_max))
            bilan_flux_jminus = dx/(2*dt)*(solution[idx][jth_elem - 1] - solution[idx][jth_elem]) + 1/2*(u_max*solution[idx][jth_elem - 1]*(1 - solution[idx][jth_elem - 1]/rho_max) + u_max*solution[idx][jth_elem]*(1 - solution[idx][jth_elem]/rho_max))

            elem = elem - dt/dx * (bilan_flux_jplus - bilan_flux_jminus)

            #last_bilan_flux = bilan_flux

        new_pos.append(elem)
        jth_elem += 1

    solution.append(new_pos)

    print(t)
    t += dt 
    idx += 1           

fig, ax = plt.subplots()


ax.set_xlim(0, time_length)
ax.set_ylim(0, 1.1)
        
plt_sol, = plt.plot([], []) 

def animate(i):
    plt_sol.set_data(mesh, solution[i])
    return plt_sol,
            
ani = animation.FuncAnimation(fig, animate, repeat=True, frames=len(mesh) - 1, interval=0.0001)

plt.show()
"""