import glob, os
import re
import xml.etree.ElementTree as ET

from collections import Counter

import numpy as np
import matplotlib.pyplot as plt

#Wordcloud ?

os.chdir('/Users/Yapix/Desktop/Droit/Cours université/L2/Semestre 2/resp/')
file20212022 = open("20212022.txt", "w")

os.chdir('/Users/Yapix/Desktop/Droit/Cours université/L2/Semestre 2/resp/corpus/')

ctx = 0

globalText20212022 = []
INTEREST = ['responsabilité', 'responsabilités', 'responsable', 'responsables', 'irresponsable', 'irresponsables', 'irresponsabilité', 'irresponsabilités', 'responsabiliser', 'responsabilisé']
toDelete = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'le', 'la', 'les', 'je', 'tu', 'il', 'ils', 'elle', 'nous', 'vous',
            'une', 'un', 'en', 'des', 'dès', 'de', 'cette', 'cet', 'ces', 'ce', 'ses', 'se', 'est', 'ai', 'eu', 'eut', 'était',
            'êtes', 'serait', 'cas', 'aussi', 'après', 'avant', 'ans', 'an', 'puis', 'où', 'ou', 'dans', 'sur', 'afin', 'qu',
            'or', 'mais', 'nos', 'vos', 'ton', 'tes', 'te', 'même', 'me', 'ta', 'ma', 'mon', 'mes', 'donc', 'et', 'du', 'au', 'aux',
            'ne', 'pas', 'qui', 'que', 'dont', 'pour', 'avec', 'lui', 'votre', 'sont', 'notre', 'à', 'tout', 'toutes', 'tous',
            'monsieur', 'madame', 'm.', 'mme', 'rapporteur', 'président', 'présidente', '(', ')', '°', 'secrétaire', 'vu', ':', ';',
            'arrêt', 'dossier', 'séance publique', '-', 'c/', ',', '/', '.', '\"', '\'', 'société à responsabilité limitée', 'par', 'sa', 'été', 'son',
            'code', 'fait', 'leur', 'être', 'droit', 'part', 'premier', 'ont', 'ainsi', 'article', 'lieu', 'titre', 'dispositions', 'disposition', 'termes', 'janvier',
            'février', 'mars', 'avril', 'mai', 'juin', 'juillet', 'aout', 'septembre', 'octobre', 'novembre', 'décembre',
            'résulte', 'rejeté', 'rejet', 'plus', 'si', 'sans', 'peut', 'demandé', 'autre', 'liste', 'appel', 'demandé', 'suite', 'application',
            'droits', 'contre', 'conseil', 'faire', 'comme', 'données', 'soit', 'commis', 'commission', 'sous', 'notamment', 'présente', 'alors', 'pièce', 'laquelle',
            'avait', 'avoir', 'lors', 'ayant', 'personne', 'personnes', 'compter', 'non', 'date', 'er', 'sera', 'ci', 'faits', 'membre', 'pièces', 'lorsque',
            'doit', 'vertu', 'entre', 'conclusions', 'période', 'alinéa', 'leurs', 'examen', 'soumis', 'prévues', 'condamné', 'articles', 'ensemble', 'lequel', 'deuxième',
            'formation', 'applicable', 'celles', 'résultant', 'relatives', 'autres', 'centre', 'deux', 'mise', 'membres', 'égard', 'point', 'ressort', 'saint', 'chaque',
            'tour', 'ni', 'objet', 'celle', 'prononcer', 'engager', 'qualité', 'peuvent', 'mois', 'général', 'devant', 'toute', 'étaient', 'tant', 'relative',
            'demandeur', 'elles', 'présent', 'jusqu', 'engagé', 'union', 'projet', 'marseille', 'ii', 'pouvait', 'aucune', 'toutefois', 'assujettie', 'assujeti', 'effet',
            'attaqué', 'sens', 'année', 'doivent', 'dix', 'un', 'deux', 'trois', 'quatre', 'cinq', 'six', 'sept', 'huit', 'neuf', 'rédaction', 'annulation', 'enfin', 'août',
            'prévu', 'dispose', 'moins', 'troisième', 'quatrième', 'cinquième', 'nouveau', 'absence', 'celui', 'échéant', 'jugeant', 'entaché', 'chargé', 'également', 'sein', 'subis',
            'lorsqu', 'aurait', 'conformément', 'vue', 'tenu', 'prise', 'subi', 'portant', 'entrée', 'mis', 'tendant', 'instance', 'lesquelles', 'iii', 'issue', 'accord',
            'agissant', 'relevant', 'paris', 'estime', 'nouvelle', 'paragraphe', 'portée', 'ceux', 'face', 'première', 'fond', 'nombre', 'requérant', 'maître',
            'hauteur', 'moyen', 'motif', 'intérieur', 'éléments', 'circonstance', 'intéressé', 'second', 'prévue', 'selon', 'prendre', 'annuler', 'avis', 'cadre', 'sarl',
            'instruction', 'sociétés', 'dénaturé', 'ait', 'imputable', 'pris', 'destinées', 'fins', 'certains', 'directement', 'appartient', 'mentionnées', 'fin',
            'espèce', 'finot', 'partie', 'excès', 'refus', 'rechercher', 'conséquences', 'fondée', 'intervention', 'séjour', 'particulièrement', 'ouest', 'particulier', 'concernant',
            'prévoit', 'bordeaux', 'tel', 'cours', 'permis', 'livre', 'unipersonnelle', 'affectant', 'défaut', 'outre', 'encontre', 'fixé', 'constitue', 'moyens', 'pu',
            'susceptibles', 'niveau', 'professionnelle', 'prévus', 'conduit', 'pendant', 'telle', 'incidences','jour', 'vers', 'contagieux', 'compris', 'produits', 'mettre',
            'méconnaissance', 'dit', 'mentionné', 'préalable','demander', 'missions', 'déclaration', 'sieur', 'cons', 'attendu', 'considérant', 'déclaré', 'ladite', 'causé',
            'saurait', 'causé', 'sieurs', 'faisant', 'plaise', 'dame', 'là', 'vis', 'dé', 'dû', 'tort', 'aucun', 'agit', 'ailleurs', 'on', 'concerne', 'fondé', 'res',
            'décidé', 'engagée', 'déc', 'avaient', 'ledit', 'juill', 'delà', 'seulement', 'esp', 'nom', 'avr', 'exécutés', 'dernier', 'statuer', 'devait', 'due', 'janv',
            'eux', 'el', 'établi', 'auraient', 'min', 'nov', 'seul', 'motifs', 'soutenir', 'présentée', 'dessus', 'dire', 'nég', 'bon', 'rendu', 'envers', 'dudit', 'seine',
            'parties', 'déclarer', 'com', 'survenu', 'mémoire', 'rés', 'étant', 'oct', 'surplus', 'formée', 'malfaçons', 'grande', 'seule', 'encore', 'reconnu', 'veuve', 'pouvant',
            'contraire', 'connaître', 'faite', 'déclarée', 'aff', 'présenté', 'séraient', 'mêmes', 'moment', 'procédé', 'temps', 'provenant', 'depuis', 'observations', 'traité',
            'élé', 'appartenant', 'direction', 'donné', 'pronconées', 'lé', 'févr', 'donner', 'annulé', 'commise', 'dés', 'partir', 'dirigée', 'incombe', 'décharger', 'suivant', 'hors',
            'avaries', 'ordonner', 'subsidiairement', 'moitié', 'particuliers'}
        # Problème, les mots peuvent avoir des sens différents dans des contextes différents, mais là j'ai supprimé assez arbitrairement...



for file in glob.glob('*.xml'):

    tree = ET.parse(file)
#   print(file)
    root = tree.getroot()

# Pour uniformiser les textes :
    if root[2].tag != 'Audience':
        toAdd = ET.Element('Audience')
        root.insert(2, toAdd)
        tree.write(file)

    for x in root[3][0]:
        tmpctx = sum(x.text.count(statement) for statement in INTEREST)
        
        # Ca ne parle pas de resp ou autre ? On s'en fout alors !
        if tmpctx == 0:
            pass
        else:   # Cool, ça parle de resp ! On va regarder les mots du paragraphe alors !
            if 'condition' in x.text:
                file20212022.write(file + " :\n")
                file20212022.write(x.text)
                file20212022.write("\n\n -------------------------------------------- \n\n")

            x.text = x.text.lower()
            x.text = re.sub(r'[0-9]', '', x.text)

            globalText20212022.append(x.text)
            ctx += tmpctx


globalText20212022 = ''.join(globalText20212022)
globalText20212022 = [word for word in re.split("\W+", globalText20212022) if word.lower() not in toDelete]

ctn = Counter(globalText20212022)
print(ctn.most_common(n=200))

#print(ctx)

file20212022.close()


# On considère désormais la JP du CE de 1821 à 1939
os.chdir('/Users/Yapix/Desktop/Droit/Cours université/L2/Semestre 2/resp/')
f18211939 = open("18211939.txt", "w", encoding='utf-8')
os.chdir('/Users/Yapix/Desktop/Droit/Cours université/L2/Semestre 2/resp/corpus/1821 - 1939/')

ctx18211939 = 0

globalText18211939 = []

xYear = np.array([])
yFreqResp = np.array([])
yFreqRespPP = np.array([])

for file in glob.glob('*.txt'):
    
    file18211939 = open(file, 'r', encoding='utf-8')
    line = file18211939.readlines()

    year = 0
    if 'Date d\'édition : ' in line[21]:
        year = int(line[21][17:21])
        xYear = np.append(xYear, [year])
    else:
        for p in range(17, 21):
            if 'Date d\'édition : ' in line[p]:
                year = int(line[p][17:21])
                xYear = np.append(xYear, [year])
                

    localFreq, localFreqTmp = 0, 0
    localFreqRespPP = 0
    
    for text in line:
        localFreqTmp = sum(text.count(statement) for statement in INTEREST)
        if localFreqTmp == 0:
            pass
        else:
            localFreq += localFreqTmp

            if 'condition' in text and (('puissance publique' in text.lower()) or ('état' in text.lower()) or ('admin' in text.lower())):
                f18211939.write(file + " :\n")
                f18211939.write(text)
                f18211939.write("\n\n -------------------------------------------- \n\n")

            text = text.lower()
            text = re.sub(r'[0-9]', '', text)

            if ('puissance publique' in text) or ('état' in text) or ('admin' in text):
                localFreqRespPP += sum(text.count(statement) for statement in ['puissance publique', 'état', 'admin'])
                #localFreqRespPP += 1
                
            globalText18211939.append(text)
    yFreqResp = np.append(yFreqResp, [localFreq])
    yFreqRespPP = np.append(yFreqRespPP, [localFreqRespPP])
    file18211939.close()

# 1934 quadruple edition
yFreqResp[104] += (yFreqResp[105] + yFreqResp[106] + yFreqResp[107])
yFreqResp = np.delete(yFreqResp, [105, 106, 107])

yFreqRespPP[104] += (yFreqRespPP[105] + yFreqRespPP[106] + yFreqRespPP[107])
yFreqRespPP = np.delete(yFreqRespPP, [105, 106, 107])


# 1923 triple edition
yFreqResp[91] += (yFreqResp[92] + yFreqResp[93])
yFreqResp = np.delete(yFreqResp, [92, 93])

yFreqRespPP[91] += (yFreqRespPP[92] + yFreqRespPP[93])
yFreqRespPP = np.delete(yFreqRespPP, [92, 93])


# 1821 double edition
yFreqResp[0] += yFreqResp[1]
yFreqResp = np.delete(yFreqResp, [1])

yFreqRespPP[0] += yFreqRespPP[1]
yFreqRespPP = np.delete(yFreqRespPP, [1])


# On harmonise les années
xYear = np.unique(xYear)

plt.xlabel("Année")
plt.ylabel("Fréquence d'utilisation du terme \"responsabilité\" et de ses dérivés par le Conseil d\'État")

plt.plot(xYear, yFreqResp)
plt.plot(xYear, yFreqRespPP)

plt.plot(1855, yFreqRespPP[25], marker='+', color='k')
plt.plot(1873, yFreqRespPP[43], marker='+', color='k')
plt.plot(1895, yFreqRespPP[64], marker='+', color='k')
plt.plot(1911, yFreqRespPP[79], marker='+', color='k')
plt.plot(1918, yFreqRespPP[86], marker='+', color='k')
plt.plot(1919, yFreqRespPP[87], marker='+', color='k')
plt.plot(1923, yFreqRespPP[90], marker='+', color='k')
plt.plot(1938, yFreqRespPP[105], marker='+', color='k')


plt.show()

globalText18211939 = ''.join(globalText18211939)
globalText18211939 = [word for word in re.split("\W+", globalText18211939) if word.lower() not in toDelete]

ctn = Counter(globalText18211939)
print(ctn.most_common(n=200))
f18211939.close()
