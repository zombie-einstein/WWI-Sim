#include "infsquad.h"

infSquad::infSquad(){}

infSquad::infSquad( vec<int> x, int type ){

    setGridLocation(x);

    infType = type;

}

infSquad::infSquad( hexVec x, int type ){

    setHexLocation(x);

    infType = type;

}

void infSquad::render( hexSpriteList* infSprites ){

    infSprites->render( hexLocation, infType );

}
