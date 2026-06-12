#include "Missile.h"

// TODO Aufgabe 3:
//  Definiert die Funktionen der Klasse `Missile`.

namespace GameObjects {
    Missile::Missile(Sea::Coordinates const & coordinates)
    : Sea::Coordinates(coordinates), hit(false)
    {
    }

    void Missile::markAsHit()
    {
        hit = true;
    }

    bool Missile::hasHitSomething() const
    {
        return hit;
    }
}
