#include "mouse.h"

void mouseScrolling( vec screenSize, vec mousePos, vec &origin, int scrollRate ){

    if ( mousePos.x < 2 && mousePos.x > -1 ){ origin.x += scrollRate; }
    else if ( mousePos.x >= screenSize.x-1 ){ origin.x -= scrollRate; }
    if ( mousePos.y < 2 && mousePos.y > -1 ){ origin.y += scrollRate; }
    else if ( mousePos.y >= screenSize.y-1 ){ origin.y -= scrollRate; }

}
