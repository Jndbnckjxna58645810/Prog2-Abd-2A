#include "game.h"

#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <thread>
using std::this_thread::sleep_for;
#include <chrono>
using std::chrono::seconds;
#include <memory>
using std::make_shared;

#include "Coordinates.h"
using Sea::Coordinates;

#include "Missile.h"
using GameObjects::Missile;
#include "TumblingMissile.h"
using GameObjects::TumblingMissile;
#include "InvertingMissile.h"
using GameObjects::InvertingMissile;
#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "init.h"
#include "utils.h"
using Utils::n_endl;

void gameLoop(vector<PlayerSea> & playerSeas)
{
    cout << endl << "Los geht's!" << n_endl(2);
    for (unsigned int turn = 0;; ++turn) {
        PlayerSea & currentPlayerSea = playerSeas[turn % 2];
        PlayerSea & otherPlayerSea = playerSeas[(turn + 1) % 2];

        gameTurn(currentPlayerSea, otherPlayerSea, turn / 2);

        if (checkGameFinished(currentPlayerSea, otherPlayerSea)) {
            break;
        }
        printCountdownToNextRound();
    }
}

void gameTurn(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea, unsigned int round)
{
    cout << "Runde " << round << endl;
    currentPlayerSea.print(otherPlayerSea.getPlayerName());
    Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea);
    // TODO Aufgabe 2:
    //  Ruft je nach Wert der Variablen `round` (gerade/ungerade) entweder `sendRegularMissileTo(..)` oder `sendTumblingMissileTo(..)` auf.
    bool hit = (round % 3 == 0) ?
        sendRegularMissileTo(currentPlayerSea, otherPlayerSea, targetCoordinates) : (
            (round % 3 == 2) ? sendTumblingMissileTo(currentPlayerSea, otherPlayerSea, targetCoordinates) :
                sendInvertingMissileTo(currentPlayerSea, otherPlayerSea, targetCoordinates));

    cout << n_endl(2) << (hit ? "Treffer!" : "Daneben!") << endl << string(80, '=') << endl;
}

void printCountdownToNextRound()
{
    sleep_for(seconds(2));
    cout << "Spielerwechsel in..." << n_endl(4);
    sleep_for(seconds(1));
    for (int i = 3; i > 0; --i) {
        cout << i << "..." << n_endl(4);
        sleep_for(seconds(1));
    }
}

bool sendRegularMissileTo(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea, Coordinates const & targetCoordinates)
{
    // TODO Aufgabe 1:
    //  Erzeugt hier `shared_ptr<Missile>` statt "reine" Missile-Instanzen.
    std::shared_ptr<Missile> missile = std::make_shared<Missile>(targetCoordinates);
    return currentPlayerSea.sendMissileTo(otherPlayerSea, missile);
}

bool sendTumblingMissileTo(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea, Coordinates const & targetCoordinates)
{
    // TODO Aufgabe 2:
    //  Entfernt den Aufruf von `sendRegularMissileTo(..)`.
    //  Erstellt hier stattdessen eine `TumblingMissile` und sendet diese analog zu `sendRegularMissileTo(..)`.
    std::shared_ptr<TumblingMissile> missile = std::make_shared<TumblingMissile>(targetCoordinates);
    return currentPlayerSea.sendMissileTo(otherPlayerSea, missile);
}

bool sendInvertingMissileTo(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea, Coordinates const & targetCoordinates)
{
    std::shared_ptr<InvertingMissile> missile = std::make_shared<InvertingMissile>(targetCoordinates);
    return currentPlayerSea.sendMissileTo(otherPlayerSea, missile);
}

bool checkGameFinished(PlayerSea const & currentPlayerSea, PlayerSea const & otherPlayerSea)
{
    if (otherPlayerSea.allShipsDestroyed()) {
        cout << "Das letzte Schiff von " << otherPlayerSea.getPlayerName() << " ist versenkt. "
             << currentPlayerSea.getPlayerName() << " hat gewonnen." << endl;
        currentPlayerSea.print(otherPlayerSea.getPlayerName());
        return true;
    }
    return false;
}

Coordinates inputMissileTargetCoordinates(PlayerSea const & currentPlayerSea)
{
    while (true) {
        cout << currentPlayerSea.getPlayerName() << " zielt auf" << endl;
        Coordinates targetCoordinates = inputCoordinates();

        if (!PlayerSea::isInsideSeaBounds(targetCoordinates)) {
            cout << "Diese Koordinaten liegen nicht im Spielfeld." << endl;
            continue;
        }
        return targetCoordinates;
    }
}
