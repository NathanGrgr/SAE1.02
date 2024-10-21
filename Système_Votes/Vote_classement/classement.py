from random import *


#Chaque votant fait un classement de tous les candidats



votant=1000
candidat=5

def scrutin(candidat):
    scrutin=[]
    for i in range(votant):
        scrutin.append(sample(range(1,candidat+1),candidat))
    return scrutin

def election(scrutin):
    elec=[0]*candidat
    for i in range(len(scrutin)):
        nbr=scrutin[i][0]
        elec[nbr-1]+=1
    return(elec)



def test(liste):
    new_liste=[]
    for i in range(len(liste)):
        if liste[i]!=0:
            new_liste.append(liste[i])
    return new_liste

def majorite(elec,candidat):
    for i in range(len(elec)):
        if elec[i] >= votant/2 or len(elec)==2:
            print(elec)
            print("Candidat",elec.index(max(elec))+1,"Gagnant de l'élection")
            return

    temp_elec=test(elec)
    der=elec.index(min(temp_elec))+1
    candidat-=1
    print("Elimination du",der,"e candidat")
    print(elec[der-1],elec,candidat)
    
    scru=scrutin(candidat)
    elec=election(scru)
    majorite(elec,candidat)




if __name__=="__main__":
    scru=scrutin(candidat)
    elec=election(scru)
    majorite(elec,candidat)