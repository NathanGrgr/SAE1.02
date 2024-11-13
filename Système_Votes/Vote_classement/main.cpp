/*
 * Vote à classement (Borda)
 * Chaque votant fait un classement des candidats
 * 1er : 4 points
 * 2e : 3 points
 * 3e : 2 points
 * 4e : 1 point
 * [[1,4,3,2][...]...]
 */

#include <iostream>
#include <vector>

using namespace std;

// Lit une chaîne de caractères depuis l'entrée standard, en ignorant les lignes commençant par "//"
string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

// Convertit une chaîne de caractères représentant une liste d'entiers en un vecteur d'entiers
vector<int> convertstrintovector(const string& chaine){
    string newchaine = chaine.substr(1, chaine.size()-2); // Enlève les crochets
    vector<int> vector;
    string element;
    for (char ch : newchaine){
        if (ch == ','){
            vector.push_back(stoi(element)); // Convertit et ajoute l'élément au vecteur
            element = "";
        }
        else {
            element += ch;
        }
    }
    vector.push_back(stoi(element)); // Ajoute le dernier élément
    return vector;
}

// Lit une liste d'entiers depuis l'entrée standard
vector<int> litListe (){
    string uneChaine;
    vector<int> liste;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    liste = convertstrintovector(uneChaine);

    return liste;
}

// Affiche un vecteur de chaînes de caractères
void afficheVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

// Affiche un vecteur d'entiers
void afficheVectInt (const vector<int> & v){
    for (const int & val : v)
        cout << val << ' ';
    cout << endl;
}

// Calcule les scores des candidats selon la méthode de Borda
vector<int> election(const vector<vector<int>>& classement,const vector <string> vCandidat) {

    vector<int> votesPremierePosition(vCandidat.size(),0);

    // Compte les votes pour la première position
    for (const auto & i : classement) {
        int premiercandidat = i[0] - 1;
        votesPremierePosition[premiercandidat]++;
    }
    size_t i = 0;
    while (i< votesPremierePosition.size()){
        votesPremierePosition[i]=votesPremierePosition[i]*4; // Multiplie par 4 les votes de la première position
        i++;
    }

    vector<int> votesDeuxiemePosition(vCandidat.size(),0);

    // Compte les votes pour la deuxième position
    for (const auto & i : classement){
        int deuxiemecandidat = i[1] - 1;
        votesDeuxiemePosition[deuxiemecandidat]++;
    }
    i = 0;
    while (i< votesDeuxiemePosition.size()){
        votesDeuxiemePosition[i]=votesDeuxiemePosition[i]*3; // Multiplie par 3 les votes de la deuxième position
        ++i;
    }

    vector<int> votesTroisiemePosition(vCandidat.size(),0);

    // Compte les votes pour la troisième position
    for (const auto& i : classement){
        int troisiemecandidat = i [2]-1;
        votesTroisiemePosition[troisiemecandidat]++;
    }
    i=0;
    while (i < votesTroisiemePosition.size()){
        votesTroisiemePosition[i]=votesTroisiemePosition[i]*2; // Multiplie par 2 les votes de la troisième position
        ++i;
    }

    vector<int> votesQuatriemePosition(vCandidat.size(),0);

    // Compte les votes pour la quatrième position
    for (const auto & i : classement){
        int quatriemecandidat = i[3]-1;
        votesQuatriemePosition[quatriemecandidat]++;
    }

    vector<int> votesBorda(vCandidat.size(),0);
    for (size_t i(0); i<4; ++i){
        votesBorda[i]=votesPremierePosition[i]+votesDeuxiemePosition[i]+votesTroisiemePosition[i]+votesQuatriemePosition[i];
    }

    return votesBorda;
}

// Structure représentant un participant avec son nom, prénom et classement
struct participant {
    string nom;
    string prenom;
    vector<int> classement;
};

// Affiche les informations des participants
void afficheVectParticipants (const vector<participant> & vPart){
    for (const participant & part : vPart){
        cout << part.nom << endl;
        cout << part.prenom << endl;
        afficheVectInt(part.classement);
    }
}

int main()
{
    vector <string> vCandidat;
    size_t nbrCandidat = 4;
    for (unsigned i (0); i < nbrCandidat; ++i)
        vCandidat.push_back(litUneString()); // Lit les noms des candidats

    vector<participant> vParticipant;
    size_t votants = 116;
    for (unsigned i (0); i < votants; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        vector<int> classement (litListe());

        vParticipant.push_back(participant{nom, prenom, classement}); // Ajoute un participant

    }

    vector<vector<int>> classementParticipants;

    for (const auto& part : vParticipant) {
        classementParticipants.push_back(part.classement); // Ajoute le classement du participant
    }

    vector<int> listeelection;
    listeelection= election(classementParticipants,vCandidat); // Calcule les scores des candidats
    for (size_t i (0); i < listeelection.size(); ++i){
        cout << "Le candidat " << vCandidat[i] << " obtient " << listeelection[i] << " points" << endl;
    }
    int max = listeelection[0];
    int max_indice = 0;

    // Trouve le candidat avec le score maximum
    for (size_t i = 1; i < listeelection.size(); ++i) {
        if (listeelection[i] > max) {
            max = listeelection[i];
            max_indice = i;
        }
    }

    int total_points = 0;
    for (const auto& points : listeelection) { total_points += points; }
    cout << "Le candidat " << vCandidat[max_indice] << " est élu avec " << max << " points sur un total de " << total_points << " points !" << endl;

    return 0;
}
