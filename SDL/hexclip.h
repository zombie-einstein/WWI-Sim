// Creates a SDL clipbox from co-ordinates (on sprite sheet) and static sprite dimensions

#ifndef HEXCLIP_H
#define HEXCLIP_H

// Libraries
#include<SDL2/SDL.h>
#include<SDL_image.h>

class hexclip{

    public:

        hexclip();

        hexclip( int n, int m );

        // Hex sprites have a standard width
        static int clipWidth;

        // Hex sprites have a standard height
        static int clipHeight;

        // clipping box for sprite sheet
        SDL_Rect clipBox;

        // Set clipbox values
        void setClipBox( int n, int m );

    protected:
    private:

};

#endif // HEXCLIP_H
