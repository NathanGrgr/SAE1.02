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

vector<int> convertir_chaine_en_vecteur(const string& chaine) {
    // Supprimer les crochets et extraire la chaîne contenant les nombres
    string chaine_sans_crochets = chaine.substr(1, chaine.size() - 2);

    vector<int> vecteur;
    string element;

    // Parcourir chaque caractère de la chaîne sans crochets
    for (char ch : chaine_sans_crochets) {
        if (ch == ',') {
            // Convertir l'élément en entier et l'ajouter au vecteur
            vecteur.push_back(stoi(element));
            element = "";  // Réinitialiser l'élément
        } else {
            element += ch;            // Ajouter le caractère à l'élément
        }
    }

    // Ajouter le dernier élément
    if (!element.empty()) {
        vecteur.push_back(stoi(element));
    }

    return vecteur;
}


vector<int> litClassement (){
    string uneChaine;
    vector<int> liste;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    liste = convertir_chaine_en_vecteur(uneChaine);

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


int election(const vector<vector<int>>& classement) {
    int votants = classement.size();
    int seuil = votants / 2;

    vector<int> votesPremierePosition(4,0);

    for (const auto & i : classement) {
        int premiercandidat = i[0] - 1;
        votesPremierePosition[premiercandidat]++;
        affichVectInt(votesPremierePosition);
        if (votesPremierePosition[premiercandidat] > seuil)
            return premiercandidat +1;
        else
            cout << "yoooooo" << endl;
    }
    return -1;
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



int main()
{
    vector <string> vGlacePref;
    for (unsigned i (0); i < 4; ++i)
        vGlacePref.push_back(litUneString());

    affichVectString (vGlacePref);

    vector<participant> vParticipant;

    for (unsigned i (0); i < 10; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        vector<int> classement (litClassement());

        vParticipant.push_back(participant{nom, prenom, classement});

        // affichVectInt(classement);
    }

    affichVectParticipants(vParticipant);
    vector<vector<int>> classementParticipants;
    for (const auto& part : vParticipant) {
        classementParticipants.push_back(part.classement);
    }

    int candidatelu;
    candidatelu = election(classementParticipants);
    cout << candidatelu << endl;

    return 0;
}
