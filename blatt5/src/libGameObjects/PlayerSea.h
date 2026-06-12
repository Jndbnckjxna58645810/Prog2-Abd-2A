#ifndef BLATT5_PLAYERSEA_H
#define BLATT5_PLAYERSEA_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "Ship.h"
#include "Missile.h"
#include "Constants.h"
#include "Grid2D.h"

using std::ostream;

namespace GameObjects {
    class PlayerSea; // Das ist eine sogenannte `forward declaration`.
}                    // Damit weiß der Compiler, dass später noch eine Klasse `PlayerSea` deklariert wird.
                     //
                     // Da der Compiler Dateien zeilenweise verarbeitet, kennt er `GameObjects::PlayerSea` zum Zeitpunkt der Deklaration von `operator<<` noch nicht, und würde einen Fehler ausgeben.
                     // Dank der forward declaration können wir aber doch auf die Klasse verweisen (in dem Fall als Parameter).
                     // Achtung: Das funktioniert nur mit Referenzen oder Pointern, nicht mit "tatsächlichen" Instanzen (also Kopien von Objekten).


// TODO Aufgabe 1:
//  Deklariert eine Überladung für `operator<<(stream, playerSea)` so, dass `PlayerSea`-Instanzen einfach direkt per `cout << playerSea` ausgegeben werden können.
//  Tipp: Siehe `Coordinates.h`
namespace GameObjects {
    ostream & operator<<(ostream & stream, const GameObjects::PlayerSea & playerSea);
}

namespace GameObjects {

    class PlayerSea {
    private:
        std::string playerName;
        std::vector<Ship> ships;
        std::vector<std::shared_ptr<Missile>> missilesSent, missilesReceived;

        bool receiveMissile(std::shared_ptr<Missile> missile);

        // TODO Aufgabe 5:
        OutputGrid gridOwnSea = OutputGrid(Constants::seaSizeX, Constants::seaSizeY, OutputGridCell());
        OutputGrid gridOtherSea = gridOwnSea;

    public:
        PlayerSea(std::string const & newPlayerName);

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

        bool allShipsDestroyed() const;

        // TODO Aufgabe 1:
        //  Entfernt die Funktion `print()` und fügt stattdessen eine `friend` Deklaration für `::operator<<` hinzu.
        //  Hinweis: Da die Klasse in einem Namespace definiert ist, gelten auch `friend` Deklarationen für entsprechende Funktionen/Klassen im selben Namespace.
        //           Um innerhalb eines Namespaces in den "globalen" Namespace zu verweisen, kann der Scope-Resolution-Operator ohne Angabe eines Namespaces verwendet werden.
        friend ostream & operator<<(ostream & stream, const PlayerSea & playerSea);

    private:
        void printHeader(std::ostream & stream) const;
        void printLine(std::ostream & stream, unsigned int y) const;
        static void printHorizontalBorder(std::ostream & stream);
    };

}


#endif //BLATT5_PLAYERSEA_H
