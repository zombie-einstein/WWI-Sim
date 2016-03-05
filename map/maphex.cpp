#include "maphex.h"

mapHex::mapHex(){
    //ctor
}

mapHex::mapHex( vec<int> x ){

    setGridLocation( x );
    terrain = 0;

}

mapHex::mapHex( hexVec x ){

    setHexLocation( x );
    terrain = 0;

}

mapHex::~mapHex(){
    //dtor
}

void mapHex::setElevation( int x ){

    elevation = x;

}

void mapHex::setTerrain( int x ){

    terrain = x;

}
