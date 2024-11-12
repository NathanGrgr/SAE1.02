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



void afficheVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

void afficheVectInt (const vector<int> & v){
    for (const int & val : v)
        cout << val << ' ';
    cout << endl;
}


vector<int> election(const vector<vector<int>>& classement,const vector <string> vCandidat) {

    vector<int> votesPremierePosition(vCandidat.size(),0);

    for (const auto & i : classement) {
        int premiercandidat = i[0] - 1;
        votesPremierePosition[premiercandidat]++;
        //afficheVectInt(votesPremierePosition);
    }
    size_t i = 0;
    while (i< votesPremierePosition.size()){
        votesPremierePosition[i]=votesPremierePosition[i]*4;
        i++;
    }

    vector<int> votesDeuxiemePosition(vCandidat.size(),0);

    for (const auto & i : classement){
        int deuxiemecandidat = i[1] - 1;
        votesDeuxiemePosition[deuxiemecandidat]++;
        //afficheVectInt(votesDeuxiemePosition);
    }
    i = 0;
    while (i< votesDeuxiemePosition.size()){
        votesDeuxiemePosition[i]=votesDeuxiemePosition[i]*3;
        ++i;
    }

    vector<int> votesTroisiemePosition(vCandidat.size(),0);

    for (const auto& i : classement){
        int troisiemecandidat = i [2]-1;
        votesTroisiemePosition[troisiemecandidat]++;
        //afficheVectInt(votesTroisiemePosition);
    }
    i=0;
    while (i < votesTroisiemePosition.size()){
        votesTroisiemePosition[i]=votesTroisiemePosition[i]*2;
        ++i;
    }

    vector<int> votesQuatriemePosition(vCandidat.size(),0);

    for (const auto & i : classement){
        int quatriemecandidat = i[3]-1;
        votesQuatriemePosition[quatriemecandidat]++;
        //afficheVectInt(votesQuatriemePosition);
    }

    // afficheVectInt(votesPremierePosition);
    // afficheVectInt(votesDeuxiemePosition);
    // afficheVectInt(votesTroisiemePosition);
    // afficheVectInt(votesQuatriemePosition);


    vector<int> votesBorda(vCandidat.size(),0);
    for (size_t i(0); i<4; ++i){
        votesBorda[i]=votesPremierePosition[i]+votesDeuxiemePosition[i]+votesTroisiemePosition[i]+votesQuatriemePosition[i];
    }

    return votesBorda;
}



struct participant {
    string nom;
    string prenom;
    vector<int> classement;
};



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
        vCandidat.push_back(litUneString());

    //afficheVectString (vCandidat);

    vector<participant> vParticipant;
    size_t votants = 116;
    for (unsigned i (0); i < votants; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        vector<int> classement (litListe());

        vParticipant.push_back(participant{nom, prenom, classement});

        //afficheVectInt(classement);
    }

    //afficheVectParticipants(vParticipant);
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

    int total_points = 0;
    for (const auto& points : listeelection) { total_points += points; }
    cout << "Le candidat " << vCandidat[max_indice] << " est élu avec " << max << " points sur un total de " << total_points << " points !" << endl;


    return 0;
}
