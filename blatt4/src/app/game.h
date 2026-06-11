#ifndef BLATT4_GAME_H
#define BLATT4_GAME_H


#include <vector>

#include "Coordinates.h"

#include "PlayerSea.h"


void gameLoop(std::vector<GameObjects::PlayerSea> & playerSeas);

void gameTurn(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

bool sendRegularMissileTo(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, Sea::Coordinates const & targetCoordinates);
bool sendTumblingMissileTo(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, Sea::Coordinates const & targetCoordinates);
bool sendInvertingMissileTo(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, Sea::Coordinates const & targetCoordinates);

void printCountdownToNextRound();

bool checkGameFinished(GameObjects::PlayerSea const & currentPlayerSea, GameObjects::PlayerSea const & otherPlayerSea);

Sea::Coordinates inputMissileTargetCoordinates(GameObjects::PlayerSea const & currentPlayerSea);


#endif //BLATT4_GAME_H
