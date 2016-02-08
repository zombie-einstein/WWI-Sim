#include "hexvec.h"
#include "vec.h"

hexVec::hexVec(){
    e = 0;  ne = 0; nw = 0;
}

hexVec::hexVec( int E, int NE, int NW ){
    e = E;  ne = NE; nw = NW;
}

hexVec::~hexVec(){

    //dtor

}

vec hexVec::convertToSquare(){

    vec tempVec( e, ne +nw );
    return tempVec;

}
