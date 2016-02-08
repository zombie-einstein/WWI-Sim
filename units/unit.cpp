#include "unit.h"

unit::unit(){
    //ctor
}

unit::unit( vec x ){

    setGridLocation( x );

}

unit::unit( hexVec x){

    setHexLocation( x );

}

unit::~unit()
{
    //dtor
}
