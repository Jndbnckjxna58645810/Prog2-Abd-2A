#include "InvertingMissile.h"

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::to_string;

#include "Coordinates.h"
using Sea::Coordinates;

#include "Constants.h"

namespace GameObjects
{
    InvertingMissile::InvertingMissile(Coordinates const & coordinates)
    : Missile(coordinates)
    {
        cout << " ... (Inverting Missile | " << toString() << ")";
    }

    InvertingMissile::InvertingMissile(InvertingMissile const & missile)
    : Missile(missile) {}

    unsigned int InvertingMissile::getX() const {
        return (Constants::seaSizeX - 1) - x;
    }

    unsigned int InvertingMissile::getY() const {
        return (Constants::seaSizeY - 1) - y;
    }

    std::string InvertingMissile::toString() const
    {
        return "(" + to_string(getX()) + ", " + to_string(getY()) + ")";
    }
} // namespace name
