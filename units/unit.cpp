#include "unit.h"

unit::unit(){
    //ctor
}

unit::unit( vec<int> x ){

    setGridLocation( x );

}

unit::unit( hexVec x){

    setHexLocation( x );

}

unit::~unit()
{
    //dtor
}
