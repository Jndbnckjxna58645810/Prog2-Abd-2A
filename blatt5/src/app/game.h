#ifndef BLATT5_GAME_H
#define BLATT5_GAME_H


#include <vector>
#include <string>

#include "Coordinates.h"

#include "PlayerSea.h"


void gameLoop(std::vector<GameObjects::PlayerSea> & playerSeas);

bool gameTurn(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

void selectTypeAndSendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea, unsigned int round);

// TODO Aufgabe 2:
//  Die 3 Funktionen `send___Missile(..)` unterscheiden sich nur durch den Typ der jeweils erzeugten Rakete (`Missile`, `TumblingMissile`, oder `DoubleMissile`) und den Parameter `missileType` für `inputMissileTargetCoordinates(..)`.
//  Ersetzt diese 3 Funktionen durch eine einzige Funktion `sendMissile<MissileType>(currentPlayerSea, otherPlayerSea)`, die den Raketentyp als Template-Parameter erhält.
bool sendRegularMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea);
bool sendTumblingMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea);
bool sendDoubleMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea);

Sea::Coordinates inputMissileTargetCoordinates(GameObjects::PlayerSea const & currentPlayerSea, std::string const & missileType);

bool checkGameFinished(GameObjects::PlayerSea const & currentPlayerSea, GameObjects::PlayerSea const & otherPlayerSea);

void printCountdownToNextRound();


#include "game.inl" // Hinweis:
                    //  Typischerweise werden h-Dateien (in denen nur Deklarationen stehen) in cpp-Dateien inkludiert (in denen die Definitionen stehen).
                    //  Definitionen von Template-Funktionen/-Klassen müssen jedoch in den h-Dateien enthalten sein, damit sie allen inkludierenden cpp-Dateien verfügbar sind.
                    //  Um trotzdem "saubere" h-Dateien zu behalten, werden Template-Definitionen per Konvention in inl-Dateien geschrieben und in den h-Dateien inkludiert.


#endif //BLATT5_GAME_H
