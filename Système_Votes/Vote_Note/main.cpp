#include <iostream>
#include <vector>

using namespace std;

// Fonction pour lire une chaîne de caractères depuis l'entrée standard
// Ignore les lignes commençant par "//"
string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

// Fonction pour lire un entier depuis l'entrée standard
// Ignore les lignes commençant par "//"
int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return stoi(uneChaine);
}

// Fonction pour afficher les éléments d'un vecteur d'entiers
void afficheVectInt (const vector<int> & v){
    for (const int & val : v)
        cout << val << ' ';
    cout << endl;
}

// Fonction pour afficher les éléments d'un vecteur de flottants
void afficheVectFloat(const vector<float>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";  // Affiche chaque élément suivi d'un espace
    }
    cout << endl;  // Saute une ligne à la fin
}

// Fonction pour calculer les scores des candidats
// Prend en entrée les notes des participants et les candidats correspondants
vector<float> election (const vector<int> & NoteParticipant, const vector<int> & CandidatParticipant){
    vector<float> CompteurNote(4, 0.0f);  // Initialisation du compteur de notes pour 4 candidats
    int val = CandidatParticipant[0];
    for (size_t i(0); i < NoteParticipant.size(); ++i){
        val = CandidatParticipant[i]-1;
        CompteurNote[val]+=static_cast<float>(NoteParticipant[i]);
    }
    for (size_t i(0); i < CompteurNote.size(); ++i){
        CompteurNote[i]=CompteurNote[i]/29;  // Division par 29 pour obtenir la moyenne
    }
    return CompteurNote;
}

// Structure représentant un participant
struct participant {
    string nom;
    string prenom;
    int candidat;
    int note;
};

// Fonction pour afficher les éléments d'un vecteur de chaînes de caractères
void afficheVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

// Fonction pour afficher les informations des participants
void afficheVectParticipants (const vector<participant> & vPart){
    for (const participant & part : vPart){
        cout << part.nom << endl;
        cout << part.prenom << endl;
        cout << part.candidat << endl;
        cout << part.note << endl;
    }
}

int main()
{
    vector <string> vCandidat;  // Vecteur pour stocker les noms des candidats
    for (unsigned i (0); i < 4; ++i)
        vCandidat.push_back(litUneString());  // Lecture des noms des candidats

    vector<participant> vParticipant;  // Vecteur pour stocker les participants

    unsigned votants = 116;  // Nombre de votants
    for (unsigned i (0); i < votants; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        int candidat (litUnEntier());
        int note(litUnEntier());
        vParticipant.push_back(participant{nom, prenom, candidat,note});  // Ajout des participants au vecteur
    }

    vector<int> NoteParticipant;  // Vecteur pour stocker les notes des participants
    for (const auto& part : vParticipant)
        NoteParticipant.push_back(part.note);

    vector<int> CandidatParticipant;  // Vecteur pour stocker les candidats des participants
    for (const auto& part : vParticipant)
        CandidatParticipant.push_back(part.candidat);

    vector<float> listeelection;
    listeelection = election(NoteParticipant, CandidatParticipant);  // Calcul des scores des candidats

    float max = listeelection[0];
    int max_indice = 0;

    // Affichage des scores des candidats et détermination du candidat élu
    for (size_t i = 0; i < listeelection.size(); ++i) {
        cout << "Le candidat " << vCandidat[i] << " a obtenu une note de " << listeelection[i] << " sur 10" << endl;
        if (listeelection[i] > max) {
            max = listeelection[i];
            max_indice = i;
        }
    }

    // Affichage du candidat élu
    cout << "Le candidat " << vCandidat[max_indice] << " est élu avec un score de " << max << " sur 10 avec un effectif de " << votants << " voies !" << endl;
    return 0;
}
