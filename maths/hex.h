#ifndef HEX_H
#define HEX_H

#include "vec.h"
#include "hexvec.h"

class hex
{
    public:

        hex();

        ~hex();

        vec gridLocation;

        hexVec hexLocation;

        void setGridLocation( vec GRID );

        void setHexLocation( hexVec HEX );

    protected:
    private:
};

#endif // HEX_H
