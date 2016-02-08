#ifndef HEXCLIP_H
#define HEXCLIP_H

#include<SDL2/SDL.h>
#include<SDL_image.h>

class hexclip
{
    public:

        hexclip();

        hexclip( int, int );

        ~hexclip();

        static int clipWidth;   // Hex's have a standard width

        static int clipHeight;  // Hex's have a standard height

        SDL_Rect clipBox;  // clipping box for sprite sheet

        // Set clipbox values
        void setClipBox( int, int );

    protected:
    private:
};

#endif // HEXCLIP_H
