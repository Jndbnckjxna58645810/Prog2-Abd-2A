#ifndef BLATT6_TUMBLINGMISSILE_H
#define BLATT6_TUMBLINGMISSILE_H


#include "Coordinates.h"

#include "Missile.h"


namespace GameObjects {

    class TumblingMissile : public Missile {
    public:
        TumblingMissile(Sea::Coordinates const & coordinates);
        TumblingMissile(TumblingMissile const & missile);

        static std::string getName();

        static Sea::Coordinates randomizedMissileCoordinates(Sea::Coordinates const & primaryCoordinates);
    };

}


#endif //BLATT6_TUMBLINGMISSILE_H
