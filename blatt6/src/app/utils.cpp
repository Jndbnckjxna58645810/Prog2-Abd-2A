#include "utils.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;


namespace Utils {

    n_endl::n_endl(unsigned int newN)
            : n(newN)
    {
    }

    ostream & operator<<(ostream & stream, n_endl const & n)
    {
        for (unsigned int i = 0; i < n.n; ++i) {
            cout << endl;
        }
        return stream;
    }

}
