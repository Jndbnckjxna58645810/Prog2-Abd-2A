#ifndef BLATT6_SHIP_H
#define BLATT6_SHIP_H


#include <vector>

#include "Object.h"
#include "Coordinates.h"

#include "Missile.h"
#include "Output.h"


namespace GameObjects {

    class Ship : public Sea::Object {
    private:
        std::vector<Coordinates> missileHitPositions;

        bool wasHitAt(Sea::Coordinates coordinates) const;

    public:
        using Sea::Object::Object;

        bool isInsideSeaBounds() const;

        void checkHits(Missile & missile);

        bool isDestroyed() const;

        void output(OutputGrid & grid) const;
    };

}


#endif //BLATT6_SHIP_H
