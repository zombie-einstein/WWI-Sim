#ifndef HEXVEC_H
#define HEXVEC_H

//#include "vec.h"

template <class T> class vec;

class hexVec
{
    public:

        hexVec();

        hexVec( int E, int NE, int NW );

        ~hexVec();

        int e, ne, nw;

        // Convert a hex vector to a square vector
        vec<int> convertToSquare();

        // Print the co-ordinates to console
        void print();

    protected:
    private:
};

#endif // HEXVEC_H
