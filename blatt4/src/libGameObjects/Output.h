#ifndef BLATT4_OUTPUT_H
#define BLATT4_OUTPUT_H


#include <string>
#include <vector>


namespace GameObjects {

    struct OutputGridCell {
        std::string output = " ~  ";
        bool ship = false;
        int missiles = 0;
    };

    using OutputGridLine = std::vector<OutputGridCell>;
    using OutputGrid = std::vector<OutputGridLine>;

}


#endif //BLATT4_OUTPUT_H
