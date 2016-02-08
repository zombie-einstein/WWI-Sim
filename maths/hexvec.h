#ifndef HEXVEC_H
#define HEXVEC_H

//#include "vec.h"

class vec;

class hexVec
{
    public:

        hexVec();

        hexVec( int E, int NE, int NW );

        ~hexVec();

        int e, ne, nw;

        // Convert a hex vector to a square vector
        vec convertToSquare();

    protected:
    private:
};

#endif // HEXVEC_H
