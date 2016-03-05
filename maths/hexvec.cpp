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

vec<int> hexVec::convertToSquare(){

    vec<int> tempVec( (ne +nw -(ne+nw)%2)/2 -nw +e, ne +nw );
    return tempVec;

}

void hexVec::print(){

    std::cout << "(" << e << "," << ne << "," << nw << ") ";

}
