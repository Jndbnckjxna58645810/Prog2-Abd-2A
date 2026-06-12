#include "PlayerSea.h"

#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include "Constants.h"


namespace GameObjects {

    string const spaceX = "          ";
    unsigned int const seaCellSizeX = 4;

    // TODO Aufgabe 1:

    void PlayerSea::printHeader(ostream & stream) const
    {
        stream << "     "
               << playerName
               << string(Constants::seaSizeX * seaCellSizeX - playerName.length(),' ')
               << spaceX
               << "Gegner" << endl
               << "  ";
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            stream << setw(seaCellSizeX) << x;
        }
        stream << spaceX;
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            stream << setw(seaCellSizeX) << x;
        }
        stream << endl;
        printHorizontalBorder(stream);
    }

    void PlayerSea::printLine(ostream & stream, unsigned int y) const
    {
        stream << setw(2) << y << " |";
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            stream << gridOwnSea[y][x].output;
        }
        stream << spaceX;
        for (unsigned int x = 0; x < Constants::seaSizeX; ++x) {
            stream << gridOtherSea[y][x].output;
        }
        stream << " | " << y << endl;
    }

    void PlayerSea::printHorizontalBorder(ostream & stream)
    {
        stream << "    "
               << string(Constants::seaSizeX * seaCellSizeX * 2 + spaceX.length() + 1, '-')
               << endl;
    }

    // TODO Aufgabe 1:
    //  Implementiert hier `operator<<`.
    ostream & operator<<(ostream & stream, const PlayerSea & playerSea) {
        stream << endl;
        playerSea.printHeader(stream);
        for (unsigned int y = 0; y < Constants::seaSizeY; ++y) {
            playerSea.printLine(stream, y);
        }
        playerSea.printHorizontalBorder(stream);
        stream << endl;
        return stream;
    }

}
