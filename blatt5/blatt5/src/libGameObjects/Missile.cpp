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
    {}

    Missile::Missile(Missile const & missile)
    : Coordinates(missile), hit(missile.hit)
    {}

    std::string Missile::getName()
    {
        return "Rakete";
    }

    bool Missile::checkHit(Coordinates const & coordinates)
    {
        if (*this == coordinates) {
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
        auto & gridCell = grid[y][x];
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
