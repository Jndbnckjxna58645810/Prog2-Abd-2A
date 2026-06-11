
// Siehe Hinweis in 'game.inl'

#include <exception>

class Grid2DInvalidSizeException : public std::exception {
private:
    const char * what() const noexcept override { return "sizeX and sizeY must both be > 0"; }
};

// TODO Aufgabe 3:
//  Implementiert den Konstruktor von Grid2D.
//  Stellt mithilfe einer Grid2DInvalidSizeException sicher, dass kein Grid2D mit einer ungültigen Größe (< 1x1) erstellt werden kann.
//  Tipp: Zur Initialisierung stellt `std::vector` einen entsprechenden Konstruktor zur Verfügung: `std::vector<ElementTyp>(Anzahl, initElement)`
//        Dieser wurde auch schon für `gridOwnSea` in 'PlayerSea.h' verwendet.
/*
 ???
 */

// TODO Aufgabe 3:
//  Implementiert `sizeX()` und `sizeY()`.
//  Erinnerung: die Größe in X-Richtung entspricht dabei der Anzahl der Elemente (vom Typ `T`) in den "inneren" Vektoren.
//                           Y-Richtung ist die Größe des "außeren" Vektors `grid`.
/*
 ???
 */

// TODO Aufgabe 4:
//  Implementiert die 4 Operator-Überladungen.
//  Stellt sicher, dass Exceptions geworfen werden, wenn ungültige Koordinaten übergeben wurden.
/*
 ???
 */
