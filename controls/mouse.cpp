#include "mouse.h"

mouse::mouse( variables* V, hexSpriteList* S, vec<int> sSize, vec<int> mMin, vec<int> mMax ){

    varPtr      = V;
    sptPtr      = S;
    screenSize  = sSize;
    mapMin      = mMin;
    mapMax      = mMax;

}

void mouse::updatePosition(){

    SDL_GetMouseState( &screenLocation.x, &screenLocation.y );

}

void mouse::mouseScrolling(){

    if ( screenLocation.x < 2 && varPtr->origin.x < mapPadding ){ varPtr->origin.x += scrollRate; }
    else if ( screenLocation.x > screenSize.x-2 && varPtr->origin.x > screenSize.x -mapPadding -mapMax.x ){ varPtr->origin.x -= scrollRate; }
    if ( screenLocation.y < 2 && varPtr->origin.y < mapPadding -mapMin.y ){ varPtr->origin.y += scrollRate; }
    else if ( screenLocation.y > screenSize.y-2 && varPtr->origin.y > screenSize.y -mapMax.y -mapPadding ){ varPtr->origin.y -= scrollRate; }

}


void mouse::convertToHex(){

    // Convert screen co-ords of mouse to positive co-ords relative to map origin
    vec<int> temp( screenLocation.x - varPtr->origin.x, varPtr->origin.y - screenLocation.y );

    // Transform and rescale to unit cartesian hex
    vec<double> newMouse( temp.x/varPtr->cosThirty - temp.y/varPtr->sinThirty, temp.x/varPtr->cosThirty + temp.y/varPtr->sinThirty );
    newMouse = newMouse*(0.5/varPtr->isoScaling);

    // Affine transformation required to find hex co-ord
    vec<double> findEast( -newMouse.x/varPtr->sqrtThree+newMouse.y-0.5, 2*newMouse.x/varPtr->sqrtThree );
    vec<double> findNEast( newMouse.x/varPtr->sqrtThree+newMouse.y-0.5, newMouse.x/varPtr->sqrtThree-newMouse.y+0.5 );

    // Locate transformed locations on hex grid
    co_ords.hexLocation.e  = floor( ( floor(findEast.y)-floor(findEast.x) )/3 );
    co_ords.hexLocation.ne = floor( ( floor(findNEast.x)-floor(findNEast.y) )/3 );

    co_ords.hexLocation.nw = 0;

    // Refactor hex location so that all components are positive
    if ( co_ords.hexLocation.e < 0 ){

        co_ords.hexLocation.nw = -co_ords.hexLocation.e;
        co_ords.hexLocation.ne += co_ords.hexLocation.e;
        co_ords.hexLocation.e  = 0;

    }
    // Convert hex co-ordinates to array co-ordinates
    co_ords.gridLocation = co_ords.hexLocation.convertToSquare();

}

void mouse::renderHex( int spriteNumber ){

    // Render the appropriately numbered sprite
    sptPtr->render( co_ords.hexLocation, spriteNumber, varPtr );

}

void mouse::printCoOrds(){

    std::cout << "Screen:";
    screenLocation.print();
    std::cout << " Array:";
    co_ords.gridLocation.print();
    std::cout << " Hex:";
    co_ords.hexLocation.print();
    std::cout << "\n";

}
