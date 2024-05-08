import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation































"""
import warnings
import functools

# https://stackoverflow.com/a/30253848/6306995
def deprecated(func):
    """ """ This is a decorator which can be used to mark functions
    as deprecated. It will result in a warning being emitted
    when the function is used.""" """
    @functools.wraps(func)
    def new_func(*args, **kwargs):
        warnings.simplefilter('always', DeprecationWarning)  # turn off filter
        warnings.warn("Call to deprecated function {}.".format(func.__name__),
                      category=DeprecationWarning,
                      stacklevel=2)
        warnings.simplefilter('default', DeprecationWarning)  # reset filter
        return func(*args, **kwargs)
    return new_func

# faudrait faire une structure de graphe en étant capable de déterminer tous les voisins etc...
# class CtrlMesh............ qui s'adapterait bien même à des maillages non forcément réguliers! ou pas

# CONSTANTES
roadSize = 10  # taille de la route
maxTime = 1.0  # Temps de simulation
precision = 10e-1  # prendre precision < 1



class Geometry:

    def __init__(self, R_size, elements=[]):

        self.r_size = R_size
        self.road_elements = elements

        self.ROAD_ELEMENTS = ["RED-GREEN-LIGHTS", "STOP", "SPEED-BUMP"] # SPEED-BUMP = ralentisseur
        for elem in elements:
            assert(elem in self.ROAD_ELEMENTS)

    """ """
        Ajouter des éléments à la route
    """ """

    """ """
        Getters et setters
    """ """
    def get_roadSize(self):
        return self.r_size

    def get_roadElements(self):
        return self.road_elements

class Traffic:

    def __init__(self, initial_density, func):

        self.initial_density = initial_density # type : une fonction de la position (1D, 2D, 3D)
                                               #        ou un Dirac (valeurs discrètes pondérées sur la maille)
        self.solution = initial_density        # initialement, solution = solution initiale (logique)

        self.func = func 

    """ """
        Vérifications
    """ """
    def verify_density(self):
        return sum(self.initial_density) == 1
    
    """ """
        Getters et setters
    """ """
    def get_initialSolution(self):
        return list(self.initial_density)
    
    def get_solution(self):
        return list(self.solution)

    def set_solution(self, sol):
        self.solution = sol

    def get_funcConservation(self):
        return self.func

class RegularMesh:

    # si on ne veut pas initialiser d'office
    blankGeometry = Geometry(0)
    blankTraffic = Traffic([0], lambda x: 0)
    # LEVER UN NotImplementedError pour dimension >= 2 (pour l'instant ?)

    def __init__(self, T_size, precision, dimension, geometry=blankGeometry, traffic=blankTraffic):

        self.r_size = geometry.get_roadSize() # taille de la route
        self.t_size = T_size                  # temps de simulation
        self.eps = precision                  # prendre precision < 1
        self.dimension = dimension            # dimension du problème
        self.nb_ctrl_size = int(self.r_size / self.eps) # nombre de cellules de contrôle

        self.mesh = np.array([], dtype=object, ndmin=self.dimension)
        self.control_mesh = np.array([], dtype=object, ndmin=self.dimension)

        self.whole_mesh = sorted(np.append(self.mesh, self.control_mesh))

        self.road_elements = geometry.get_roadElements() # pour les éléments de la route, on ne va pas se casser la tête :
                                                         # ils sont répartis aléatoirement sur la route (avec une distance
                                                         # minimale entre chaque, donc lever erreur si distance minimale
                                                         # impossible à satisfaire)
        self.traffic = traffic.get_initialSolution() # on n'a que la solution à l'instant initial lors de l'initialisation
                                                                # logique
        self.animate_traffic = []
        
        self.func_conservation = traffic.get_funcConservation()
                                                                
        self.RULES = []

        self.NUMERICAL_SCHEME = ["GODUNOV", "LAX-FRIEDRICH"]
        self.CTRL_MESH_OPTIONS = ["CENTERED_NODES"]

        self.REGULAR_NEIGHBORS_POSITIONS_1D = ["LEFT", "RIGHT"]
        # self.REGULAR_NEIGHBORS_POSITIONS_2D = ["LEFT", "RIGHT", "TOP", "DOWN"] # Qui sait... on fera peut-être du 2D
        # Le 3D est un autre soucis (pas forcément plus problématique que le 2D)...
        
        self.PLOT_OPTIONS = ["POS_TIME", "TIME_POS"]


    """ """
        Construire les maillages des positions (avec ou sans les cellules de contrôle)
    """ """
    def build_mesh(self, r_size=roadSize, eps=precision):

        self.r_size = roadSize
        self.precision = precision
        
        if self.dimension == 1:

            # Générer un maillage utilisable par la méthode des volumes finis centrés aux nœuds

            nb_ctrl_size = int(r_size / eps)  # nb de pas de position
            dx = r_size / (nb_ctrl_size - 2)  # le pas; le "- 2" correspond au fait d'avoir un maillage découpé tel que
                                              # [dx/2, dx, dx, ..., dx, dx/2]
            self.nb_ctrl_size = nb_ctrl_size

            road_mesh_pos = np.linspace(0, r_size, num=nb_ctrl_size)
            # l'élément initial et l'élément final apparaissent deux fois dans le tableau pour que la méthode
            # "CENTERED_NODES" fonctionne
            road_mesh_pos = np.insert(road_mesh_pos, 0, 0)  # On ajoute le 0
            road_mesh_pos = np.append(road_mesh_pos, r_size)  # et l'élément final

            self.mesh = road_mesh_pos
            return road_mesh_pos
            
        else:
            raise NotImplementedError
    
    def build_ctrl_mesh(self, option="CENTERED_NODES"):
        assert(option in self.CTRL_MESH_OPTIONS)

        if self.dimension == 1:
            
            if option == "CENTERED_NODES":

                # Ajoutons des nœuds autour de chaque intervalle / volume de contrôle
                # On génère alors un tableau ne contenant que les nœuds (et pas les interfaces
                # qui elles sont contenues dans road_ctrl_mesh)
                road_centered_nodes = np.array([])

                # nœuds 1 à N
                idx = 1
                while idx < len(self.mesh) - 2:
                    road_centered_nodes = np.append(road_centered_nodes, (self.mesh[idx] + self.mesh[idx + 1]) / 2)
                    idx += 1

                self.control_mesh = road_centered_nodes
                return road_centered_nodes

            else:
                raise NotImplementedError

        else:
            raise NotImplementedError

    """ """
        Initialiser (comportement du trafic à l'état initial & "géométrie" des routes, manière dont se fait la circulation)

    """ """
    def initialize(self, geometry, traffic):

        self.r_size = geometry.get_roadSize()
        self.traffic = traffic.get_initialSolution() # on a là la solution initiale
        pass

    def rules(self):
        # Ensemble des règles (sorte de code de la route) à respecter
        pass
    
    """ """
        Construire les maillages POS x TIME(avec ou sans les cellules de contrôle)
    """ """
    def build_mesh_time(self, r_size=roadSize, t_size=maxTime, eps=precision):
        pass
    
    def build_ctrl_mesh_time(self, option="CENTERED_NODES"):
        assert(option in self.CTRL_MESH_OPTIONS)

        if self.dimension == 1:
            
            if option == "CENTERED_NODES":
                pass

        else:
            raise NotImplementedError

    """ """
        RÉSOUDRE L'EDP NUMÉRIQUEMENT
    """ """
    def adapt_initToMesh(self):
        # traiter la condition initiale pour qu'elle soit adaptée au maillage
        # on donne une liste étant la répartition de la densité sur le maillage

        xvals = self.control_mesh
        sol = self.traffic
        pt_to_interp = np.linspace(0, self.r_size, num=len(sol))

        # la solution initiale est alors interpolée en chaque point du maillage
        #plt.plot(xvals, np.interp(xvals, pt_to_interp, sol))
        #plt.show()
        plt.plot(xvals, np.interp(xvals, pt_to_interp, sol))
        return [xvals, np.interp(xvals, pt_to_interp, sol)]

    def compute_fluxes(self, time, elem, METHOD, dx, dt):
        assert(METHOD in self.NUMERICAL_SCHEME)
        
        if self.dimension == 1:

            if METHOD == "LAX-FRIEDRICH":
                # page 88 https://www2.math.ethz.ch/education/bachelor/lectures/fs2013/math/nhdgl/numcl_notes_HOMEPAGE.pdf
                # sauf que nous 1D : donc à A correspond juste la fonction f de drho/dt + df(rho)/dx = 0
                flux_value = 0
                
                # on veut obtenir les "voisins de cellule"!
                chers_voisins = self.get_neighbors(self.get_inElements(elem)) # obtenir les éléments voisins de l'élément dans la cellule

                flux_value += 1/2 * (self.func_conservation(chers_voisins[0]) + self.func_conservation(chers_voisins[1]))
                flux_value -= 1/2 * dx / dt * (self.func_conservation(chers_voisins[1]) - self.func_conservation(chers_voisins[0]))
                
                return flux_value
            else:
                raise NotImplementedError
        else:
            raise NotImplementedError

    # Très sans doute qu'il n'y a plus besoin de ça!
    @deprecated
    def compute_border_fluxes(self, time, elem, METHOD):
        assert(METHOD in self.NUMERICAL_SCHEME)
        
        if self.dimension == 1:
            return
        else:
            raise NotImplementedError

    def apply_scheme(self, option, animate=False):
        assert(option in self.NUMERICAL_SCHEME)

        # pour chaque point de la maille, on dispose de la densité initiale
        sol = self.adapt_initToMesh() # Attention à bien réinitialiser l'état du trafic si
                                      # on applique plusieurs fois le schéma !
        t = 0
        if self.dimension == 1:

            dx = self.r_size / (self.nb_ctrl_size - 2)   # le pas; le "- 2" correspond au fait d'avoir un maillage découpé tel que
                                                         # [dx/2, dx, dx, ..., dx, dx/2]
            dt = self.t_size / (self.nb_ctrl_size - 2)   # dt selon l'axe des ordonnées
        
            while t < self.t_size:
                # À chaque pas de temps, on calcule toutes les nouvelles positions

                new_pos = sol
                
                border_left_flux, border_right_flux = 0, 0
                left_flux, right_flux = 0, 0
                # Au fur et à mesure et à mesure que l'on itère, à un signe près,
                # le flux droit devient le flux droit! (il a déjà était calculé donc!)

                for i in range(len(sol[0])):
                    if animate: self.animate_traffic.append(new_pos[1][i]) #self.animate_traffic[i] = sol
                    print(new_pos[1][i])
                    print("ssss")

                    # Même si méthode utilisant get_meshBorders() coûte un peu plus cher,
                    # on comprend mieux son fonctionnement, elle est plus naturelle
                                
                    left_flux = right_flux
                    right_flux = self.compute_fluxes(t, sol[0][i], option, dx, dt)

                    if float(sol[0][i]) in self.get_ctrlMeshBorders():
                        # Le calcul des flux est différent pour les termes du bord.

                        #border_left_flux = border_right_flux
                        #border_right_flux = self.compute_fluxes(t, i, option, dx, dt)
                        #border_right_flux = self.compute_fluxes(t, i, option, dx, dt)

                        if sol[0][i] == self.get_ctrlMeshBorders()[0]: # si c'est le bord gauche
                            new_pos[1][i] = new_pos[1][i - 1] - dt / dx * (- left_flux)          
                        else: # si c'est le bord droit
                            new_pos[1][i] = new_pos[1][i - 1] - dt / dx * (right_flux)
                            
                    else:
                        # Calcule le flux que se prend au temps t l'élément i
                        #left_flux = right_flux
                        #right_flux = self.compute_fluxes(t, sol[0][i], option, dx, dt)

                        # À voir si on l'on veut garder en mémoire la densité! (et ainsi tracer
                        # l'évolution de la densité au cours du temps)
                        new_pos[1][i] = new_pos[1][i - 1] - dt / dx * (right_flux - left_flux)

                                                
                t += dt
            sol = new_pos
        else:
            raise NotImplementedError
        
        self.traffic_solution = sol

        return sol

    """ """
        Getters et setters
    """ """
    def get_inElements(self, elem):
        # Basé sur une position quelconque (pas forcément un point de la maille)
        # on retourne la cellule dans laquelle est le point (cad un entier)

        if self.dimension == 1:
            
            tmp = sorted(np.append(self.control_mesh, elem))

            if tmp.index(elem) == 0: return 0
            else: return tmp.index(elem) - 1
            
        else:
            raise NotImplementedError
    
    def get_neighbors(self, nth_elem):
        # retourner un tableau à 2^n éléments (e.g. n = 2: le point à gauche, celui à droite, celui en haut et celui en bas)
        # on obtient alors les points de contrôle sur la frontière de la cellule (centrée en) `elem`
        # en 1D, on obtient juste les points de contrôle à gauche et à droite d'un élément de self.mesh
        # ATTENTION SI ON EST SUR LES BORDS DE LA MAILLE
        
        if self.dimension == 1:
            # attention, 1er et dernier éléments
            if nth_elem == 0:
                return [self.control_mesh[0], self.control_mesh[1]]
            elif nth_elem == len(self.control_mesh):
                return [self.control_mesh[-2], self.control_mesh[-1]]
            else:
                return [self.control_mesh[nth_elem - 1], self.control_mesh[nth_elem + 1]]
        else:
            raise NotImplementedError
        
    def get_meshBorders(self):
        # le traitement des points sur le bord nécessite une attention toute particulière!
        
        if self.dimension == 1:
            return [self.mesh[0], self.mesh[-1]]
        else:
            raise NotImplementedError
        
    def get_ctrlMeshBorders(self):
        # le traitement des points sur le bord nécessite une attention toute particulière!
        
        if self.dimension == 1:
            return [self.control_mesh[0], self.control_mesh[-1]]
        else:
            raise NotImplementedError

        
    def get_mesh(self):
        return self.mesh

    def get_controlMesh(self):
        return self.control_mesh

    def get_wholeMesh(self):

        if self.dimension == 1:
            # utiliser un sorted est casse gueule pour autre chose que de la dimension 1 (étant donné qu'il n'y a pas
            # d'ordre canonique)
            self.whole_mesh = sorted(np.append(self.mesh, self.control_mesh))
            return self.whole_mesh

        else:
            raise NotImplementedError

    def get_solution(self):
        return self.traffic
        
    """ """
        AFFICHER LA GRILLE
    """ """
    def plot_mesh(self):
        
        if self.dimension == 1:

            # Voici la route!
            
            for elem in self.mesh: # Plot la maille
                plt.scatter(elem, 0, color="black", marker=".")
            for elem in self.control_mesh: # Plot les éléments de contrôle
                plt.scatter(elem, 0, color="blue", marker="+")

        else:
            raise NotImplementedError

        plt.show()

    def show(self, option, animate=False):
        assert(option in self.PLOT_OPTIONS)

        if animate==True:
            fig, ax = plt.subplots()
            ax.set_xlim(0, self.r_size)
            ax.set_ylim(0, self.t_size)
        
            x = np.linspace(0, self.r_size, self.nb_ctrl_size)
            plt_sol, = plt.plot([], []) 

            def animate(i):
                plt_sol.set_data(self.control_mesh, self.animate_traffic[i])
                return plt_sol,
            
            #print(self.animate_traffic)
            ani = animation.FuncAnimation(fig, animate, repeat=True, frames=len(x) - 1, interval=self.nb_ctrl_size)
        else:
            plt.plot(self.control_mesh, self.traffic_solution[1])
        plt.show()


def initial_density():
    # densité à l'instant initial
    # attention, quand on donne la densité initiale, il faut que l'on ait une valeur
    # pour chaque noeud de la maille, on sinon on les interpole!
    
    return list([0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0, 0, 0, 0, 0, 0])

def func_conservation(x):

    return x

# on ne peut pas dépasser
# faire plusieurs voies ?
# voitures / HUD
    # vitesse, taille uniforme (générer aléatoirement différentes tailles)
    # ---> voitures rigides
# feu rouge / stops / ....
# caractéristiques globales du trafic (densité initiale, heure, temps... ?)
# conditions initiales
# route pas forcément droite (utiliser fonction! et discrétiser)
# code de la route (distance sécu...)
# gestion des chocs / accidents!!! #~résolution des chocs!!!

# méthodes des caractéristiques (!!!)

# 1) la densité initiale répartit (uniformément) nos voitures
# 2) résolution

""" """
    ORDONNANCEMENT
""" """
grid = RegularMesh(maxTime, precision, dimension=1)

traffic = Traffic(initial_density(), func_conservation) # @todo
geometry = Geometry(roadSize, elements=[]) # @todo

grid.initialize(geometry, traffic) # dépend donc de rho_0 etc
grid.rules() # code de la route (règles simples), à faire!
 
grid.build_mesh() # dépend donc de la géométrie de la route, pour l'instant 1D
grid.build_ctrl_mesh()

grid.apply_scheme("LAX-FRIEDRICH", animate=True)
#grid.plot_mesh()
grid.show("POS_TIME", animate=True) # plot la solution; option : temps en fonction de la position, par exemple ou le contraire

#############
#############
#############






#############
#############
#############
"""





"""
np.warnings.filterwarnings('ignore', category=np.VisibleDeprecationWarning)                 

# CONSTANTES
R_size = 10  # taille de la route
T_size = 10  # Temps de simulation
precision = 10e-1  # prendre precision < 1




def gen_1D_mesh(r_size=R_size, eps=precision):
    # Générer un maillage utilisable par la méthode des volumes finis centrés aux nœuds

    nb_ctrl_size = int(r_size / eps)  # nb de pas de position
    #nb_ctrl_tmps = int(t_size / eps)  # nb de pas de temps
    dx = r_size / (nb_ctrl_size - 2)  # le pas; le "- 2" correspond au fait d'avoir un maillage découpé tel que
    # [dx/2, dx, dx, ..., dx, dx/2]

    road_ctrl_mesh_pos = np.linspace(0, r_size, num=nb_ctrl_size)
    # l'élément initial et l'élément final apparaissent deux fois dans le tableau pour que la méthode
    # "CENTERED_NODES" fonctionne
    road_ctrl_mesh_pos = np.insert(road_ctrl_mesh_pos, 0, 0)  # On ajoute le 0
    road_ctrl_mesh_pos = np.append(road_ctrl_mesh_pos, r_size)  # et l'élément final

    return road_ctrl_mesh_pos

def gen_1D_ctrl_mesh(option="CENTERED_NODES"):

    road_mesh = gen_1D_mesh()
    road_ctrl_mesh = np.array([[]])

    if option == "CENTERED_NODES":
        # Ajoutons des nœuds autour de chaque interval / volume de contrôle
        # On génère alors un tableau ne contenant que les nœuds (et pas les interfaces
        # qui elles sont contenues dans road_ctrl_mesh)
        road_centered_nodes = np.array([])

        # noeud 0
        #road_centered_nodes = np.append(road_centered_nodes, (road_mesh[0] + road_mesh[1]) / 2)

        # nœuds 1 à N
        idx = 1
        while idx < len(road_mesh) - 2:
            road_centered_nodes = np.append(road_centered_nodes, (road_mesh[idx] + road_mesh[idx + 1]) / 2)
            idx += 1

        road_ctrl_mesh = road_centered_nodes

    return road_ctrl_mesh

def gen_1D_mesh_time(r_size=R_size, t_size=T_size, eps=precision):
    # Générer un maillage utilisable par la méthode des volumes finis centrés aux nœuds

    nb_ctrl_size = int(r_size / eps)  # nb de pas de position
    nb_ctrl_tmps = int(t_size / eps)  # nb de pas de temps
    dx = r_size / (nb_ctrl_size - 2)  # le pas; le "- 2" correspond au fait d'avoir un maillage découpé tel que
    # [dx/2, dx, dx, ..., dx, dx/2]
    dt = t_size / (nb_ctrl_tmps - 2)  # dt selon l'axe des ordonnées

    road_mesh_pos_time = np.array([])
    
    road_mesh_pos = np.linspace(0, r_size, num=nb_ctrl_size)
    # l'élément initial et l'élément final apparaissent deux fois dans le tableau pour que la méthode
    # "CENTERED_NODES" fonctionne
    road_mesh_pos = np.insert(road_mesh_pos, 0, 0)  # On ajoute le 0
    road_mesh_pos = np.append(road_mesh_pos, r_size)  # et l'élément final

    t = 0
    while t <= t_size:
        to_add = np.array([t, road_mesh_pos])
        # to_add = np.concatenate((np.array([t]), road_ctrl_mesh_pos), axis = 0)
        road_mesh_pos_time = np.append(road_mesh_pos_time, np.array([to_add]))
        # attention, Numpy lève un Warning à cet endroit (VisibleDeprecationWarning) mais ça ne nous dérange pas.
        t += dt

    return road_mesh_pos_time


def gen_1D_ctrl_mesh_time(option="CENTERED_NODES", r_size=R_size, t_size=T_size, eps=precision):

    nb_ctrl_size = int(r_size / eps)  # nb de pas de position
    nb_ctrl_tmps = int(t_size / eps)  # nb de pas de temps
    dx = r_size / (nb_ctrl_size - 2)  # le pas; le "- 2" correspond au fait d'avoir un maillage découpé tel que
    # [dx/2, dx, dx, ..., dx, dx/2]
    dt = t_size / (nb_ctrl_tmps - 2)  # dt selon l'axe des ordonnées

    road_mesh_pos_time = np.array([])

    road_mesh = gen_1D_mesh()
    road_ctrl_mesh = np.array([[]])

    if option == "CENTERED_NODES":
        # Ajoutons des nœuds autour de chaque interval / volume de contrôle
        # On génère alors un tableau ne contenant que les nœuds (et pas les interfaces
        # qui elles sont contenues dans road_ctrl_mesh)
        road_centered_nodes = np.array([])

        # noeud 0
        #road_centered_nodes = np.append(road_centered_nodes, (road_mesh[0] + road_mesh[1]) / 2)

        # nœuds 1 à N
        idx = 1
        while idx < len(road_mesh) - 2:
            road_centered_nodes = np.append(road_centered_nodes, (road_mesh[idx] + road_mesh[idx + 1]) / 2)
            idx += 1


        road_ctrl_mesh_pos_time = np.array([])
        road_ctrl_mesh = road_centered_nodes

        t = 0
        while t <= t_size:
            to_add = np.array([t, road_ctrl_mesh])
        # to_add = np.concatenate((np.array([t]), road_ctrl_mesh_pos), axis = 0)
            road_ctrl_mesh_pos_time = np.append(road_ctrl_mesh_pos_time, np.array([to_add]))
        # attention, Numpy lève un Warning à cet endroit (VisibleDeprecationWarning) mais ça ne nous dérange pas.
            t += dt

    return road_ctrl_mesh_pos_time


def plot_1D_meshes():
    for elem in gen_1D_mesh():
        plt.scatter(elem, 0, color="black", marker=".")

    for elem in gen_1D_ctrl_mesh():
        plt.scatter(elem, 0, color="blue", marker="+")

def plot_1D_time_meshes():
    t = 0
    for elem in gen_1D_mesh_time():

        if isinstance(elem, float) or isinstance(elem, int): t = elem
        else: # si on a pas un temps, on plot
            for el in elem:
                plt.scatter(el, t, color="black", marker=".")

    for elem in gen_1D_ctrl_mesh_time():

        if isinstance(elem, float) or isinstance(elem, int): t = elem
        else: # si on a pas un temps, on plot
            for el in elem:
                plt.scatter(el, t, color="blue", marker="+")

#plot_1D_meshes()
plot_1D_time_meshes()
#plt.show()

"""



#############
#############
#############

"""
def gen_1D_mesh(r_size=R_size, t_size=T_size, eps=precision):
    # Générer un maillage utilisable par la méthode des volumes finis centrés aux nœuds

    nb_ctrl_size = int(r_size / eps)  # nb de pas de position
    nb_ctrl_tmps = int(t_size / eps)  # nb de pas de temps
    dx = r_size / (nb_ctrl_size - 2)  # le pas; le "- 2" correspond au fait d'avoir un maillage découpé tel que
    # [dx/2, dx, dx, ..., dx, dx/2]
    dt = t_size / (nb_ctrl_tmps - 2)
    
    # On construit le maillage.

    # D'abord, l'intervalle (pour la position)
    road_ctrl_mesh_pos = np.linspace(0, r_size, num=nb_ctrl_size)
    # l'élément initial et l'élément final apparaissent deux fois dans le tableau pour que la méthode
    # "CENTERED_NODES" fonctionne
    road_ctrl_mesh_pos = np.insert(road_ctrl_mesh_pos, 0, 0)  # On ajoute le 0
    road_ctrl_mesh_pos = np.append(road_ctrl_mesh_pos, r_size)  # et l'élément final

    #road_ctrl_mesh = road_ctrl_mesh_pos # tableau [[x, x, ..., x] au temps t0,
                                         #          [x, x, ..., x] au temps t1,
                                         #          ..........................,
                                         #          [x, x, ..., x] au temps tn]

    # Ensuite, idem pour le temps:
    #for tmp in range(nb_ctrl_tmps - 1):
    #    #road_ctrl_mesh = np.append(road_ctrl_mesh, np.array([road_ctrl_mesh_pos]))
    #    road_ctrl_mesh = np.concatenate((road_ctrl_mesh, road_ctrl_mesh_pos))

    return road_ctrl_mesh_pos

print(gen_1D_mesh())

def gen_1D_ctrl_mesh(option="CENTERED_NODES"):

    road_mesh = gen_1D_mesh()
    road_ctrl_mesh = np.array([[]])

    if option == "CENTERED_NODES":
        # Ajoutons des nœuds autour de chaque interval / volume de contrôle
        # On génère alors un tableau ne contenant que les nœuds (et pas les interfaces
        # qui elles sont contenues dans road_ctrl_mesh)
        road_centered_nodes = np.array([])

        # noeud 0
        #road_centered_nodes = np.append(road_centered_nodes, (road_mesh[0] + road_mesh[1]) / 2)

        # nœuds 1 à N
        idx = 1
        while idx < len(road_mesh) - 2:
            road_centered_nodes = np.append(road_centered_nodes, (road_mesh[idx] + road_mesh[idx + 1]) / 2)
            idx += 1

        road_ctrl_mesh = road_centered_nodes

    return road_ctrl_mesh

nb_ctrl_size = int(R_size / precision)  # nb de pas de position
dx = R_size / (nb_ctrl_size - 2)

nb_ctrl_tmps = int(T_size / precision)  # nb de pas de temps
dt = T_size / (nb_ctrl_tmps - 2)

t = 0
while t <= T_size:
    for i in gen_1D_mesh():
        plt.scatter(i, t, c="red")
        if t != T_size:
            plt.scatter(i, t + dt / 2, c="blue", marker="x")
    for j in gen_1D_ctrl_mesh():
        plt.scatter(j, t, c="blue", marker="x")
        plt.vlines(j, 0, R_size, linestyles="dashed")
        if t != T_size:
            plt.hlines(t + dt / 2, 0, T_size, linestyles="dashed")

    t += dt

plt.show()

# Le maillage est fait.
# Reste à poser et puis résoudre l'équation sur le maillage.
"""
