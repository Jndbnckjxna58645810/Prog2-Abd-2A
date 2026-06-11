#include "Object.h"


namespace Sea {

    Object::Object(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Coordinates(newCoordinates), size(newSize), orientation(newOrientation)
    {
    }

    bool Object::isAtCoordinates(Coordinates const & coordinates) const
    {
        // TODO Aufgabe 2:
        //  Nutzt die Funktionalität von `Coordinates`, um zu bestimmen, ob ein Teil dieses Objekts auf den übergebenen Koordinaten (`coordinates`) liegt.
        if (orientation == Orientation::X) {
            return (coordinates.getY() == y) && 
                   (coordinates.getX() >= x) && 
                   (coordinates.getX() < x + size);
        } else {
            return (coordinates.getX() == x) && 
                   (coordinates.getY() >= y) && 
                   (coordinates.getY() < y + size);
        }
    }

    bool Object::intersectsWith(Object const & otherObject) const
    {
        // TODO Aufgabe 2:
        //  Nutzt die Funktion `isAtCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt (`otherObject`) überschneiden.
        for (unsigned int i = 0; i < size; ++i) {
            unsigned int checkX = x + (orientation == Orientation::X ? i : 0);
            unsigned int checkY = y + (orientation == Orientation::Y ? i : 0);
            
            if (otherObject.isAtCoordinates(Coordinates(checkX, checkY))) {
                return true;
            }
        }
        return false;
    }

}
