#include "hex.h"

hex::hex(){ }

hex::hex( vec<int> x ){

    setGridLocation( x );

}

hex::hex( hexVec x ){

    setHexLocation( x );

}

void hex::setGridLocation( vec<int> GRID ){

    gridLocation = GRID;
    hexLocation  = GRID.convertToHex();

}

void hex::setHexLocation( hexVec HEX ){

    hexLocation  = HEX;
    gridLocation = HEX.convertToSquare();

}
