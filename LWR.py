from scipy.optimize import minimize_scalar # vaut mieux ne pas utiliser le schéma localLaxFriedrich 
from scipy import integrate # pour vérifier rapidement la conservation du nombre de voiture, on aurait pu le
# réimplémenter nous même (on a d'ailleurs tous les codes en notre possession) mais on ne voyait pas l'utilité
# d'écrire une n-ième fois la méthode de Simpson
import matplotlib.animation as animation 
import matplotlib.pyplot as plt
import numpy as np

DEBUG = False

##############
# CONSTANTES #      On est adimensionné !
##############
road_size = 10
time_length = 6

############################################
# GRILLE POUR LA MÉTHODE DES VOLUMES FINIS #    On discrétise !
############################################

# Si la précision est modifiée, penser à adapter la taille des tableaux dans `runLaxFriedrichScheme`
precision_mesh = 10e-3  # le résultat est très sensible 
precision_time = 10e-3  # aux variations de discrétisation
# Précisions que si l'on considère une "trop grande précision" l'affichage est très long
# on a l'impression que rien ne bouge mais si, seulement, comme il y a plus d'itérations à faire par seconde... c'est plus long!

nb_cells = 10 * int(1 / precision_mesh) 
nb_time_cells = 10 * int(1 / precision_time)

nb_ctrl_size = int(road_size / precision_mesh) - 2
#dx = road_size / (nb_ctrl_size - 2)  # le pas; le "- 2" correspond au fait d'avoir un maillage découpé tel que
                                     # [dx/2, dx, dx, ..., dx, dx/2]

def build_cells(optType, optPrecision):
    # Ces fonctions ont été conçues pour passer facilement du 1D au 2D (ce que nous ne faisons pas finalement)
    r_size, eps = optType, optPrecision
    # Générer un maillage utilisable par la méthode des volumes finis centrés aux nœuds

    nb_ctrl_size = int(r_size / eps)  # nb de pas de position
    #dx = r_size / (nb_ctrl_size - 2)  # le pas; le "- 2" correspond au fait d'avoir un maillage découpé tel que
    #self.nb_ctrl_size = nb_ctrl_size

    road_mesh_pos = np.linspace(0, r_size, num=nb_ctrl_size)
            # l'élément initial et l'élément final apparaissent deux fois dans le tableau pour que la méthode
            # "CENTERED_NODES" fonctionne
    road_mesh_pos = np.insert(road_mesh_pos, 0, 0)  # On ajoute le 0
    road_mesh_pos = np.append(road_mesh_pos, r_size)  # et l'élément final

    return road_mesh_pos

mesh = build_cells(road_size, precision_mesh)

def build_ctrl_mesh():

    road_centered_nodes = np.array([])

    idx = 1
    while idx < len(mesh) - 2:
        road_centered_nodes = np.append(road_centered_nodes, (mesh[idx] + mesh[idx + 1]) / 2)
        idx += 1

    return road_centered_nodes

control_mesh = build_ctrl_mesh()
dx = control_mesh[2] - control_mesh[1]

time_mesh = build_cells(time_length, precision_time)
dt = time_mesh[2] - time_mesh[1]

if DEBUG:
    print(dx)
    print(dt)
    print(mesh)
    print(time_mesh)

##################
# QUELQUES CHOCS #      
##################
def chocs_methode_carac():
    # En ayant suivi :
    # https://github.com/joannaww/Lighthill-Witham-Richards-Model/blob/main/Matuszak_Wojciechowicz.ipynb
    # On a surtout voulu expérimenter et voir ce qu'ils avaient fait.
    # Cette partie n'est pas fondamentale puisque l'on privilégie l'approche de Godunov.
    def f(rho, u_max, rho_max):
        f = u_max * rho * (1 - rho / rho_max)
        return f

    def u(rho, u_max, rho_max):
        u = f(rho, u_max, rho_max) / rho
        return u

    def red_green_light_X(u_max, t, ksi):
        if ksi < 0:    
            x = -u_max * t + ksi
        else:
            x = u_max * t + ksi
        return x

    rho_max = 1
    rho_l=0.4
    u_max = 1
    rho = np.linspace(0, rho_max, 100)

    u_max = 1
    ksi = np.linspace(-10,10,10)
    t = np.linspace(0, 10, 100)

    def traffic_jam_X(u_max, t, rho_max, rho_l, ksi):
        lst = []
        for i in ksi:
            if i < 0:
                x = u_max * t * (1 - 2 * rho_l / rho_max) + i
                condition = (x >= (u_max * rho_l**2 - u_max * rho_l * rho_max) / (rho_max * (rho_max - rho_l)) * t).all()
            else:
                x = -u_max * t + i
                condition = (x <= (u_max * rho_l**2 - u_max * rho_l * rho_max) / (rho_max * (rho_max - rho_l)) * t).all()
            
            if condition:
                x = np.nan
            lst.append(x)
        return (lst)

    print (traffic_jam_X(u_max, t, rho_max, rho_l, ksi))
    rho_max = 1
    rho_l = 0.4
    u_max = 1
    ksi = np.linspace(-10, 10, 50)
    t = np.linspace(0, 10, 100)

    for elem in traffic_jam_X(u_max, t, rho_max, rho_l, ksi):
        plt.plot(elem, t, 'black')
        
    x_red = (u_max * rho_l**2 - u_max * rho_l * rho_max) / (rho_max * (rho_max - rho_l)) * t
    plt.plot(x_red, t, 'red')

    plt.xlim(ksi[0], ksi[-1])
    plt.xlabel('x')
    plt.ylabel('t')
    plt.show()

#############################
# FIXER LA DENSITÉ INITIALE #      
#############################
def initial_density(option, nb_feux_rouge=1):
    # donner une liste d'option pour la densité initiale!
    # feu rouge (simple, double), bouchon...

    lst = []
    if option == "FEU_ROUGE":
        mid_mesh = int(nb_cells / 2)
        for i in range(0, mid_mesh): lst.append(1.0)
        for i in range(mid_mesh, nb_cells): lst.append(0.0)

        lst.pop(-1)

    elif option == "DOUBLE_FEU_ROUGE":  # 2 feux rouges F
                                        # voiture F      personne        voiture F       personne
        meshcut = int(nb_cells / 4)
        for i in range(0, meshcut): lst.append(1.0)
        for i in range(meshcut, 2 * meshcut): lst.append(0.0)
        for i in range(2 * meshcut, 3 * meshcut): lst.append(1.0)
        for i in range(3 * meshcut, nb_cells): lst.append(0.0)

        lst.pop(-1)

    # Suite à des modifications de dernière minute, cette option ne marche plus
    # pas grave
    #elif option == "FEU_ROUGE" and nb_feux_rouge != 0:
    #    meshcut = int(nb_cells / (2 * nb_feux_rouge))
    #    for j in range(0, 2 * nb_feux_rouge):
    #        to_append = 1.0 if (j % 2 == 0) else 0.0
    #        for i in range(j * meshcut, (j + 1) * meshcut): lst.append(to_append)
    #    #lst.pop(-1)

    elif option == "FREINAGE_BRUTAL":
        sigma = 0.1
        lst = [1 / np.sqrt(4 * np.pi * sigma) * np.exp(-(x - road_size / 2)**2 / (4 * sigma**2)) for x in control_mesh]

    elif option == "test_1":
        lst = [1/(x**2 + 1) * np.exp(-x) for x in control_mesh]

    elif option == "test_2":
        lst = [np.abs(1/(1 + np.sin(x)**2) * np.sin(x)) for x in control_mesh]

    elif option == "test_3":        # une entrée dans un bouchon !!!
        lst = [1/(1 + np.exp(-x**2 + 10)) for x in control_mesh]
    
    elif option == "test_4":        # la masse suit les premiers qui restent eux entre eux!
        lst = [np.abs(np.exp(-x**2 + 1) * np.sin(x) * np.cos(x)) for x in control_mesh]

    elif option == "ALEATOIRE_UNIFORME":
        lst = np.random.uniform(size=nb_cells - 1)
    
    elif option == "ALEATOIRE_UNIFORME_N_FEUX_ROUGES":
        # À corriger, ça ne marche pas pour toutes les valeurs de `nb_feux_rouges`
        # trouver l'erreur
        meshcut = int(nb_cells / (2 * nb_feux_rouge))
        for j in range(0, 2 * nb_feux_rouge):
            for i in range(j * meshcut, (j + 1) * meshcut): 
                to_append = np.random.uniform() if (j % 2 == 0) else 0.0
                lst.append(to_append)
        lst.pop(-1)

    elif option == "lineaire":
        pass

    else:
        lst = [1]

    if DEBUG:
        plt.plot(control_mesh, lst)
        plt.show()
    return lst

def flux(x):
    # Dans l'équation drho/dt + d{f(rho)}/dx = 0, le "flux" est la fonction f.
    v_max, rho_max = 0.2, 1
    return x * v_max * (1 - x / rho_max)

############################
# SCHÉMA DE LAX-FRIEDRICHS #      
############################
def LaxFriedrich(solution, cpt_flux, idx, jth_elem):
    # correction = max {|f'(u)|, u in 0, road_length}
    correction = 1

    bilan_flux_jplus = 1 / 2 * (cpt_flux[jth_elem] + cpt_flux[jth_elem + 1]) - correction / 2 * dx / dt * (solution[idx][jth_elem + 1] - solution[idx][jth_elem])
    #bilan_flux_jminus = 1/2 * (cpt_flux[jth_elem - 1] + cpt_flux[jth_elem]) - correction / 2 * dx / dt * (solution[idx][jth_elem] - solution[idx][jth_elem - 1])

    return bilan_flux_jplus #bilan_flux_jminus, bilan_flux_jplus

# Oublions le ce schéma là! C'était juste pour faire des tests
def localLaxFriedrich(solution, cpt_flux, idx, jth_elem):
    # Vaut mieux ne pas l'utiliser celle là!!! elle semble encore plus dépendante de la discrétisation que la version "globale"
    # de Lax Friedrich
    # correction = max {|f'(u)|, u dans [0, road_length]}
    def fprime(x):
        v_max, rho_max = 1, 1
        return - np.abs(v_max - 2 * v_max * x / rho_max) # le moins car on veut le max

    correction = minimize_scalar(fprime, bounds=(min(solution[idx][jth_elem], solution[idx][jth_elem + 1]), max(solution[idx][jth_elem], solution[idx][jth_elem + 1])), method="bounded")
    
    bilan_flux_jplus = 1/2 * (cpt_flux[jth_elem] + cpt_flux[jth_elem + 1]) - correction.x / 2 * dx / dt * (solution[idx][jth_elem + 1] - solution[idx][jth_elem])
    bilan_flux_jminus = 1/2 * (cpt_flux[jth_elem - 1] + cpt_flux[jth_elem]) - correction.x / 2 * dx / dt * (solution[idx][jth_elem] - solution[idx][jth_elem - 1])

    return bilan_flux_jminus, bilan_flux_jplus

def runLaxFriedrichScheme(mesh, time_mesh):
    t, idx = 0, 0
    solution = [initial_density("DOUBLE_FEU_ROUGE")]
    conservation_nb_voiture = []

    while t <= time_length:
        # À chaque pas de temps, on calcule les nouvelles positions
        new_pos = []
        
        circle_solution = np.concatenate(([solution[idx][-1]], solution[idx], [solution[idx][0]]))
        # On calcule les flux de la gauche vers la droite (on utilisera à la solution de l'itération précédente)
        # Il faut calculer les flux non pas sur les points de `control_mesh` mais sur ceux de `mesh` 
        # En bons physiciens que nous sommes, nous faisons l'approximation que lorsque la discrétisation est suffisamment
        # petite, les points de `control_mesh` et ceux de `mesh` sont confondus (+ que la condition initiale
        # n'admette pas de variations brutales, si elle en a il faut justement utiliser Godunov!!!)
        cpt_flux = flux(circle_solution)    

        last_bilan_flux = 0
        jth_elem = 0
        for elem in solution[idx]:

            if jth_elem + 1 == len(solution[idx]): pass
            else:
                bilan_flux_jplus = LaxFriedrich(solution, cpt_flux, idx, jth_elem)
                elem = elem - dt / dx * (bilan_flux_jplus - last_bilan_flux)

            jth_elem += 1            
            last_bilan_flux = bilan_flux_jplus
            new_pos.append(elem)

        conservation_nb_voiture.append(integrate.simpson(new_pos, dx=dx))
        solution.append(new_pos)

        print(t)
        t += dt 
        idx += 1           

    print(conservation_nb_voiture)

    fig, ax = plt.subplots()

    ax.set_xlim(0, road_size)
    ax.set_ylim(0, max(max(conservation_nb_voiture) + 0.1, 1.1))
            
    plt_sol, = plt.plot([], []) 
    plt_solexact, = plt.plot([], [])

    # Corrections à faire en fonction de la taille de la discrétisation :
    # différence de puissance entre precision_mesh et precision_time
    mesh, time_mesh = np.delete(mesh, 0), np.delete(time_mesh, 0)
    mesh, time_mesh = np.delete(mesh, -1), np.delete(time_mesh, -1)
    mesh = np.delete(mesh, -1)
    #mesh, time_mesh = np.delete(mesh, -1), np.delete(time_mesh, -1)

    def animate(i):
        plt_sol.set_data(mesh, solution[i])
        return plt_sol,

    ani = animation.FuncAnimation(fig, animate, repeat=True, frames=len(mesh) - 1, interval=1)
    plt.plot(time_mesh, conservation_nb_voiture)
    plt.show()

######################
# MÉTHODE DE GODUNOV #      
# (NE MARCHE PAS...) #      DOMMAGE
######################

def godunov():
    # On suit essentiellement https://pure.tue.nl/ws/portalfiles/portal/46911278
    # Mais cette partie ne marche pas donc grosse déception.

    riemMesh = np.linspace(-road_size / 2, road_size / 2, nb_cells)
    riemTime = np.linspace(0, time_length, nb_time_cells)

    h = riemMesh[1] - riemMesh[0]
    k = riemTime[1] - riemTime[0]

    x = lambda i: i * h # i dans Z
    ti = lambda n: n * k # n dans N

    x_half = lambda j: x(j) + h / 2

    # Définition des volumes de contrôle
    V = lambda j: [x_half(j - 1), x_half(j)] # j dans Z
    T = lambda time: [ti(time), ti(time + 1)] # time dans N

    allV = [V(j) for j in range(int(-road_size / (2 * h) ), int(road_size / (2 * h) + 1))]

    # on suit : https://ntnuopen.ntnu.no/ntnu-xmlui/bitstream/handle/11250/259317/730608_FULLTEXT01.pdf?sequence=3&isAllowed=y
    # page 50
    rho_left = 3/4
    rho_right = 1/4

    def initial_solution(x):
        lst = []

        for elem in x:
            if elem < 0:
                lst.append(rho_left)
            else: # attention au cas x = 0
                lst.append(rho_right)

        return lst

    # On utilise :
    # https://cermics.enpc.fr/cermics-rapports-recherche/1995/CERMICS-1995/CERMICS-1995-48.pdf page 7
    # https://www.uv.es/relativisticastrophysicsgroup/simulacionnumerica/node34.html 
    #def piecewiseConstantApprox(arr, n):
    #    # au temps n, approximation de la solution initiale par  
    #    tmp_ln = np.linspace(x(i), x(i + 1), 2)
    #    ret = []
    #
    #    for j in range(len(riemMesh)):
    #        
    #    return ret 
    

    def riemFlux(x):
        v_max, rho_max = 1, 1
        return x * v_max * (1 - x / rho_max)
    def invRiemFlux(x):
        v_max, rho_max = 1, 1
        return - x * v_max * (1 - x / rho_max) # le moins pour maximiser!


    #s = (riemFlux(rho_left) - riemFlux(rho_right)) / (rho_left - rho_right) # Condition de Rankine-Hugoniot
    #print(s)

    def riemmF(solution, idx, i, j):
    
        if solution[idx][i] <= solution[idx][i + 1]:
            #print(minimize_scalar(riemFlux, bounds=(solution[idx][i], solution[idx][j]), method="bounded").fun)
            return minimize_scalar(riemFlux, bounds=(solution[idx][i], solution[idx][j]), method="bounded").fun
        else:
            #print(minimize_scalar(invRiemFlux, bounds=(solution[idx][j], solution[idx][i]), method="bounded").fun)
            return minimize_scalar(invRiemFlux, bounds=(solution[idx][j], solution[idx][i]), method="bounded").fun

    #def scheme(solution, i, riemmF):
        # calcul du schéma à la position i au temps n
        #return solution[i] - k / h * (riemmF(solution, i, i + 1) - riemmF(solution, i - 1, i))
    
    def riemannExactSolve(rho_left, rho_right, conditionA, conditionB, conditionBB, speedi, speedii):
        
        if rho_left < rho_right: # Onde de choc
            #s = (riemFlux(rho_left) - riemFlux(rho_right)) / (rho_left - rho_right) # Rankine-Hugoniot
            #exactSol = [(elem < s ) * rho_left + (elem >= s) * rho_right for elem in riemMesh]
            exactSol = (0 < conditionA) * rho_left * speedi + (0 > conditionA) * rho_right * speedii

        else: # Onde de raréfaction / de détente
            #exactSol = [(elem < 1 - 2 * rho_left) * rho_left + (elem > 1 - 2 * rho_right) * rho_right \
            #            + (1 - 2 * rho_left < elem) * (elem <= 1 - 2 * rho_right) * (1 - elem) / 2 \
            #            for elem in riemMesh]
            exactSol = (0 < conditionB) * rho_left * speedi + (conditionB < 0) * (0 < conditionBB) * 1 / 4 * 1 * 1 + (0 < conditionBB) * rho_right * speedii
        return exactSol
    
    #print("======")
    #print(riemMesh)
    #plt.plot(riemannExactSolve(rho_left, rho_right))
    #plt.show()
    
    t, idx = 0, 0
    solution = [initial_solution(riemMesh)]
    while t < time_length:
        tmp_sol = []
        
        # on périodicise
        circle_solution = np.concatenate(([solution[idx][-1]], solution[idx], [solution[idx][0]]))
        for j in range(len(solution[idx])):
            # page 20 https://pure.tue.nl/ws/portalfiles/portal/46911278
            conditionZ = 1 - (circle_solution[j - 1] + circle_solution[j])
            conditionY = 1 - 2 * circle_solution[j - 1]
            conditionA, conditionB, conditionBB = 1 - (circle_solution[j] + circle_solution[j + 1]), \
                                                  1 - 2 * circle_solution[j], \
                                                  1 - 2 * circle_solution[j + 1]
            speedmi = 1 - circle_solution[j - 1]
            speedi, speedii = 1 - circle_solution[j], 1 - circle_solution[j + 1]

            flux_jplus = riemannExactSolve(circle_solution[j], circle_solution[j + 1], conditionA, conditionB, \
                                           conditionBB, speedi, speedii)
            flux_jmoins = riemannExactSolve(circle_solution[j - 1], circle_solution[j], conditionZ, conditionY, \
                                            conditionB, speedmi, speedi)
            new_elem = circle_solution[j] - k / h * (flux_jplus - flux_jmoins)
            tmp_sol.append(new_elem)

        #for i in range(len(riemMesh)):
            #if i == 0: tmp_sol.append(solution[i] - k / h * riemmF(solution, i, i + 1))
            #elif i == len(riemMesh): tmp_sol.append(solution[i] - k / h * riemmF(solution, i - 1, i))
            #else: 
            #right_flux = riemmF(circle_solution, riemFlux, i, i + 1)
            #left_flux = riemmF(circle_solution, invRiemFlux, i + 1, i)
            #flux = 1 / 2 * (right_flux + left_flux + h / k * (circle_solution[i - 1] - circle_solution[i]))
            # on moyenne sur la cellule de contrôle
            #if i == 0: sol_j_n = solution[idx][0]
            #elif i == len(riemMesh) - 1: sol_j_n = solution[idx][len(riemMesh) - 1]
            #else: sol_j_n = 1 / h * (solution[idx][i + 1] + solution[idx][i]) / 2
            #print(sol_j_n)
            #flux_r = riemmF(solution[idx], i, i + 1)
            #flux_l = riemmF(solution[idx], i - 1, i)
            #solsol = sol_j_n - k / h * (flux_r - flux_l)
                
        # Sur chaque cellule, on calcule la solution exacte
        #riemmProblem = [riemannExactSolve(vj[0], vj[1]) for vj in allV]
        #plt.plot(riemMesh, riemmProblem[30])
        #print(riemmProblem)

        #for i in range(len(riemMesh)):
        #    print(solution[idx])
            #if i == len(riemMesh)
        #    flux_r = riemmF(solution, idx, i, i + 1)
        #    flux_l = riemmF(solution, idx, i - 1, i)
        #    solsol = riemmProblem - k / h * (flux_r - flux_l)

        #    tmp_sol.append(riemmProblem)
        #    j += 1
        #print(nb_cells / 2 - 1)
        #print(j)
        #print("")
        #print("==============")

        #plt.plot(np.linspace(-road_size / 2, road_size / 2, j), tmp_sol)
        #plt.show()

        print(t / time_length) # % d'achèvement

        #tmp_sol[0] = circle_solution[idx][0]
        #tmp_sol[-1] = circle_solution[idx][-1]

        solution.append(tmp_sol)

        idx += 1
        t += dt
    
    
    print(len(solution))
    # Un exemple pour rho_left = 3/4, rho_right = 1/4
    def exactSol_rarefactionWave(x, t):
        lst = []
        
        for elem in x:
            if elem < -1 / 2 * t:
                lst.append(rho_left)
            elif (- 1 / 2 * t <= elem) and (elem <= 1 / 2 * t):
                lst.append(1 / 2 * (1 - elem / t))
            else:
                lst.append(rho_right)

        return lst
    
    fig, ax = plt.subplots()

    ax.set_xlim(-road_size/2, road_size/2)
    ax.set_ylim(0, 1.1)
            
    plt_sol, = plt.plot([], []) 

    def animate(i):
        plt_sol.set_data(riemMesh, exactSol_rarefactionWave(riemMesh, t(i)))
        return plt_sol,
    def animate2(i):
        plt_sol.set_data(riemMesh, solution[i])
        return plt_sol,        
    #riemmProblem = [riemannExactSolve(vj[0], vj[1]) for vj in allV]
    #def animate3(i):
    #    plt_sol.set_data(riemMesh, riemmProblem[i])
    #    return plt_sol,        

    
    ani2 = animation.FuncAnimation(fig, animate2, repeat=True, frames=len(riemMesh) - 1, interval=1)
    #ani = animation.FuncAnimation(fig, animate, repeat=True, frames=len(riemMesh) - 1, interval=1)
    #plt.plot(riemMesh, initial_solution(riemMesh), color="gray")
    plt.show()

####################
#                  #
# CE QUE L'ON VEUT #      En utilisant toutes les fonctions précédemment définies, on
#                  #      affiche ce qui nous intéresse
####################

#chocs_methode_carac()
runLaxFriedrichScheme(mesh, time_mesh)
#godunov()
