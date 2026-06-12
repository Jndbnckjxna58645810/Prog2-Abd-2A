#ifndef BLATT5_GRID2D_H
#define BLATT5_GRID2D_H

#include <vector>

using std::vector;

namespace Sea {
    // TODO Aufgabe 3:
    //  Erstellt eine Template-Klasse `Grid2D` mit dem Template-Klassen-Parameter `T`.
    template <typename T>
    class Grid2D {
    private:
        // TODO Aufgabe 3:
        //  Definiert die Member-Variable `grid` als Vektor von Vektoren mit Elementen vom Typ `T`.
        //  Jeder "innere" Vektor in `grid` soll dabei einer Zeile entsprechen, also der Y-Koordinate.
        //  Jede dieser Zeilen enthält gleich viele Elemente (vom Typ `T`), die jeweils eine Spalte bilden, also die X-Koordinate.
        //  Tipp: Wie ein Vektor von Vektoren definiert wird, ist bspw. bei der bisherigen Definition von `OutputGrid` in 'Output.h' zu sehen.
        vector<vector<T>> grid;
        // TODO Aufgabe 3:
        //  Erstellt einen Konstruktor `Grid2D(sizeX, sizeY, initElement)`.
        //  `sizeX` und `sizeY` sind die Größe in X- und Y-Richtung, also Y viele Vektoren (Zeilen) der Größe X.
        //  sowie ein Element vom Typ `T` zur Initialisierung der Vektoren.
    public:
        Grid2D(unsigned int sizeX, unsigned int sizeY, T const & initElement);
        // TODO Aufgabe 3:
        //  Erstellt zwei Methoden `sizeX()` und `sizeY()`.
        //  Sie sollen jeweils die Größe in X- bzw. Y-Richtung zurückgeben.
        unsigned int sizeX() const;
        unsigned int sizeY() const;
        // TODO Aufgabe 4:
        //  Überladet den `operator[]` so, dass er ein `Coordinates`-Element als Parameter erhält und eine Referenz auf das entsprechende Element zurückgibt.
        //  Instanzen von Grid2D sollen dann wie folgt verwendet werden können: `Coordinates c(3, 4); gridVariable[c] = ...`
        //  Erstellt zwei Varianten: einmal mit und einmal ohne `const` (Rückgabewert und Funktion).
        T & operator[](Coordinates const & coordinates);
        const T & operator[](Coordinates const & coordinates) const;
        // TODO Aufgabe 4:
        //  Überladet den `operator()` so, dass er X- und Y-Koordinaten als einzelne ganzzahlige Parameter erhält und eine Referenz auf das entsprechende Element zurückgibt.
        //  Instanzen von Grid2D sollen dann wie folgt verwendet werden können: `gridVariable(x, y) = ...` bzw. `gridVariable(3, 4) = ...`
        //  Erstellt zwei Varianten: einmal mit und einmal ohne `const` (Rückgabewert und Funktion).
        T & operator()(unsigned int x, unsigned int y);
        const T & operator()(unsigned int x, unsigned int y) const;
        // (TODO Aufgabe 6:)
        //   Warum werden von den Operatoren sowohl Varianten mit als auch ohne `const` benötigt?
        //
        // Die beiden unterschiedlichen Varianten (mit und ohne const) werden benötigt,
        // um die konstante Korrektheit (Const-Correctness) der Klasse zu garantieren.
        // 
        // 1. Die Variante OHNE const ermöglicht den schreibenden Zugriff auf die 
        //    Grid-Elemente eines veränderbaren Objekts (Rückgabe einer normalen Referenz T&).
        // 
        // 2. Die Variante MIT const wird zwingend benötigt, wenn das Grid-Objekt selbst 
        //    als 'const' deklariert ist. Da der Operator selbst als const markiert ist, 
        //    garantiert er, das Grid nicht zu verändern, und gibt folglich auch nur eine 
        //    schreibgeschützte Referenz (const T&) auf das Element zurück.
    };
}

#include "Grid2D.inl" // Siehe Hinweis in 'game.h'

#endif //BLATT5_GRID2D_H