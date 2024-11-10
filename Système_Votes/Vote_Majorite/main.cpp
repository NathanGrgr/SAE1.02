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

// vector<int> convertstrintovector(const string& chaine){
//     string newchaine = chaine.substr(1, chaine.size()-2);
//     vector<int> vector;
//     string element;
//     for (char ch : newchaine){
//         if (ch == ','){
//             vector.push_back(stoi(element));
//             element = "";
//         }
//         else {
//             element += ch;
//         }
//     }
//     vector.push_back(stoi(element));
//     return vector;
// }

vector<int> convertstrintovector(const string& chaine) {
    if (chaine.size() < 2 || chaine.front() != '[' || chaine.back() != ']') {
        throw invalid_argument("Invalid format: Expected format [1,2,3]");
    }

    string newchaine = chaine.substr(1, chaine.size() - 2);
    vector<int> vector;
    string element;

    for (char ch : newchaine) {
        if (ch == ',') {
            if (!element.empty()) {
                try {
                    vector.push_back(stoi(element));
                } catch (const invalid_argument& e) {
                    cerr << "Invalid integer: " << element << endl;
                }
                element.clear();
            }
        } else {
            element += ch;
        }
    }

    // Push the last element after the loop
    if (!element.empty()) {
        try {
            vector.push_back(stoi(element));
        } catch (const invalid_argument& e) {
            cerr << "Invalid integer: " << element << endl;
        }
    }

    return vector;
}


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

struct participant {
    string nom;
    string prenom;
    vector<int> classement;
};


void affichVectInt (const vector<int> & v){
    for (const int & val : v)
        cout << val << ' ';
    cout << endl;
}



vector<int> election(const vector<vector<int>>& classement){
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
    VoteDecompte.clear();
    return VoteDecompte;
}



vector<int> election2etour(const vector<vector<int>>& classement){
    size_t votants = classement.size();
    vector<int> Vote2eDecompte(4,0);
    for (size_t i (0); i < votants; ++i){
        if (classement[i][1]==1){
            Vote2eDecompte[0]++;
        }
        else if (classement[i][2]==2){
            Vote2eDecompte[1]++;
        }
        else if (classement[i][0]==3){
            Vote2eDecompte[2]++;
        }
        else if (classement[i][0]==4){
            Vote2eDecompte[3]++;
        }
    }
    affichVectInt(Vote2eDecompte);


    return Vote2eDecompte;
}

void affichVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

void affichVectParticipants (const vector<participant> & vPart){
    for (const participant & part : vPart){
        cout << part.nom << endl;
        cout << part.prenom << endl;
    }
}

int main()
{
    vector <string> vCandidat;
    for (unsigned i (0); i < 3; ++i)
        vCandidat.push_back(litUneString());
    affichVectString (vCandidat);

    vector<participant> vParticipant;

    unsigned votants = 10;
    for (unsigned i (0); i < votants; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        vector<int> choix (litClassement());
        vParticipant.push_back(participant{nom, prenom, choix});
    }

    vector<vector<int>> classementParticipants;
    for (const auto& part : vParticipant)
        classementParticipants.push_back(part.classement);


    vector<int> listeelection;
    listeelection= election(classementParticipants);
    int max_indice = 0;
    int max = listeelection[0];
    if (listeelection.size()!=0){
        int max = listeelection[0];


        for (size_t i = 1; i < listeelection.size(); ++i) {
            if (listeelection[i] > max) {
                max = listeelection[i];
                max_indice = i;
            }
        cout << "Le candidat " << max_indice +1 << " est élu avec " << max << " des voies au 1er tour sur un total de " << votants << " voies !" << endl;
        }
    }
    else{
        listeelection=election2etour(classementParticipants);
        int max = listeelection[0];


        for (size_t i = 1; i < listeelection.size(); ++i) {
            if (listeelection[i] > max) {
                max = listeelection[i];
                max_indice = i;
            }
        cout << "Le candidat " << max_indice +1 << " est élu avec " << max << " des voies au er tour sur un total de " << votants << " voies !" << endl;
        }
    }



    //     affichVectParticipants(vParticipant);
    //     cout << string (15, '-') << endl;
    //     sort (vParticipant.begin(), vParticipant.end(), compare2part);
    //     affichVectParticipants(vParticipant);
    // // */

    //     cout << "c'est la glace " << vGlacePref[0] << " qui a gagne" << endl;
    return 0;
}

/*
Nom
Prénon
Choix1
Choix2
*/
