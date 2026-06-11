#ifndef BLATT4_INVERTINGMISSILE_H
#define BLATT4_INVERTINGMISSILE_H

#include "Coordinates.h"

#include "Missile.h"

namespace GameObjects {

    class InvertingMissile : public Missile {
    public:
        InvertingMissile(Sea::Coordinates const & coordinates);
        InvertingMissile(InvertingMissile const & missile);

        unsigned int getX() const;
        unsigned int getY() const;

        std::string toString() const;
    };

}


#endif //BLATT4_TUMBLINGMISSILE_H
