#include "mouse.h"

void mouseScrolling( vec screenSize, vec mousePos, vec &origin, int scrollRate ){

    if ( mousePos.x < 2 && mousePos.x > -1 ){ origin.x += scrollRate; }
    else if ( mousePos.x >= screenSize.x-1 ){ origin.x -= scrollRate; }
    if ( mousePos.y < 2 && mousePos.y > -1 ){ origin.y += scrollRate; }
    else if ( mousePos.y >= screenSize.y-1 ){ origin.y -= scrollRate; }

}

vec convertMouseToHex( vec mousePos, vec offset, variables* v ){

    // Convert screen co-ords of mouse to positive co-ords relative to map origin
    mousePos = vec ( mousePos.x - offset.x, offset.y - mousePos.y );

    // Affine transform from isometric co-ords to cartesian hexgrid
    double newMousePosX = 0.5*( mousePos.x/v->cosThirty - mousePos.y/v->sinThirty );
    double newMousePosY = 0.5*( mousePos.x/v->cosThirty + mousePos.y/v->sinThirty );

    // Rescale co-ords proportional to width of hex sprties
    newMousePosX = newMousePosX/v->isoScaling;
    newMousePosY = newMousePosY/v->isoScaling;

    // Affine transformations required to find "e" component of hex co-ord
    double findEastX = -newMousePosX/v->sqrtThree+newMousePosY-0.5;
    double findEastY = 2*newMousePosX/v->sqrtThree;

    // Affine transformation required to find "ne" component of hex co-ord
    double findNWestX = newMousePosX/v->sqrtThree+newMousePosY-0.5;
    double findNWestY = newMousePosX/v->sqrtThree-newMousePosY+0.5;

    vec mouseGridVec;

    // Locate transformed locations on hex grid
    mouseGridVec.x = floor( ( floor(findEastY)-floor(findEastX) )/3 );
    mouseGridVec.y = floor( ( floor(findNWestX)-floor(findNWestY) )/3 );

    return mouseGridVec;
}
