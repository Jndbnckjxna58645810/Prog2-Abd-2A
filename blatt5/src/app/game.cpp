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
#include "DoubleMissile.h"
using GameObjects::DoubleMissile;
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

        bool finished = gameTurn(currentPlayerSea, otherPlayerSea, turn / 2);
        if (finished) {
            break;
        }
    }
}

bool gameTurn(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea, unsigned int round)
{
    // TODO Aufgabe 1:
    cout << "Runde " << round << endl;
    currentPlayerSea.print();

    selectTypeAndSendMissile(currentPlayerSea, otherPlayerSea, round);

    if (!checkGameFinished(currentPlayerSea, otherPlayerSea)) {
        printCountdownToNextRound();
        return false;
    }
    return true;
}

void selectTypeAndSendMissile(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea, unsigned int round)
{
    bool hit;
    switch (round % 3) {
        // TODO Aufgabe 2:
        //  Ersetzt die Funktionsaufrufe von `send___Missile(..)` durch Aufrufe der Template-Funktion `sendMissile<___>(...)`.
        case 2: hit = sendTumblingMissile(currentPlayerSea, otherPlayerSea); break;
        case 1: hit = sendDoubleMissile(currentPlayerSea, otherPlayerSea); break;
        default: hit = sendRegularMissile(currentPlayerSea, otherPlayerSea);
    }
    cout << n_endl(2) << (hit ? "Treffer!" : "Daneben!") << endl << string(80, '=') << endl;
}

// TODO Aufgabe 2:
bool sendRegularMissile(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea)
{
    Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea, Missile::getName());
    auto missile = make_shared<Missile>(targetCoordinates);
    return currentPlayerSea.sendMissileTo(otherPlayerSea, missile);
}

bool sendTumblingMissile(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea)
{
    Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea, TumblingMissile::getName());
    auto missile = make_shared<TumblingMissile>(targetCoordinates);
    return currentPlayerSea.sendMissileTo(otherPlayerSea, missile);
}

bool sendDoubleMissile(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea)
{
    Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea, DoubleMissile::getName());
    auto missile = make_shared<DoubleMissile>(targetCoordinates);
    return currentPlayerSea.sendMissileTo(otherPlayerSea, missile);
}

Coordinates inputMissileTargetCoordinates(PlayerSea const & currentPlayerSea, std::string const & missileType)
{
    while (true) {
        cout << currentPlayerSea.getPlayerName() << " zielt mit einer " << missileType << " auf" << endl;
        Coordinates targetCoordinates = inputCoordinates();

        if (!PlayerSea::isInsideSeaBounds(targetCoordinates)) {
            cout << "Diese Koordinaten liegen nicht im Spielfeld." << endl;
            continue;
        }
        return targetCoordinates;
    }
}

bool checkGameFinished(PlayerSea const & currentPlayerSea, PlayerSea const & otherPlayerSea)
{
    if (otherPlayerSea.allShipsDestroyed()) {
        // TODO Aufgabe 1:
        cout << "Das letzte Schiff von " << otherPlayerSea.getPlayerName() << " ist versenkt. "
             << currentPlayerSea.getPlayerName() << " hat gewonnen." << endl;
        currentPlayerSea.print();
        return true;
    }
    return false;
}

void printCountdownToNextRound()
{
#ifndef EXERCISE_SKIP_WAITING
    sleep_for(seconds(2));
#endif
    cout << "Spielerwechsel in..." << n_endl(4);
#ifndef EXERCISE_SKIP_WAITING
    sleep_for(seconds(1));
#endif
    for (int i = 3; i > 0; --i) {
        cout << i << "..." << n_endl(4);
#ifndef EXERCISE_SKIP_WAITING
        sleep_for(seconds(1));
#endif
    }
}
