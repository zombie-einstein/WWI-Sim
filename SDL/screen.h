#ifndef SCREEN_H
#define SCREEN_H

#include<SDL2/SDL.h>
#include<SDL_image.h>
#include <SDL_ttf.h>

#include "vec.h"

class screen{

    public:

        screen();

        ~screen();

        // Screen dimensions (set when initialized)
        vec<int> dimensions;

        // The Window to render to
        SDL_Window* window;

        // Window surface
        SDL_Renderer* renderer;

        //Small font for screen
        TTF_Font* screenFontSmall = NULL;

        //Large font for screen
        TTF_Font* screenFontLarge = NULL;

        // Initialize screen
        bool init( const char* label, int width, int height );

        bool loadFonts( const char* path );

        // Clear and update screen
        void clean();

        // Update the screen
        void update();

    protected:
    private:
};

#endif // SCREEN_H
