#ifndef BLATT6_OUTPUT_H
#define BLATT6_OUTPUT_H


#include <string>

#include "Grid2D.h"


namespace GameObjects {

    struct OutputGridCell {
        std::string output = " ~  ";
        bool ship = false;
        unsigned int missiles = 0;
    };

    using OutputGrid = Sea::Grid2D<OutputGridCell>;

}


#endif //BLATT6_OUTPUT_H
