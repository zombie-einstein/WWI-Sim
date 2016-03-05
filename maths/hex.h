#ifndef HEX_H
#define HEX_H

#include "vec.h"
#include "hexvec.h"

class hex{

    public:

        hex();

        ~hex();

        vec <int> gridLocation;

        hexVec hexLocation;

        void setGridLocation( vec<int> GRID );

        void setHexLocation( hexVec HEX );

    protected:
    private:
};

#endif // HEX_H
