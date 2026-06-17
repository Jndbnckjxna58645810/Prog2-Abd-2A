#ifndef BLATT6_OBJECT_H
#define BLATT6_OBJECT_H


#include "Coordinates.h"


namespace Sea {

    enum class Orientation {
        X,
        Y
    };

    class Object : public Coordinates {
    protected:
        unsigned int const size;
        Orientation const orientation;

    public:
        Object(Coordinates const & newCoordinates, unsigned int newSize, Orientation newOrientation);

        bool isAtCoordinates(Coordinates const & coordinates) const;
        bool intersectsWith(Object const & otherObject) const;

        unsigned int getSize() const;
        Orientation getOrientation() const;
    };

}


#endif //BLATT6_OBJECT_H
