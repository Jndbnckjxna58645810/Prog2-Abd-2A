#include "TumblingMissile.h"

#include <iostream>
using std::cout;
using std::endl;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <algorithm>
using std::clamp;
#include <string>
using std::to_string;


#include "Coordinates.h"
using Sea::Coordinates;

#include "Constants.h"

namespace GameObjects {

    TumblingMissile::TumblingMissile(Coordinates const & coordinates)
    : Missile(coordinates)
    {
        std::tie(offsetX, offsetY) = randomizedMissileOffset();
        cout << " ... (Tumbling Missile | " << toString() << ")";
    }

    TumblingMissile::TumblingMissile(TumblingMissile const & missile)
    : Missile(missile), offsetX(missile.offsetX), offsetY(missile.offsetY)
    {}

    Offset TumblingMissile::randomizedMissileOffset()
    {
        static random_device randomNumberInitializer;
        static mt19937 randomNumbers(randomNumberInitializer());
        static uniform_int_distribution<int> intMinus1to1(-1, 1);

        int x = intMinus1to1(randomNumbers);
        int y = intMinus1to1(randomNumbers);

        int X = static_cast<int>(Coordinates::getX()) + x;
        int Y = static_cast<int>(Coordinates::getY()) + y;
        if (X < 0 || X >= static_cast<int>(Constants::seaSizeX))
            x = 0;
        if (Y < 0 || Y >= static_cast<int>(Constants::seaSizeY))
            y = 0;

        return {x, y};
    }

    // TODO Aufgabe 2:
    //  Definiert die Funktionen `getX()`, `getY()` und `toString()`.
    unsigned int TumblingMissile::getX() const {
        return Coordinates::getX() + offsetX;
    }

    unsigned int TumblingMissile::getY() const {
        return Coordinates::getY() + offsetY;
    }

    std::string TumblingMissile::toString() const
    {
        return "(" + to_string(getX()) + ", " + to_string(getY()) + ")";
    }
}
