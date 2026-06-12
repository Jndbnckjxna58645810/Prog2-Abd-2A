// Siehe Hinweis in 'game.inl'

#include <exception>
#include "Coordinates.h"

class Grid2DInvalidSizeException : public std::exception {
private:
    const char * what() const noexcept override { return "sizeX and sizeY must both be > 0"; }
};

// TODO Aufgabe 3:
//  Implementiert den Konstruktor von Grid2D.
//  Stellt mithilfe einer Grid2DInvalidSizeException sicher, dass kein Grid2D mit einer ungültigen Größe (< 1x1) erstellt werden kann.
//  Tipp: Zur Initialisierung stellt `std::vector` einen entsprechenden Konstruktor zur Verfügung: `std::vector<ElementTyp>(Anzahl, initElement)`
//        Dieser wurde auch schon für `gridOwnSea` in 'PlayerSea.h' verwendet.
namespace Sea {
    template <typename T>
    Grid2D<T>::Grid2D(unsigned int sizeX, unsigned int sizeY, T const & initElement) {
        if (sizeX < 1 || sizeY < 1) {
            throw Grid2DInvalidSizeException();
        }
        grid.resize(sizeY, std::vector<T>(sizeX, initElement));
    }
// TODO Aufgabe 3:
//  Implementiert `sizeX()` und `sizeY()`.
//  Erinnerung: die Größe in X-Richtung entspricht dabei der Anzahl der Elemente (vom Typ `T`) in den "inneren" Vektoren.
//                           Y-Richtung ist die Größe des "außeren" Vektors `grid`.
    template <typename T>
    unsigned int Grid2D<T>::sizeX() const {
        return grid.empty() ? 0 : grid[0].size();
    }
    template <typename T>
    unsigned int Grid2D<T>::sizeY() const {
        return grid.size();
    }
// TODO Aufgabe 4:
//  Implementiert die 4 Operator-Überladungen.
//  Stellt sicher, dass Exceptions geworfen werden, wenn ungültige Koordinaten übergeben wurden.
    template <typename T>
    T & Grid2D<T>::operator[](Coordinates const & coordinates) {
        if (coordinates.getX() >= sizeX() || coordinates.getY() >= sizeY()) {
            throw std::out_of_range("Coordinates are out of bounds of the Grid2D.");
        }
        return grid[coordinates.getY()][coordinates.getX()];
    }
    template <typename T>
    const T & Grid2D<T>::operator[](Coordinates const & coordinates) const {
        if (coordinates.getX() >= sizeX() || coordinates.getY() >= sizeY()) {
            throw std::out_of_range("Coordinates are out of bounds of the Grid2D.");
        }
        return grid[coordinates.getY()][coordinates.getX()];
    }
    template <typename T>
    T & Grid2D<T>::operator()(unsigned int x, unsigned int y) {
        return (*this)[Coordinates(x, y)];
    }
    template <typename T>
    const T & Grid2D<T>::operator()(unsigned int x, unsigned int y) const {
        return (*this)[Coordinates(x, y)];
    }
}