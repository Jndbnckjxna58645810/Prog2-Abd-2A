#include "Coordinates.h"

#include <string>
using std::to_string;

#include <iostream>
using std::ostream;


namespace Sea {

    Coordinates::Coordinates(unsigned int newX, unsigned int newY)
    : x(newX), y(newY)
    {
    }

    bool Coordinates::samePositionAs(unsigned int otherX, unsigned int otherY) const
    {
        return getX() == otherX && getY() == otherY;
    }

    // TODO Aufgabe 3:
    //  Definiert den `operator==(..)` identisch zu und als Ersatz für die Funktion `samePositionAs(..)`.
    bool Coordinates::operator==(Coordinates const & otherCoordinates) const
    {
        return samePositionAs(otherCoordinates.getX(), otherCoordinates.getY());
    }

    unsigned int Coordinates::getX() const
    {
        return x;
    }

    unsigned int Coordinates::getY() const
    {
        return y;
    }

    std::string Coordinates::toString() const
    {
        return "(" + to_string(getX()) + ", " + to_string(getY()) + ")";
    }

}

// TODO Aufgabe 3:
//  Implementiert den `operator<<(..)` so, dass er die `toString()` nutzt, um die Koordinaten in den `std::ostream` auszugeben.
//  (Eine Referenz von `std::ostream` kann wie `std::cout` verwendet werden.)
std::ostream & operator<<(std::ostream & stream, const Sea::Coordinates & coordinates) {
    stream << coordinates.toString();
    return stream;
}
