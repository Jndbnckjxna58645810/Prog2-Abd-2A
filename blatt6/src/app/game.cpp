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
    cout << "Runde " << round << endl << currentPlayerSea;

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
        case 2: hit = sendMissile<TumblingMissile>(currentPlayerSea, otherPlayerSea); break;
        case 1: hit = sendMissile<DoubleMissile>(currentPlayerSea, otherPlayerSea); break;
        default: hit = sendMissile<Missile>(currentPlayerSea, otherPlayerSea);
    }
    cout << n_endl(2) << (hit ? "Treffer!" : "Daneben!") << endl << string(80, '=') << endl;
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
        cout << "Das letzte Schiff von " << otherPlayerSea.getPlayerName() << " ist versenkt. "
             << currentPlayerSea.getPlayerName() << " hat gewonnen." << endl
             << currentPlayerSea;
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

void printStats(vector<PlayerSea> & playerSeas)
{
    cout << endl << "Spielstatistik:" << n_endl(2);
    for (auto const & playerSea : playerSeas) {
        cout << playerSea.getPlayerName() << endl;
        playerSea.printStats();
        cout << endl;
    }
}
