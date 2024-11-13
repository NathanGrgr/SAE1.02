/*
 * Vote à majorité simple à 2 tours
 * Le candidat ayant le plus de voies gagne au 2nd tour
 * Candidat peut gagner au 1er tour si majorité
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Lit une chaîne depuis l'entrée standard en ignorant les lignes qui commencent par "//".
 * @return Une chaîne lue depuis l'entrée.
 */
string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

/**
 * Convertit une représentation de chaîne de caractères d'un vecteur d'entiers en un vrai vecteur d'entiers.
 * @param chaine La représentation de chaîne du vecteur.
 * @return Un vecteur d'entiers.
 */
vector<int> convertstrintovector(const string& chaine){
    string newchaine = chaine.substr(1, chaine.size()-2);
    vector<int> vector;
    string element;
    for (char ch : newchaine){
        if (ch == ','){
            vector.push_back(stoi(element));
            element = "";
        }
        else {
            element += ch;
        }
    }
    vector.push_back(stoi(element));
    return vector;
}

/**
 * Lit un classement depuis l'entrée standard et le convertit en un vecteur d'entiers.
 * @return Un vecteur d'entiers représentant le classement.
 */
vector<int> litClassement (){
    string uneChaine;
    vector<int> liste;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    liste = convertstrintovector(uneChaine);

    return liste;
}

/**
 * Structure représentant un participant.
 */
struct participant {
    string nom; ///< Le nom de famille du participant.
    string prenom; ///< Le prénom du participant.
    vector<int> classement; ///< Le classement du participant.
};

/**
 * Affiche le contenu d'un vecteur d'entiers.
 * @param v Le vecteur à afficher.
 */
void afficheVectInt (const vector<int> & v){
    for (const int & val : v)
        cout << val << ' ';
    cout << endl;
}

/**
 * Procède au premier tour de l'élection.
 * @param classement Le classement de tous les participants.
 * @param vCandidat La liste des candidats.
 * @return Un vecteur du nombre de votes pour chaque candidat.
 */
vector<int> election(const vector<vector<int>>& classement,vector<string> vCandidat){
    size_t votants = classement.size();
    int seuil = votants/2;
    vector<int> VoteDecompte(4,0);
    for (size_t i (0); i < votants; ++i){
        if (classement[i][0]==1){
            VoteDecompte[0]++;
        }
        else if (classement[i][0]==2){
            VoteDecompte[1]++;
        }
        else if (classement[i][0]==3){
            VoteDecompte[2]++;
        }
        else if (classement[i][0]==4){
            VoteDecompte[3]++;
        }
    }
    for (size_t i(0); i<VoteDecompte.size(); ++i){
        if (VoteDecompte[i]>seuil){
            return VoteDecompte;
        }
    }
    cout << "Début du 1er tour : " << endl;
    for (size_t i(0); i < VoteDecompte.size(); ++i){
        cout << "Le candidat " << vCandidat[i] << " a obtenu " << VoteDecompte[i] << " votes" << endl;
    }
    VoteDecompte.clear();
    return VoteDecompte;
}

/**
 * Procède au second tour de l'élection.
 * @param classement Le classement de tous les participants.
 * @return Un vecteur du nombre de votes pour chaque candidat au second tour.
 */
vector<int> election2etour(const vector<vector<int>>& classement){
    size_t votants = classement.size();
    vector<int> Vote2eDecompte(4,0);
    for (size_t i (0); i < votants; ++i){
        if (classement[i][1]==1){
            Vote2eDecompte[0]++;
        }
        else if (classement[i][1]==2){
            Vote2eDecompte[1]++;
        }
        else if (classement[i][1]==3){
            Vote2eDecompte[2]++;
        }
        else if (classement[i][1]==4){
            Vote2eDecompte[3]++;
        }
    }

    return Vote2eDecompte;
}

/**
 * Affiche le contenu d'un vecteur de chaînes.
 * @param v Le vecteur à afficher.
 */
void afficheVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

/**
 * Affiche les détails de tous les participants.
 * @param vPart Le vecteur de participants à afficher.
 */
void afficheVectParticipants (const vector<participant> & vPart){
    for (const participant & part : vPart){
        cout << part.nom << endl;
        cout << part.prenom << endl;
        afficheVectInt(part.classement);
    }
}

/**
 * Fonction principale pour procéder à l'ensemble du processus électoral.
 * @return 0 si le programme s'exécute avec succès.
 */
int main()
{
    vector <string> vCandidat;
    for (unsigned i (0); i < 4; ++i)
        vCandidat.push_back(litUneString());
    //afficheVectString (vCandidat);

    vector<participant> vParticipant;

    unsigned votants = 116;
    for (unsigned i (0); i < votants; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        vector<int> choix (litClassement());
        vParticipant.push_back(participant{nom, prenom, choix});
    }

    vector<vector<int>> classementParticipants;

    for (const auto& part : vParticipant)
        classementParticipants.push_back(part.classement);

    //[[1,2][..]..]
    vector<int> listeelection;
    listeelection= election(classementParticipants,vCandidat);
    int max_indice = 0;

    if (listeelection.size()!=0){
        int max = listeelection[0];

        for (size_t i = 1; i < listeelection.size(); ++i) {
            if (listeelection[i] > max) {
                max = listeelection[i];
                max_indice = i;
            }
        cout << "Le candidat " << vCandidat[max_indice] << " est élu avec " << max << " des voies au 1er tour sur un total de " << votants << " voies !" << endl;
            return 0;
        }
    }
    else{
        cout << "Aucun candidat n'a gagné à la majorité absolue" << endl;
        cout << "Debut du 2e tour : " << endl;
        listeelection=election2etour(classementParticipants);

        for (size_t i = 0; i < listeelection.size(); ++i){
            cout << "Le candidat " << vCandidat[i] << " a obtenu " << listeelection[i] << " votes" << endl;
        }

        //afficheVectInt(listeelection);
        int max = listeelection[0];
        for (size_t j(0); j < listeelection.size(); ++j){
            if (max < listeelection[j]){
                max=listeelection[j];
                max_indice=j;
            }
        }
        cout << "Le candidat " << vCandidat[max_indice] << " est élu avec " << max << " voies au 2e tour sur un total de " << votants << " voies !" << endl;
        return 0;
    }
}
