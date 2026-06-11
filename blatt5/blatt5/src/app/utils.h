#ifndef BLATT5_UTILS_H
#define BLATT5_UTILS_H


#include <iostream>


namespace Utils {

    struct n_endl {
        unsigned int n;

        explicit n_endl(unsigned int newN);
    };

    std::ostream & operator<<(std::ostream & stream, n_endl const & n);

}


#endif //BLATT5_UTILS_H
