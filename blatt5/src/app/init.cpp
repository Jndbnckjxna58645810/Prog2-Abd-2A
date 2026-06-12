#include "init.h"

#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::getline;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <climits>

#include "Coordinates.h"
using Sea::Coordinates;
#include "Object.h"
using Sea::Orientation;

#include "Constants.h"
using GameObjects::Constants;
#include "Ship.h"
using GameObjects::Ship;
#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "utils.h"
using Utils::n_endl;

unsigned int const Constants::seaSizeX = 5;
unsigned int const Constants::seaSizeY = 5;
vector<unsigned int> const Constants::shipSizes = { 1, 2 };

void initializePlayerSeasWithShips(vector<PlayerSea> & playerSeas)
{
    for (unsigned int playerIdx = 0; playerIdx < 2; ++playerIdx) {
        string playerName = inputPlayerName();
        playerSeas.emplace_back(playerName);
        initializeShips(playerSeas[playerIdx]);
    }
}

string inputPlayerName()
{
    static unsigned int playerCount = 0;
    cout << endl << "Name von Spieler " << ++playerCount << ":";

    string playerName;
    getline(cin, playerName);
    return playerName;
}

void initializeShips(PlayerSea & playerSea)
{
    cout << "Setze deine Schiffe ins Wasser (" << PlayerSea::getSeaBounds() << ")." << endl;

    for (unsigned int shipIdx = 0; shipIdx < Constants::shipSizes.size(); ++shipIdx) {
        auto size = Constants::shipSizes[shipIdx];

        while (!initializeShip(playerSea, size));
    }
    cout << n_endl(20);
}

bool initializeShip(PlayerSea & playerSea, unsigned int size)
{
    Ship ship = inputShip(size);
    auto addResult = playerSea.addShip(ship);
    if (addResult == PlayerSea::AddShipResult::outsideSeaBounds) {
        cout << "Das Schiff muss im Wasser liegen (" << PlayerSea::getSeaBounds() << ")." << endl;
        return false;
    }
    else if (addResult == PlayerSea::AddShipResult::overlapOtherShip) {
        cout << "Dort liegt schon ein Schiff." << endl;
        return false;
    }
    return true;
}

Ship inputShip(unsigned int size)
{
    cout << endl << "Neues Schiff der Groesse " << size << endl;
    Coordinates coordinates = inputCoordinates();
    Orientation orientation = inputOrientation();

    return Ship(coordinates, size, orientation);
}

Coordinates inputCoordinates()
{
    unsigned int x, y;
    do {
        cout << "  x y:";
        cin >> x >> y;
    } while (checkForInputError());
    return Coordinates(x, y);
}

Orientation inputOrientation()
{
    string orientation;
    do {
        cout << "  Ausrichtung nach (r/rechts oder u/unten):";
        cin >> orientation;
    } while (checkForInputError() || (orientation[0] != 'r' && orientation[0] != 'u'));
    return orientation[0] == 'r' ? Orientation::X : Orientation::Y;
}

bool checkForInputError()
{
    bool error = cin.fail();
    if (error) {
        cout << "Eingabe fehlerhaft." << endl;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return error;
}
