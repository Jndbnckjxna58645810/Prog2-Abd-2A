#ifndef BLATT8_PLAYERSEA_H
#define BLATT8_PLAYERSEA_H


#include <string>
#include <vector>
#include <list>
#include <memory>
#include <iostream>

#include "Coordinates.h"

#include "Ship.h"
#include "Missile.h"
#include "Vortex.h"
#include "Constants.h"


namespace GameObjects {
    class PlayerSea; // forward declaration
}

std::ostream & operator<<(std::ostream & stream, GameObjects::PlayerSea const & playerSea);

namespace GameObjects {

    class PlayerSea {
    private:
        std::string playerName;
        std::vector<Ship> ships;
        std::vector<std::shared_ptr<Missile>> missilesSent, missilesReceived;

        bool receiveMissile(std::shared_ptr<Missile> missile);

        OutputGrid gridOwnSea = OutputGrid(Constants::seaSizeX, Constants::seaSizeY, {});
        OutputGrid gridOtherSea = gridOwnSea;

    public:
        void setPlayerName(std::string const & newPlayerName);

        std::string const & getPlayerName() const;

        static std::string getSeaBounds();

        static bool isInsideSeaBounds(Sea::Coordinates const & coordinates);

        bool overlapWithExistingShips(Ship const & otherShip) const;

        enum class AddShipResult {
            added,
            outsideSeaBounds,
            overlapOtherShip
        };
        AddShipResult addShip(Ship const & ship);

        bool sendMissileTo(PlayerSea & otherSea, std::shared_ptr<Missile> missile);

        std::list<Sea::FCoordinates> collectTrackerCoordinates() const;
        Vortex createVortex(std::list<Sea::FCoordinates> const & trackerCoordinates, PlayerSea & otherSea);

        // (TODO Aufgabe 4:)
        // 1. Genutzte Container-Operationen:
        //    - "Sammeln": Sequentielles Einfügen am Ende via push_back() während des Spiels.
        //    - "Auswerten": Sequentielles Durchlaufen via Iteratoren (begin() bis end()) 
        //      in std::transform, um die X- und Y-Vektoren zu füllen.
        // 2. Warum std::list die beste Wahl ist:
        //    - Das "Sammeln" geschieht dynamisch. std::list (eine doppelt verkettete Liste) 
        //      erlaubt das Einfügen am Ende in O(1) konstanter Zeit, ohne jemals internen 
        //      Speicher reallokieren oder Elemente kopieren zu müssen (wie es bei std::vector 
        //      der Fall wäre).
        //    - Für das "Auswerten" reicht ein einfacher, sequentieller Durchlauf völlig aus. 
        //      Der Nachteil von std::list (kein wahlfreier Zugriff über einen Index wie [i]) 
        //      fällt hier überhaupt nicht ins Gewicht, da wir niemals mitten in die Liste 
        //      springen müssen.

        bool allShipsDestroyed() const;

        void printStats() const;

        friend std::ostream & ::operator<<(std::ostream & stream, GameObjects::PlayerSea const & playerSea);

    private:
        void printHeader(std::ostream & stream) const;
        void printLine(std::ostream & stream, unsigned int y) const;
        static void printHorizontalBorder(std::ostream & stream);
    };

}


#endif //BLATT8_PLAYERSEA_H
