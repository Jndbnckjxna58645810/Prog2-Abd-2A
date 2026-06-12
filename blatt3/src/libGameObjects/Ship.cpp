#include "Ship.h"

#include "Constants.h"
// TODO Aufgabe 6: Warum ist die folgende using-Anweisung hier unnötig?
// Erklärung: Da sich der restliche Code in der Datei innerhalb des Blocks 
// `namespace GameObjects { ... }` befindet, sind alle Elemente aus diesem Namensraum 
// (inklusive `Constants`) bereits ohne Qualifizierung sichtbar.
// using GameObjects::Constants; <-- Kann gelöscht werden!
using GameObjects::Constants;


namespace GameObjects {

    bool Ship::isInsideSeaBounds() const
    {
        if (x < Constants::seaSizeX && y < Constants::seaSizeY) {
            auto orientationAsInt = static_cast<unsigned int>(orientation);
            unsigned int
                shipEndX = x + (1 - orientationAsInt) * (size - 1),
                shipEndY = y + orientationAsInt * (size - 1);
            return  shipEndX < Constants::seaSizeX &&
                    shipEndY < Constants::seaSizeY;
        }
        return false;
    }

    // TODO Aufgabe 4:
    //  Definiert die Funktion `checkAndUpdateIncomingMissile(..)`.
    //  Nutzt die Funktionen von `Sea::Object`, um zu prüfen, ob die übergebene Rakete (`missile`) dieses Schiff trifft.
    //  Bei einem Treffer, markiert `missile` entsprechend.
    bool Ship::checkAndUpdateIncomingMissile(Missile & missile)
        {
            if (this->isAtCoordinates(missile)) {
                missile.markAsHit();
                hitCount++;
                return true;
            }
            return false;
        }

    bool Ship::isDestroyed() const
    {
        // TODO Aufgabe 4:
        //  Prüft, ob alle Felder des Schiffs einmal getroffen wurden.
        //  (Tipp: Es können nie mehrere Raketen auf die gleichen Koordinaten geschossen werden.)
        return hitCount >= size;
    }

}

