#include "PlayerSea.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include "Constants.h"


namespace GameObjects {

    string const spaceX = "          ";
    unsigned int const seaCellSizeX = 4;

    void PlayerSea::print(string const & otherPlayerName) const
    {
        cout << endl;
        printHeader(otherPlayerName);
        for (unsigned int y = 0; y < Constants::seaSizeY; ++y) {
            printLine(y);
        }
        printHorizontalBorder();
        cout << endl;
    }

    void PlayerSea::printHeader(string const & otherPlayerName) const
    {
        cout << "     "
             << playerName
             << string(Constants::seaSizeX * seaCellSizeX - playerName.length(),' ')
             << spaceX
             << otherPlayerName << endl
             << "  ";
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            cout << setw(seaCellSizeX) << x;
        }
        cout << spaceX;
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            cout << setw(seaCellSizeX) << x;
        }
        cout << endl;
        printHorizontalBorder();
    }

    void PlayerSea::printLine(unsigned int y) const
    {
        cout << setw(2) << y << " |";
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            cout << gridOwnSea[y][x].output;
        }
        cout << spaceX;
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            cout << gridOtherSea[y][x].output;
        }
        cout << " | " << y << endl;
    }

    void PlayerSea::printHorizontalBorder()
    {
        cout << "    "
             << string(Constants::seaSizeX * seaCellSizeX * 2 + spaceX.length() + 1, '-')
             << endl;
    }

}
