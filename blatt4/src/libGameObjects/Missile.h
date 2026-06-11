#ifndef BLATT4_MISSILE_H
#define BLATT4_MISSILE_H


#include "Coordinates.h"

#include "Output.h"


namespace GameObjects {

    class Missile : public Sea::Coordinates {
    private:
        bool hit = false;

    public:
        Missile(Sea::Coordinates const & coordinates);
        Missile(Missile const & missile);
        virtual ~Missile() = default;

        bool checkHit(Sea::Coordinates const & coordinates);
        void markAsHit();
        bool hasHitSomething() const;

        void output(OutputGrid & grid) const;
    };

}


#endif //BLATT4_MISSILE_H
