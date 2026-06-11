#ifndef BLATT5_OUTPUT_H
#define BLATT5_OUTPUT_H


#include <string>
#include <vector>


namespace GameObjects {

    struct OutputGridCell {
        std::string output = " ~  ";
        bool ship = false;
        int missiles = 0;
    };

    // TODO Aufgabe 5:
    //  Verwendet statt der vector-vector-Deklaration von `OutputGrid` eure Template-Klasse `Sea::Grid2D`, um die `OutputGridCell`-Instanzen zu verwalten.
    using OutputGrid = std::vector<std::vector<OutputGridCell>>;

}


#endif //BLATT5_OUTPUT_H
