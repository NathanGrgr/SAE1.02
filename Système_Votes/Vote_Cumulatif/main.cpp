/*
 * Vote Cumulatif
 * Chaque attribue x nombre de points à chacun des candidats
 * Votant répartit 10 points pour tous les candidats
 * [[0,5,3,2][..]..]
 */


#include <iostream>
#include <vector>

using namespace std;


string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}


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



void affichVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

void affichVectInt (const vector<int> & v){
    for (const int & val : v)
        cout << val << ' ';
    cout << endl;
}


struct participant {
    string nom;
    string prenom;
    vector<int> classement;
};


void affichVectParticipants (const vector<participant> & vPart){
    for (const participant & part : vPart){
        cout << part.nom << endl;
        cout << part.prenom << endl;
        affichVectInt(part.classement);
    }
}



vector<int> election(const vector<vector<int>>& classement, const vector<string> vCandidat){
    vector<int> votesCumules(vCandidat.size(),0);

    for (size_t i(0); i < classement.size(); ++i){
        for (size_t j(0); j < vCandidat.size(); ++j){
            votesCumules[j]+=classement[i][j];
        }
    }
    return votesCumules;
}


int main()
{
    vector <string> vCandidat;
    size_t nbrCandidat = 4;
    for (unsigned i (0); i < nbrCandidat; ++i)
        vCandidat.push_back(litUneString());

    //affichVectString (vCandidat);

    vector<participant> vParticipant;
    size_t votants = 116;
    for (size_t i (0); i < votants; ++i){
        string nom =litUneString();
        string prenom =litUneString();
        vector<int> classement=litListe();
        //affichVectInt(classement);
        vParticipant.push_back(participant{nom, prenom, classement});
    }

    //affichVectParticipants(vParticipant);
    vector<vector<int>> classementParticipants;

    for (const auto& part : vParticipant) {
        classementParticipants.push_back(part.classement);
    }
    vector<int> listeelection;
    listeelection= election(classementParticipants,vCandidat);



    for (size_t i (0); i < listeelection.size(); ++i){
        cout << "Le candidat " << vCandidat[i] << " obtient " << listeelection[i] << " points" << endl;
    }
    int max = listeelection[0];
    int max_indice = 0;
    for (size_t i = 1; i < listeelection.size(); ++i) {
        if (listeelection[i] > max) {
            max = listeelection[i];
            max_indice = i;
        }
    }
    cout << "Le candidat " << vCandidat[max_indice] << " est élu avec " << max << " points issues des " << votants << " votants !" << endl;

    return 0;
}

