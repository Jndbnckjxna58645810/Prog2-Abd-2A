
// Hinweis: Da diese .inl-Datei in einer h-Datei inkludiert wird, darf/sollte hier (im Vergleich zu cpp-Dateien) kein `using ..` verwendet werden.


// TODO Aufgabe 2:
//  Implementiert hier die Template-Funktion `sendMissile<MissileType>(..)`.
template <typename T>
bool sendMissile(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea)
{
    Sea::Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea, T::getName());
    auto missile = std::make_shared<T>(targetCoordinates);
    return currentPlayerSea.sendMissileTo(otherPlayerSea, missile);
}
