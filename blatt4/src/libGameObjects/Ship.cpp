#include "Ship.h"

#include "PlayerSea.h"


namespace GameObjects {

    bool Ship::isInsideSeaBounds() const
    {
        if (PlayerSea::isInsideSeaBounds(*this)) {
            auto orientationAsInt = static_cast<unsigned int>(orientation);
            Coordinates shipEnd(
                x + (1 - orientationAsInt) * (size - 1),
                y + orientationAsInt * (size - 1));
            return PlayerSea::isInsideSeaBounds(shipEnd);
        }
        return false;
    }

    void Ship::checkHits(std::shared_ptr<Missile> missile)
    {
        for (unsigned int i = 0; i < size; ++i) {
            Coordinates shipHitPosition = (orientation == Sea::Orientation::X) ? Coordinates(x + i, y) : Coordinates(x, y + i);
            if (missile->checkHit(shipHitPosition)) {
                missileHitPositions.push_back(shipHitPosition);
            }
        }
    }

    bool Ship::isDestroyed() const
    {
        for (unsigned int i = 0; i < size; ++i) {
            Coordinates coordinates = (orientation == Sea::Orientation::X) ? Coordinates(x + i, y) : Coordinates(x, y + i);
            if (!wasHitAt(coordinates)) {
                return false;
            }
        }
        return true;
    }

    bool Ship::wasHitAt(Sea::Coordinates coordinates) const
    {
        for (unsigned int missileIdx = 0; missileIdx < missileHitPositions.size(); ++missileIdx) {
            // TODO Aufgabe 3:
            //  Nutzt den `operator==(..)` statt `samePositionAs(..)`.
            if (missileHitPositions[missileIdx] == coordinates) {
                return true;
            }
        }
        return false;
    }

    void Ship::output(OutputGrid & grid) const
    {
        for (unsigned int i = 0; i < size; ++i) {
            if (orientation == Sea::Orientation::X) {
                auto & cell = grid[y][x + i];
                cell.ship = true;
                cell.output = " X  ";
            } else {
                auto & cell = grid[y + i][x];
                cell.ship = true;
                cell.output = " X  ";
            }
        }
    }

}
