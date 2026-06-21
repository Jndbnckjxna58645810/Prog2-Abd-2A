// TODO:
//  Entfernt die Kommentar-Zeichen (//) für Aufgaben, die erledigt sind und getestet werden sollen:


#define TEST_AUFGABE_1 // TODO Aufgabe 1
//#define TEST_AUFGABE_2 // TODO Aufgabe 2


#include "test.h"

#include <iostream>
using std::cout;
using std::endl;
using std::stringstream;
#include <algorithm>
using std::count;

#include "Coordinates.h"
using Sea::Coordinates;
#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "utils.h"
using Utils::n_endl;


bool testPassed()
{
    bool testResult =
            testConstructor() &&
            testOperator();

    if (testResult) {
        cout << "Test OK." << n_endl(2);
        return true;
    }
    cout << "Test fehlgeschlagen." << n_endl(2);
    return false;
}

bool testConstructor()
{
#ifdef TEST_AUFGABE_1
    PlayerSea ps;
#endif
    return true;
}

bool testOperator()
{
#ifdef TEST_AUFGABE_2
    Coordinates sameX1(1, 1);
    Coordinates sameX2(1, 2);
    Coordinates sameY1(1, 1);
    Coordinates sameY2(2, 1);
    Coordinates crossed1(1, 2);
    Coordinates crossed2(2, 1);
    Coordinates equal1(1, 1);
    Coordinates equal2(1, 1);
    return
        (sameX1 < sameX2) != (sameX2 < sameX1) &&
        (sameY1 < sameY2) != (sameY2 < sameY1) &&
        (crossed1 < crossed2) != (crossed2 < crossed1) &&
        !(equal1 < equal2) &&
        !(equal2 < equal1);
#else
    return true;
#endif
}
