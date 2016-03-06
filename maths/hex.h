// Combines hex and array co-ordinate values easing conversion between two
// In particular converting from hex co-ords to 2-d array storage

#ifndef HEX_H
#define HEX_H

#include "vec.h"
#include "hexvec.h"

class hex{

    public:

        hex();

        // Constructors from both a 2-d or hex co-ordinates
        hex( vec<int> x );
        hex( hexVec x );

        // Array co-ordinate vector
        vec <int> gridLocation;

        // Hex co-ordinates
        hexVec hexLocation;

        // Set location in 2-d co-ords, and generate corresponding hex co-ords
        void setGridLocation( vec<int> GRID );

        // Set location from hex co-ords and generate corresponding 2-d co-ords
        void setHexLocation( hexVec HEX );

    protected:
    private:

};

#endif // HEX_H
