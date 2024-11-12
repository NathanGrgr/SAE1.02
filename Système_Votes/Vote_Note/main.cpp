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


int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return stoi(uneChaine);
}

void afficheVectInt (const vector<int> & v){
    for (const int & val : v)
        cout << val << ' ';
    cout << endl;
}

void afficheVectFloat(const vector<float>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";  // Affiche chaque élément suivi d'un espace
    }
    cout << endl;  // Saute une ligne à la fin
}
vector<float> election (const vector<int> & NoteParticipant, const vector<int> & CandidatParticipant){
    vector<float> CompteurNote(4, 0.0f);
    int val = CandidatParticipant[0];
    for (size_t i(0); i < NoteParticipant.size(); ++i){
        val = CandidatParticipant[i]-1;
        //cout << NoteParticipant[i] << endl;
        CompteurNote[val]+=static_cast<float>(NoteParticipant[i]);
    }
    //afficheVectInt(CompteurNote);
    for (size_t i(0); i < CompteurNote.size(); ++i){
        CompteurNote[i]=CompteurNote[i]/29;
    }
    return CompteurNote;
}
struct participant {
    string nom;
    string prenom;
    int candidat;
    int note;
};





void afficheVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

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
    vector <string> vCandidat;
    for (unsigned i (0); i < 4; ++i)
        vCandidat.push_back(litUneString());
    //afficheVectString (vCandidat);

    vector<participant> vParticipant;

    unsigned votants = 116;
    for (unsigned i (0); i < votants; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        int candidat (litUnEntier());
        int note(litUnEntier());
        vParticipant.push_back(participant{nom, prenom, candidat,note});
    }

    vector<int> NoteParticipant;
    for (const auto& part : vParticipant)
        NoteParticipant.push_back(part.note);

    vector<int> CandidatParticipant;
    for (const auto& part : vParticipant)
        CandidatParticipant.push_back(part.candidat);

    //afficheVectInt(NoteParticipant);
    //afficheVectInt(CandidatParticipant);
    //[4,5,4,1,10,2]
    vector<float> listeelection;
    listeelection=election(NoteParticipant,CandidatParticipant);
    //afficheVectFloat(listeelection);

    float max = listeelection[0];
    int max_indice = 0;

    for (size_t i = 0; i < listeelection.size(); ++i) {
        cout << "Le candidat " << vCandidat[i] << " a obtenu une note de " << listeelection[i] << " sur 10" << endl;
        if (listeelection[i] > max) {
            max = listeelection[i];
            max_indice = i;
        }
    }

    cout << "Le candidat " << vCandidat[max_indice] << " est élu avec un score de " << max << " sur 10 avec un effectif de " << votants << " voies !" << endl;
    return 0;
}

