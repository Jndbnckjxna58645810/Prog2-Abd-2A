#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    cout << "Hello, World!" << endl;
    vector<string> team = {"Polina Hryhorashchenko" " Zidane Tawa Ngueguim und"}; //Vektor mit Startwerten
    team.emplace_back("Zidane Tawa Ngueguim"); //Weiteren Wert zum Vektor hinzufugen
    team.emplace_back("Luca Beinlich"); //...
    int teamSize = team.size(); //Indexing starts from 0 (here it goes up to 3)
    cout << "Wir sind ein Team: " << team[0] << "..." << team.at(teamSize - 1) << endl;
    return 0;
}
