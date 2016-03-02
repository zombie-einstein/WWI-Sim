#include "keyboard.h"

// Map control, moves the map render origin based on input

void mapControl( SDL_Event event, vec &mapOrigin, int shift ){

    switch( event.key.keysym.sym ){

        case SDLK_UP:       mapOrigin.y = mapOrigin.y +shift; break;

        case SDLK_DOWN:     mapOrigin.y = mapOrigin.y -shift; break;

        case SDLK_RIGHT:    mapOrigin.x = mapOrigin.x -shift; break;

        case SDLK_LEFT:     mapOrigin.x = mapOrigin.x +shift; break;

    }
}
