#include <vector>
using std::vector;

#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "init.h"
#include "game.h"


int main()
{
    vector<PlayerSea> playerSeas;
    initializePlayerSeasWithShips(playerSeas);

    gameLoop(playerSeas);

    return 0;
}
