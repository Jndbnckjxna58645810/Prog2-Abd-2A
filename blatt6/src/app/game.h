#ifndef BLATT6_GAME_H
#define BLATT6_GAME_H


#include <vector>
#include <string>

#include "Coordinates.h"

#include "PlayerSea.h"


void gameLoop(std::vector<GameObjects::PlayerSea> & playerSeas);

bool gameTurn(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

void selectTypeAndSendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

template<class T>
bool sendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea);

Sea::Coordinates inputMissileTargetCoordinates(GameObjects::PlayerSea const & currentPlayerSea, std::string const & missileType);

bool checkGameFinished(GameObjects::PlayerSea const & currentPlayerSea, GameObjects::PlayerSea const & otherPlayerSea);

void printCountdownToNextRound();

void printStats(std::vector<GameObjects::PlayerSea> & playerSeas);


#include "game.inl"


#endif //BLATT6_GAME_H
