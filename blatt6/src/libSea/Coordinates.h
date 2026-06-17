#ifndef BLATT6_COORDINATES_H
#define BLATT6_COORDINATES_H


#include <string>
#include <iostream>


namespace Sea {

    class Coordinates {
    protected:
        unsigned int x, y;

    public:
        Coordinates(unsigned int newX, unsigned int newY);

        bool samePositionAs(unsigned int otherX, unsigned int otherY) const;

        bool operator==(Coordinates const & otherCoordinates) const;

        unsigned int getX() const;
        unsigned int getY() const;

        std::string toString() const;
    };

}

std::ostream & operator<<(std::ostream & stream, Sea::Coordinates const & coordinates);


#endif //BLATT6_COORDINATES_H
