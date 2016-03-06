#include "unit.h"

unit::unit(){ }

unit::unit( vec<int> x ){

    setGridLocation( x );

}

unit::unit( hexVec x){

    setHexLocation( x );

}

