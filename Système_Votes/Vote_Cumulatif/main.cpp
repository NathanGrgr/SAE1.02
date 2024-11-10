#include <iostream>
#include <vector>

using namespace std;





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

vector<int> election(const vector<vector<int>>& classement, const vector<string> vCanndidat){
    vector<int> votesPointsCumules(vCandidat.size(),0);
}


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}


/*[[0,5,3,2][..]..]
 * Celui qui a le plus de points gagne
 */
