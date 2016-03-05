#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

#include<SDL2/SDL.h>
#include<SDL_image.h>
#include "vec.h"

void mapControl( SDL_Event event, vec<int> &mapOrigin, int shift );

#endif // KEYBOARD_H_INCLUDED
