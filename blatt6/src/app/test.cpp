// TODO:
//  Entfernt die Kommentar-Zeichen (//) für Aufgaben, die erledigt sind und getestet werden sollen:


#define TEST_AUFGABE_2 // TODO Aufgabe 2


#include "test.h"

#include <iostream>
using std::cout;
using std::endl;
using std::stringstream;
#include <algorithm>
using std::count;

#include "Coordinates.h"
using Sea::Coordinates;
#include "Grid2D.h"
using Sea::Grid2D;


bool testPassed()
{
    bool testResult =
            testWalkAndFilter();

    if (testResult) {
        cout << "Test OK." << endl;
        return true;
    }
    cout << "Test fehlgeschlagen." << endl;
    return false;
}

bool testWalkAndFilter()
{
#ifdef TEST_AUFGABE_2
    Grid2D<int> grid(2, 2, 1);
    grid(1, 1) = 2;

    int sum = 0;
    grid.walk([&](int const & cell) { sum += cell; });

    auto filteredValues = grid.filter([](int const & cell) { return cell > 1; });

    return sum == 5 && filteredValues.size() == 1 && filteredValues[0] == 2;
#else
    return true;
#endif
}
