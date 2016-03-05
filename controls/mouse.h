#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED

#include <SDL2/SDL.h>
#include <math.h>
#include "vec.h"
#include "variables.h"
#include "hexspritelist.h"
#include "hex.h"

class mouse{

    public:

        mouse( variables* V, hexSpriteList* S, vec<int> sSize, vec<int> mMin, vec<int> mMax  );

        // Mouse location on screen
        vec<int> screenLocation;

        // Mouse location in isometric map hex's
        hex co_ords;

        // Pointer to hex-pixel variable list
        variables* varPtr;

        // Pointer to selection sprite list
        hexSpriteList* sptPtr;

        // Padding around map
        int mapPadding = 100;

        // Mouse scroll rate
        int scrollRate = 1;

        // Screen dimensions
        vec<int> screenSize;

        // Map minimum dimensions on screen
        vec<int> mapMin;

        // Map maximum dimension on screen
        vec<int> mapMax;

        // update mouse position from SDL
        void updatePosition();

        // Check if mouse is at boundary and apply scrolling
        void mouseScrolling();

        // Convert pixel location to hex Location
        void convertToHex();

        // Render the appropriate selection hex
        void renderHex( int spriteNumber );

        // Print co-ords
        void printCoOrds();
};

#endif // MOUSE_H_INCLUDED
