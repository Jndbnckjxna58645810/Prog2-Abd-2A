#include "game.h"

// TODO Aufgabe 6:
//  Bringe die `include`- und `using`-Anweisungen in eine sinnvolle Ordnung.
#include <iostream>
#include <vector>

#include "init.h"
#include "Coordinates.h"
#include "PlayerSea.h"

using std::cout;
using std::endl;
using std::vector;

using Sea::Coordinates;
using GameObjects::PlayerSea;


// TODO Aufgabe 6:
//  Zerlege die Funktion `gameLoop(..)` in sinnvolle, kürzere Teilfunktionen.
bool playRound(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea) {
    currentPlayerSea.displaySeaArea();
    
    Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea);
    bool hit = currentPlayerSea.sendMissileTo(otherPlayerSea, targetCoordinates);
    
    if (hit) {
        cout << "Treffer!" << endl;
    } else {
        cout << "Daneben!" << endl;
    }

    if (otherPlayerSea.allShipsDestroyed()) {
        cout << "Das letzte Schiff von " << otherPlayerSea.getPlayerName() << " ist versenkt. "
             << currentPlayerSea.getPlayerName() << " hat gewonnen." << endl;
        return true; // Spiel ist vorbei
    }
    return false; // Spiel geht weiter
}

void gameLoop(vector<PlayerSea> & playerSeas)
{
    cout << endl << "Los geht's!" << endl;
    for (unsigned int round = 0;; ++round) {
        PlayerSea & currentPlayerSea = playerSeas[round % 2];
        PlayerSea & otherPlayerSea = playerSeas[(round + 1) % 2];

        bool gameFinished = playRound(currentPlayerSea, otherPlayerSea);
        if (gameFinished) {
            break;
        }
    }
}

Coordinates inputMissileTargetCoordinates(PlayerSea const & currentPlayerSea)
{
    while (true) {
        cout << endl << currentPlayerSea.getPlayerName() << " zielt auf" << endl;
        Coordinates targetCoordinates = inputCoordinates();

        if (currentPlayerSea.missileAlreadySentTo(targetCoordinates)) {
            cout << "Diese Koordinaten hast du schon probiert." << endl;
            continue;
        }
        return targetCoordinates;
    }
}
