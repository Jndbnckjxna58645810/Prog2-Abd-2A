#include <vector>
using std::vector;

#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "init.h"
#include "game.h"
#include "test.h"


int main()
{
    vector<PlayerSea> playerSeas;

    if (testPassed()) {

#ifndef EXERCISE_SKIP_PLAYER_INIT
        initializePlayerSeasWithShips(playerSeas);
#else
        for (int i = 0; i < 2; ++i) {
            playerSeas.push_back(PlayerSea(i ? "Paddy" : "Flo"));
            playerSeas[i].addShip(GameObjects::Ship({1, 2}, 2, Sea::Orientation::X));
        }
#endif

        gameLoop(playerSeas);

        printStats(playerSeas);
    }

    return 0;
}
