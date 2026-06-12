#include "PlayerSea.h"

#include <string>
using std::string;
using std::to_string;
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Coordinates.h"
using Sea::Coordinates;

#include "Constants.h"


namespace GameObjects {

    PlayerSea::PlayerSea(string const & newPlayerName)
    : playerName(newPlayerName)
    {
        // TODO Aufgabe 5:
        std::cout << gridOwnSea.sizeX() << "x" << gridOwnSea.sizeY() << " Spielfeld von " << newPlayerName << " bereit." << std::endl;
    }

    string const & PlayerSea::getPlayerName() const
    {
        return playerName;
    }

    string PlayerSea::getSeaBounds()
    {
        return "Spielfeld: 0-" + to_string(Constants::seaSizeX - 1) +
                       " x 0-" + to_string(Constants::seaSizeY - 1);
    }

    bool PlayerSea::overlapWithExistingShips(Ship const & otherShip) const
    {
        for (unsigned int shipIdx = 0; shipIdx < ships.size(); ++shipIdx) {
            Ship const & ship = ships[shipIdx];
            if (ship.intersectsWith(otherShip)) {
                return true;
            }
        }
        return false;
    }

    PlayerSea::AddShipResult PlayerSea::addShip(Ship const & ship)
    {
        if (!ship.isInsideSeaBounds()) {
            return AddShipResult::outsideSeaBounds;
        }
        if (overlapWithExistingShips(ship)) {
            return AddShipResult::overlapOtherShip;
        }
        ships.push_back(ship);
        ship.output(gridOwnSea);
        return AddShipResult::added;
    }

    bool PlayerSea::sendMissileTo(PlayerSea & otherSea, shared_ptr<Missile> missile)
    {
        otherSea.receiveMissile(missile);
        missilesSent.push_back(missile);
        missile->output(gridOtherSea);
        return missile->hasHitSomething();
    }

    bool PlayerSea::receiveMissile(shared_ptr<Missile> missile)
    {
        for (unsigned int shipIdx = 0; shipIdx < ships.size(); ++shipIdx) {
            ships[shipIdx].checkHits(*missile);
        }
        missilesReceived.push_back(missile);
        missile->output(gridOwnSea);
        return missile->hasHitSomething();
    }

    bool PlayerSea::allShipsDestroyed() const
    {
        for (unsigned int shipIdx = 0; shipIdx < ships.size(); ++shipIdx) {
            Ship const & ship = ships[shipIdx];
            if (!ship.isDestroyed()) {
                return false;
            }
        }
        return true;
    }

    bool PlayerSea::isInsideSeaBounds(Coordinates const & coordinates)
    {
        return  coordinates.getX() < Constants::seaSizeX &&
                coordinates.getY() < Constants::seaSizeY;
    }

}
