#include "hex.h"

hex::hex()
{
    //ctor
}

hex::~hex()
{
    //dtor
}

void hex::setGridLocation( vec GRID ){

    gridLocation = GRID;
    hexLocation  = GRID.convertToHex();

}

void hex::setHexLocation( hexVec HEX ){

    hexLocation  = HEX;
    gridLocation = HEX.convertToSquare();

}
