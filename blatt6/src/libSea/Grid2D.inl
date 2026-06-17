
class Grid2DInvalidSizeException : public std::exception {
private:
    const char * what() const noexcept override { return "sizeX and sizeY must both be > 0"; }
};

template<class T>
Sea::Grid2D<T>::Grid2D(unsigned int sizeX, unsigned int sizeY, T const & initElement)
: grid(sizeY, std::vector<T>(sizeX, initElement))
{
    if (sizeX == 0 || sizeY == 0) {
        throw Grid2DInvalidSizeException();
    }
}

template<class T>
unsigned int Sea::Grid2D<T>::sizeX() const
{
    return static_cast<unsigned int>(grid[0].size());
}

template<class T>
unsigned int Sea::Grid2D<T>::sizeY() const
{
    return static_cast<unsigned int>(grid.size());
}

template<class T>
unsigned int Sea::Grid2D<T>::size() const
{
    return sizeX() * sizeY();
}

template<class T>
T const & Sea::Grid2D<T>::operator[](Sea::Coordinates const & coords) const
{
    return grid.at(coords.getY()).at(coords.getX());
}

template<class T>
T & Sea::Grid2D<T>::operator[](Sea::Coordinates const & coords)
{
    return grid.at(coords.getY()).at(coords.getX());
}

template<class T>
T const & Sea::Grid2D<T>::operator()(unsigned int x, unsigned int y) const
{
    return grid.at(y).at(x);
}

template<class T>
T & Sea::Grid2D<T>::operator()(unsigned int x, unsigned int y)
{
    return grid.at(y).at(x);
}

// TODO Aufgabe 2:
//  Implementiert hier die Funktion `walk(..)`.
//  Sie soll die übergebene (Lambda-)Funktion `operation` einmal für jedes Element im Grid aufrufen.
//  Es wird also mindestens eine Schleife (loop) benötigt, um über alle Elemente zu iterieren.
template<class T>
void Sea::Grid2D<T>::walk(auto const & operation) const {
    for (unsigned int y = 0; y < sizeY(); ++y) {
        for (unsigned int x = 0; x < sizeX(); ++x) {
            operation((*this)(x, y));
        }
    }
}

// TODO Aufgabe 2:
//  Implementiert hier die Funktion `filter(..)`.
//  Sie soll die übergebene (Lambda-)Funktion `condition` nutzen, um jedes Element zu prüfen.
//  Für die (Lambda-)Funktion `condition` soll der Typ std::function genutzt werden, 
//  um Rückgabetyp und Typ der an die (Lamda-)Funktion übergebenen Elemente spezifizieren zu können.
//  Alle Elemente, für die die Funktion "true" zurückgibt, sollen gesammelt in einem `vector` zurückgegeben werden.
//  Es wird also mindestens eine Schleife (loop) benötigt, um über alle Elemente zu iterieren.
//  Die Elemente in dem Ergebnis-`vector` sollen Kopien sein.
template<class T>
std::vector<T> Sea::Grid2D<T>::filter(auto const & condition) const {
    std::vector<T> result;
    for (unsigned int y = 0; y < sizeY(); ++y) {
        for (unsigned int x = 0; x < sizeX(); ++x) {
            if (condition((*this)(x, y))) {
                result.push_back((*this)(x, y));
            }
        }
    }
    return result;
}

template<class T>
unsigned int Sea::Grid2D<T>::count(auto const & predicate) const {
    unsigned int r = 0;
    for (unsigned int y = 0; y < sizeY(); ++y) {
        for (unsigned int x = 0; x < sizeX(); ++x) {
            if (predicate((*this)(x, y))) { ++r; }
        }
    }
    return r;
}
