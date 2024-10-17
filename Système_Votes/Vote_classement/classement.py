from random import *


#Chaque votant fait un classement de tous les candidats


scrutin=[]
votant=1000

for i in range(votant):
    

    for j in range(5):
        choix_votant=[1,2,3,4,5]
        shuffle(choix_votant)
        #Faire équivalent de shuffle en algo et en C++
    scrutin.append(choix_votant)

print(scrutin)