#ifndef SCREEN_H
#define SCREEN_H

#include<SDL2/SDL.h>
#include<SDL_image.h>
#include <SDL_ttf.h>

class screen{

    public:

        screen();

        ~screen();

        // The Window to render to
        SDL_Window* window;

        // Window surface
        SDL_Renderer* renderer;

        //Globally used font
        TTF_Font* screenFont = NULL;

        // Initialize screen
        bool init( const char* label, int width, int height );

        bool loadFont( const char* path );

        // Clear and update screen
        void clean();

        // Update the screen
        void update();

    protected:
    private:
};

#endif // SCREEN_H
