#include "Missile.h"

#include <iostream>
using std::cout;
using std::endl;
using std::left;
#include <iomanip>
using std::setw;
#include <sstream>
using std::stringstream;

#include "Coordinates.h"
using Sea::Coordinates;


namespace GameObjects {

    Missile::Missile(Coordinates const & coordinates)
    : Coordinates(coordinates)
    {
        // TODO Aufgabe 3:
        //  Nutzt den `operator<<(..)` statt `toString()`.
        cout << endl << "(Create Missile | " << coordinates << ")";
    }

    Missile::Missile(Missile const & missile)
    : Coordinates(missile), hit(missile.hit)
    {
        cout << endl << "(Copy Missile)";
    }

    bool Missile::checkHit(Coordinates const & coordinates)
    {
        // TODO Aufgabe 3:
        //  Nutzt den `operator==(..)` statt `samePositionAs(..)`.
        if (this->operator==(coordinates)) {
            markAsHit();
            return true;
        }
        return false;
    }

    void Missile::markAsHit()
    {
        hit = true;
    }

    bool Missile::hasHitSomething() const
    {
        return hit;
    }

    void Missile::output(OutputGrid & grid) const
    {
        auto & gridCell = grid[getY()][getX()];
        stringstream stream;
        if (hit) {
            gridCell.missiles += 1;
            stream << " *" << setw(2) << left << gridCell.missiles;
        }
        else {
            gridCell.missiles -= 1;
            stream << " " << gridCell.output[1] << setw(2) << left << (-gridCell.missiles);
        }
        gridCell.output = stream.str();
    }

}
