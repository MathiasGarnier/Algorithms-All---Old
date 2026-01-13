# IMPORTS
import os
import csv
import json
import argparse
import operator                         # comme on a pas le droit d'utiliser les fonctions anonymes...
import numpy as np
import pandas as pd
import seaborn as sns
from pathlib import Path
import matplotlib.pyplot as plt

CURRENT_PATH = Path.cwd()
CHARACTERS_PATH = CURRENT_PATH / 'data' / 'characters'
TXTs_PATH = CURRENT_PATH / 'data' / 'txt'

BOOKS_PATH = list(CHARACTERS_PATH.glob('*.book'))
TXTs_PATH = list(TXTs_PATH.glob('*.txt'))

BOOK_NAMES = [os.path.basename(txt_path) for txt_path in TXTs_PATH]
NB_BOOKS = len(BOOK_NAMES)

LEMMAs_NAME = ['agent', 'patient', 'mod', 'poss']

# Contrainte : utilisation d'internet limitée à la documentation officielle et Stackoverflow (pas de LLM et d'agent Copilot ou autre;
# ça a trop vibe codé pendant le HACKATHON) 
# En fin de compte j'ai utilisé gemini une seule et unique fois par manque de temps
# à cause d'un soucis avec argparse et l'addressage windows.


#######################################
#   ÉTAPE 1
#######################################

def verif_mention_ratio():
    # On vérifie que la somme de mention_ratio fait bien un pour être sûr que l'on ait bien compris
    # comment fonctionne globalement le bins
    for book in BOOKS_PATH:

        total = 0
        with open(book, encoding='utf-8') as json_book:
            jbook = json.load(json_book)

            for carac in jbook:
                total += carac['count']['mention_ratio']

        print(total)
        # Étrange, on obtient pas 1 (il manque des personnages ? ou je ne sais juste pas ce que représente mention_ratio)
        # ou sinon juste une troncature trop brutale

def get_main_characters_data(book, numChar=5, debug=False, total=False):
    # Récupérer les données associées aux principaux caractères pour un certain livre.
    # total pour obtenir tous les caractères
    
    mainChar_data = []
    with open(book, encoding='utf-8') as json_book:
        jbook = json.load(json_book)

        if debug:
            print(f"En tout, on a {len(jbook)} caractères. On ne sélectionne que les {numChar} principaux.")

        for carac in jbook:
            # On s'en fiche de faire un truc opti, ça aurait été mieux de passer par un dataframe sans doute.
            mainChar_data.append([carac['count']['mention_ratio'], carac])

        # https://docs.python.org/3/library/operator.html#operator.itemgetter
        # utiliser une fonction anonyme (lambda) aurait été mieux... mais bon
        mainChar_data.sort(key=operator.itemgetter(0), reverse=True)
        if debug:
            print(len(mainChar_data))
            print(mainChar_data[0:numChar][1])

    if total:
        mainChar_data_ret = [mainChar_data[0:len(mainChar_data)][i][1] for i in range(0, len(mainChar_data))]
    else:
        mainChar_data_ret = [mainChar_data[0:numChar][i][1] for i in range(0, numChar)]
    return mainChar_data_ret

def most_frequent_words_FROM_THE_BOOKS(number=100, numChar=5):
    """
    Créer une fonction qui parcourt l'ensemble des fichiers `.book` et construit une liste des 100 mots les plus fréquents 
    associés aux personnages, tous romans confondus (vous pouvez vous limiter aux 5 personnages les plus importants par roman). 
    Dans cet examen, les mots des personnages sont l'ensemble des lemmes présents dans les champs `agent`, `patient`, `mod`, `poss` 
    du dictionnaire. Chaque .book est à ouvrir comme un fichier json, qui comporte une liste de dictionnaires de personnages, listé 
    du premier personnage au dernier.
    """

    # Ce n'était pas absolument clair si l'on voulait les 100 mots les plus fréquents TOUS ROMANS CONFONDUS en considérant tous les
    # personnages sélectionnés ou si l'on voulait les 100 mots pour tous les romans POUR CHAQUE PERSONNAGE
    # Tout du moins, je ne comprends pas totalement si le "associés aux personnages" signifie que l'on souhaite les mots les
    # plus fréquents pour chaque personnage ou bien en agglutinant les personnages. (Voyant le nom de la première
    # variable définie ci-après, j'ai suivi la deuxième option ici)
    # Pour récupérer pour chaque personnage, c'est même plus simple : suffit de ne pas agglutiner et de considérer séparément.
    # Après relecture énoncé pdf, c'est toujours flou. La version courte semble faire privilégier le choix ici fait.
    # Néanmoins, a priori, il faudra tout de même faire l'autre version pour les sacs de mots (?). À voir.
    # Après rerelecture énoncé pdf, la consigne longue semble faire privilégier l'autre version, celle non ici faite. Mais doute.

    agglutiner_lemmes = {}

    #print(BOOKS_PATH)
    for book in BOOKS_PATH:
        
        #with open(book, encoding='utf-8') as json_book:
            #print(len(json.load(json_book)))
            #jbook = json.load(json_book)

        # Récupérer les 5 personnages les plus importants pour chaque roman.
        mainChar_data = get_main_characters_data(book, numChar=numChar, debug=False, total=False)
        #print(len(mainChar_data)) # 5 

        for carac in mainChar_data:
            
            for lemma in LEMMAs_NAME:
                current_lemma = carac[lemma]
                
                for elem in current_lemma:
                    
                    if elem['w'] not in agglutiner_lemmes:
                        agglutiner_lemmes[elem['w']] = 1 # oops i c'est l'indice et non l'idx_count # elem['i']
                    else:
                        agglutiner_lemmes[elem['w']] += 1 # elem['i']
                    
        # CASCADE DE FOR..........

    #print(type(agglutiner_lemmes))
    #print(len(agglutiner_lemmes))
    # https://stackoverflow.com/a/268285/6306995
    # avec une modification à apporter (utiliser items())
    #print(max(agglutiner_lemmes.items(), key=operator.itemgetter(1)))
    # on réutiliser un sort en fin de compte
    return sorted(agglutiner_lemmes.items(), key=operator.itemgetter(1), reverse=True)[0:number]


#######################################
#   ÉTAPE 2 & 3
#######################################

def total_number_tokens():
    total = 0
    for book in BOOKS_PATH:
        # Récupérer les 5 personnages les plus importants pour chaque roman.
        mainChar_data = get_main_characters_data(book, numChar=0, debug=False, total=True)
        #print(len(mainChar_data)) # 5 
        for carac in mainChar_data:
            for lemma in LEMMAs_NAME:
                current_lemma = carac[lemma]
                for _ in current_lemma:
                    total += 1
                 
    return total

def number_tokens_book(book):
    total = 0
    mainChar_data = get_main_characters_data(book, numChar=0, debug=False, total=True)
    #print(len(mainChar_data)) # 5 
    for carac in mainChar_data:
        for lemma in LEMMAs_NAME:
            current_lemma = carac[lemma]
            for _ in current_lemma:
                total += 1
                 
    return total    

def number_tokens_most_frequent_words():

    total = 0
    mfw = most_frequent_words_FROM_THE_BOOKS()

    for elem in mfw:
        #print(elem[1])
        total += elem[1]

    return total

def frequency_most_frequent_words_FROM_THE_BOOKS(number=100, onlyFreq=True, mfw_tokens=True):
    """
    Extraire la fréquence des **100 mots les plus fréquents** récupérés en étape #1.
    Pour chaque roman, divisez la fréquence brute par la somme totale des 100 mots les plus fréquents. 

    POUR TOUS LES LIVRES.
    """

    if mfw_tokens:
        # prendre juste les 100 mots les plus fréquents pour calculer le nombre total de mot (freq relative)
        total_number_of_tokens = number_tokens_most_frequent_words()
    else:
        total_number_of_tokens = total_number_tokens() # calculé sur l'ensemble total (tous les mots
                                                       # de tous les romans)

    mfw_books = most_frequent_words_FROM_THE_BOOKS()
    lst_ret = []
    for word, occ in mfw_books:
        if onlyFreq:
            lst_ret.append(occ / total_number_of_tokens)
        else:
            lst_ret.append((word, occ / total_number_of_tokens))
   
    return lst_ret    
        
def construct_bowRomans(number=100, numChar=5, onlyFreq=False, mfw_tokens=False, to_save='BoW_100_romans.csv'):
    
    # Supposons que les 100 mots les plus fréquents soient calculés à partir de 
    # most_frequent_words_FROM_THE_BOOKS()
    # Pour chaque roman, on souhaite déterminer la fréquence de chacun des mots
    # apparaissant dans la liste ci-dessus
    mfw = most_frequent_words_FROM_THE_BOOKS(number=number, numChar=numChar)    
    lst_words = [mfw[i][0] for i in range(0, number)]
    #lst_words_total_num = sum(mfw[i][1] for i in range(0, number))

    # Pour chaque roman
    lst_ret = []
    for book in BOOKS_PATH:

        mainChar_data = get_main_characters_data(book, numChar=numChar, debug=False)
        if mfw_tokens:
            # prendre juste les 100 mots les plus fréquents pour calculer le nombre total de mot (freq relative)
            total_number_of_tokens = number_tokens_most_frequent_words()
        else:
            # Doute sur la consigne mais ça semble plus cohérent de calculer la fréquence relative
            # pour chaque livre (quitte à faire une règle de trois, ça ne change rien; à une constante 
            # multiplicative près)
            # nombre total de tokens du livre book
            total_number_of_tokens = number_tokens_book(book)
            # En vrai, c'est sans doute mieux d'utiliser lst_words_total_num
            # mais comme dit avant, à une constante près, ça ne doit pas changer grand chose

        mfw_dict = dict(mfw)
        # https://stackoverflow.com/a/22991990/6306995
        mfw_dict = mfw_dict.fromkeys(mfw_dict, 0)

        for carac in mainChar_data:
    
           for lemma in LEMMAs_NAME:
               current_lemma = carac[lemma]
               
               for elem in current_lemma:
                   
                   if elem['w'] in lst_words:
                       mfw_dict[elem['w']] += 1

        mfw_dict = {k: v / total_number_of_tokens for k, v in mfw_dict.items()}
        lst_ret.append(mfw_dict)

    df = pd.DataFrame(lst_ret, index=BOOK_NAMES)
    df.to_csv(to_save)
    #print(df.shape)

    # pour le premier livre, étrange que "dire" revienne plus souvent que "avoir"
    return df    

def get_genres():
    """
    Récupérer le genre de seulement les textes nous intéressant.
    """

    genre_files = 'genre_labels.json'
    dict_genre = {}
    with open(CURRENT_PATH / genre_files, encoding='utf-8') as json_genre:
        jgenre = json.load(json_genre)
        # Attention, dans ce fichier, il y a 20 textes et non 10 
        # (certains n'apparaissent pas dans le corpus)
        
        #print(jgenre['texts'][1])
        texts = jgenre['texts']
        for i in range(len(texts)):
            # On récupère uniquement les textes qui nous intéressent
            if texts[i]['title'] in BOOK_NAMES:
                #print(jgenre['texts'][i]['title'])

                dict_genre[texts[i]['title']] = texts[i]['genre']

    return dict_genre

def split_genres(dict_genre):
    # On a deux genres : policier et sentimental
    # pour chaque genre : amalgamer et moyenner les vecteurs obtenus dans le bow 
    genre_policier, genre_sentimental = {}, {}

    for key, values in dict_genre.items():
        if values == 'policier':
            # Pas propre mais ça marche (ça split effectivement)
            genre_policier[key] = values
        else:
            genre_sentimental[key] = values

    return genre_policier, genre_sentimental

def construct_bowGenres(to_save='BoW_100_genres.csv'):
    """
    Calculez le vecteur moyen pour chacun des deux genres romanesques, convertissez cela sous la forme d'un dataframe avec deux lignes, `policier` et `sentimental` (les labels sont à charger avec le fichier `genre_labels.json`).
    Sauvegarder ce DataFrame sous le nom `BoW_100_genres.csv`.
    """
    dict_genre = get_genres()
    policier, sentimental = split_genres(dict_genre)
    policier_keys, sentimental_keys = list(policier.keys()), list(sentimental.keys())
    bow = construct_bowRomans()

    #print(list(policier.keys())[0])
    #print(bow.loc(policier_keys[0]))
    bow = bow.T 
    #print(bow[sentimental_keys[0]].head())
    #print(bow[sentimental_keys[1]].head())
    #print((bow[sentimental_keys[0]] + bow[sentimental_keys[1]]).head())

    # On aurait pu créer une fonction pour créer les pd.Series
    ds_pol = pd.Series(0, index=bow.index)
    for pol_keys in policier_keys:
        ds_pol = ds_pol + bow[pol_keys] 
        #print(bow[pol_keys].head(2))
    ds_pol = ds_pol / len(policier_keys)

    ds_sentimental = pd.Series(0, index=bow.index)
    for sent_keys in sentimental_keys:
        ds_sentimental = ds_sentimental + bow[sent_keys] 
    ds_sentimental = ds_sentimental / len(sentimental_keys)

    df = pd.concat([ds_pol, ds_sentimental], axis=1)
    df = df.T
    df.index = ['policier', 'sentimental']

    df.to_csv(to_save)

    return df

def construct_bowPersonnages(number=100, numChar=5, onlyFreq=False, mfw_tokens=False, to_save='BoW_100_personnages.csv'):
    # Pour chaque roman, pour chacun des numChar=5 personnages les plus importants
    # recréer un bow
    # on s'attend à avoir un df.shape = (10 * numChar, 100)

    mfw = most_frequent_words_FROM_THE_BOOKS(number=number, numChar=numChar)    
    lst_words = [mfw[i][0] for i in range(0, number)]
    # Même questionnement sur lst_words_total_num que dans construct_bowRomans
    #lst_words_total_num = sum(mfw[i][1] for i in range(0, number))
    # mais pour rester cohérent, on réutilise la convention adoptée précédemment.

    # Pour chaque roman
    lst_ret = []
    for book in BOOKS_PATH:

        mainChar_data = get_main_characters_data(book, numChar=numChar, debug=False)
        if mfw_tokens:
            # prendre juste les 100 mots les plus fréquents pour calculer le nombre total de mot (freq relative)
            total_number_of_tokens = number_tokens_most_frequent_words()
        else:
            # Doute sur la consigne mais ça semble plus cohérent de calculer la fréquence relative
            # pour chaque livre (quitte à faire une règle de trois, ça ne change rien; à une constante 
            # multiplicative près)
            # nombre total de tokens du livre book
            total_number_of_tokens = number_tokens_book(book)
            # En vrai, c'est sans doute mieux d'utiliser lst_words_total_num
            # mais comme dit avant, à une constante près, ça ne doit pas changer grand chose

        # On calcule pour chaque caractère
        lst_carac = []
        for carac in mainChar_data:
            mfw_dict = dict(mfw)
            # https://stackoverflow.com/a/22991990/6306995
            mfw_dict = mfw_dict.fromkeys(mfw_dict, 0)

            for lemma in LEMMAs_NAME:
               current_lemma = carac[lemma]
               
               for elem in current_lemma:
                   
                   if elem['w'] in lst_words:
                       mfw_dict[elem['w']] += 1

            mfw_dict = {k: v / total_number_of_tokens for k, v in mfw_dict.items()}
            lst_carac.append(mfw_dict)
        lst_ret.append(lst_carac)

    #print(len(lst_ret[0][0]))
    #pd.DataFrame(lst_ret, index=BOOK_NAMES) donne directement un résultat exploitable
    # mais c'est vrai qu'il n'est pas très beau.

    #au final on n'utilise même pas tmp_df
    #tmp_df = pd.DataFrame(lst_ret, index=BOOK_NAMES)
    #print(tmp_df.head(1))
    # à vrai dire, on aurait pu construire immédiatement le cleaned_df
    # néanmoins, pour clarté et pour découper tâche plus proprement
    # on le fait en deux étapes distinctes
    # Viens donc la création de cleaned_df
    augmented_index = [book_name + '__' + str(i) for book_name in BOOK_NAMES for i in range(numChar) ]
    #print(augmented_index)
    cleaned_df = pd.DataFrame(None, index=augmented_index, columns=lst_words)

    book_num = 0
    for book_name in BOOK_NAMES:
        for i in range(numChar):
            cleaned_df.loc[book_name + '__' + str(i)] = lst_ret[book_num][i]

        book_num += 1

    cleaned_df.to_csv(to_save)
    return cleaned_df

#######################################
#   ÉTAPE 4
#######################################

def cosine_similarity(a, b):
    # Ça vient du prod scalaire canonique sur R^n
    return np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b))

def cosine_bow_book_carac(doc_romans, doc_perso, numChar=5, to_save='distances_personnages_romans.csv'):
    # Calculer la distance cosinus entre le bow du roman book et celui de 
    # chacun de ses numChar=5 personnages principaux
    
    bow_book_file = doc_romans #'BoW_100_romans.csv'
    bow_perso_file = doc_perso #'BoW_100_personnages.csv'

    # Charger les données
    #with open(bow_book_file, mode='r', encoding='utf-8') as csv_bow_book:
    #    csv_file = csv.reader(csv_bow_book)
    #    for book in csv_file:
    #        print(book)
    # On va utiliser pandas plutôt 

    # Attention si on utilise un numChar différent de 5, faudra penser à
    # regénérer au préalable les csv avec le bon nombre de personnages
    csv_bow_book = pd.read_csv(bow_book_file, index_col=0, header=0)
    csv_bow_perso = pd.read_csv(bow_perso_file, index_col=0, header=0)
    #print(csv_bow_book)
    
    df_cos = pd.DataFrame(0, index=BOOK_NAMES, columns=[i for i in range(numChar)], dtype=float)
    # Est-ce bien cette matrice qui est demandée ?

    book_num = 0
    for book_name in BOOK_NAMES:
        for i in range(numChar):
            df_cos.loc[book_name, i] = cosine_similarity(csv_bow_book.loc[book_name], csv_bow_perso.loc[book_name + '__' + str(i)])
        book_num += 1

    df_cos.to_csv(to_save)

    return df_cos

def cosine_bow_book_genre(doc_genres, doc_perso, numChar=5, to_save='distances_personnages_genres.csv'):
    # On s'occupe désormais du genre

    # Rappel: comme ci-dessus, faire attention à numChar si modification
    bow_genre_file = doc_genres #'BoW_100_genres.csv'
    bow_perso_file = doc_perso #'BoW_100_personnages.csv'
    
    csv_bow_genre = pd.read_csv(bow_genre_file, index_col=0, header=0)
    csv_bow_perso = pd.read_csv(bow_perso_file, index_col=0, header=0)

    df_cos = pd.DataFrame(0, index=BOOK_NAMES, columns=[i for i in range(numChar)], dtype=float)
    # Est-ce bien cette matrice qui est demandée ?

    #book_num = 0
    #Ça fait pas trop de sens de faire ça mais j'ai l'impression que c'est ce que demande la consigne
    # for genre in ['policier', 'sentimental']: # on n'a que 2 genres
    #     for i in range(numChar):
    #         book_name = BOOK_NAMES[i]
    #         df_cos.loc[genre, i] = cosine_similarity(csv_bow_genre.loc[genre], csv_bow_perso.loc[book_name + '__' + str(i)])

    #     book_num += 1

    #Ahhh! je crois que j'ai compris ce qui est demandé:
    # prendre la similarité cosinus entre le genre dudit roman et perso1, puis perso2, ...

    genres = get_genres()

    book_num = 0
    for book_name in BOOK_NAMES:
        book_genre = genres[book_name]
        #print(book_genre)
        for i in range(numChar):
            df_cos.loc[book_name, i] = cosine_similarity(csv_bow_genre.loc[book_genre], csv_bow_perso.loc[book_name + '__' + str(i)])
        book_num += 1

    df_cos.to_csv(to_save)

    return df_cos

#######################################
#   ÉTAPE 5
#######################################

def visualize_cosine_bow_carac(doc_romans, doc_perso):
    # Visualiser matrice sauvegardée dans distances_personnages_romans.csv
    cosine_bow_carac = cosine_bow_book_carac(doc_romans, doc_perso)

    sns.heatmap(cosine_bow_carac, cmap='viridis')
    plt.gca().set_aspect('equal') # Pour que l'image soit moins déformée.
    plt.show()

def visualize_cosine_bow_genre(doc_genres, doc_perso):
    # Visualiser matrice sauvegardée dans distances_personnages_genres.csv
    cosine_bow_genre = cosine_bow_book_genre(doc_genres, doc_perso)

    sns.heatmap(cosine_bow_genre, cmap='viridis')
    plt.gca().set_aspect('equal') # Pour que l'image soit moins déformée.
    plt.show()

def visualize_bonus_cosine_bow_carac(doc_romans, doc_perso):
    # Une autre manière de visualiser les résultats

    # Visualiser matrice sauvegardée dans distances_personnages_romans.csv
    cosine_bow_carac = cosine_bow_book_carac(doc_romans, doc_perso)

    sns.violinplot(cosine_bow_carac.T, inner="point", density_norm="count")
    #plt.gca().set_aspect('equal') # Pour que l'image soit moins déformée.
    plt.xticks(rotation=90)
    plt.show()

def visualize_bonus_cosine_bow_genre(doc_genres, doc_perso):
    # Visualiser matrice sauvegardée dans distances_personnages_genres.csv
    cosine_bow_genre = cosine_bow_book_genre(doc_genres, doc_perso)

    sns.violinplot(cosine_bow_genre.T, inner="point", density_norm="count")
    #plt.gca().set_aspect('equal') # Pour que l'image soit moins déformée.
    plt.xticks(rotation=90)
    plt.show()


if __name__ == "__main__":
    
    parser = argparse.ArgumentParser(description="Tenter de répondre aux questions de l'examen parce que j'avoue que je suis pas certain d'avoir compris toutes les questions / d'avoir fait les choses attendues.")

    parser.add_argument("-ia", help="Chemin (input) vers le dossier contenant les fichiers .txt")
    parser.add_argument("-ib", help="Chemin (input) vers le dossier contenant les fichiers .book")
    parser.add_argument("-oa", help="Chemin (output) vers le fichier BoW_100_romans.csv")
    parser.add_argument("-ob", help="Chemin (output) vers le fichier BoW_100_genres.csv")
    parser.add_argument("-oc", help="Chemin (output) vers le fichier BoW_100_personnages.csv")
    parser.add_argument("-od", help="Chemin (output) vers le fichier distances_personnages_romans.csv")
    parser.add_argument("-oe", help="Chemin (output) vers le fichier distances_personnages_genres.csv")

    args = parser.parse_args()

    # REDEFINIR TXTs_PATH & BOOKS_PATH
    # ici c'est complètement inutile car on va obtenir strictement
    # le même résultat, la seule différence ? le chemin est donné en ligne de commande
    if args.ia:
        TXTs_PATH = list(Path(args.ia).glob('*.txt'))
    
    if args.ib:
        BOOKS_PATH = list(Path(args.ib).glob('*.book'))

    construct_bowRomans(number=100, numChar=5, onlyFreq=False, mfw_tokens=False, to_save=args.oa)
    construct_bowGenres(to_save=args.ob)
    construct_bowPersonnages(number=100, numChar=5, onlyFreq=False, mfw_tokens=False, to_save=args.oc)
    cosine_bow_book_carac(args.oa, args.oc, numChar=5, to_save=args.od)
    cosine_bow_book_genre(args.ob, args.oc, numChar=5, to_save=args.oe)

    # Enfin, pour les visualisations :
    print("VISUALISATIONS (en vrai faudrait mettre des titres etc...)")
    # Comme le dit si bien AlphaWann: 
    # J'aime pas stagner, je suis un développeur, je visualise et j'évite de tomber

    # METTRE accès .csv à jour en utilisant args
    visualize_cosine_bow_carac(args.oa, args.oc)
    visualize_cosine_bow_genre(args.ob, args.oc)
    visualize_bonus_cosine_bow_carac(args.oa, args.oc)
    visualize_bonus_cosine_bow_genre(args.ob, args.oc)
