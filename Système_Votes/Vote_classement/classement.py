from random import *


#Chaque votant fait un classement de tous les candidats


scrutin=[]
votant=1000


def trouver_nombre_frequent(liste):
    max_count = 0
    nombre_frequent = liste[0]

    # Parcourir chaque élément unique de la liste
    for nombre in liste:
        count = 0
        # Compter combien de fois cet élément apparaît dans la liste
        for i in liste:
            if i == nombre:
                count += 1
        # Mettre à jour si un élément plus fréquent est trouvé
        if count > max_count:
            max_count = count
            nombre_frequent = nombre

    # Retourner le nombre le plus fréquent
    return nombre_frequent



for i in range(votant):
    

    for j in range(5):
        choix_votant=[1,2,3,4,5]
        shuffle(choix_votant)
        #Faire équivalent de shuffle en algo et en C++
    scrutin.append(choix_votant)

print(scrutin)