#ifndef BLATT4_TUMBLINGMISSILE_H
#define BLATT4_TUMBLINGMISSILE_H


#include <tuple>
using Offset = std::tuple<int, int>;

#include "Coordinates.h"

#include "Missile.h"


namespace GameObjects {

    class TumblingMissile : public Missile {
    private:
        int offsetX, offsetY;
    public:
        TumblingMissile(Sea::Coordinates const & coordinates);
        TumblingMissile(TumblingMissile const & missile);

        Offset randomizedMissileOffset();

        // TODO Aufgabe 2:
        //  Deklariert Überladungen für die virtuellen Funktionen `getX(..)`, `getY(..)` und `toString()` der Klasse `Coordinates`.
        unsigned int getX() const override;
        unsigned int getY() const override;

        std::string toString() const override;
    };

}


#endif //BLATT4_TUMBLINGMISSILE_H
