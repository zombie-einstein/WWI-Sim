// Create an SDL texture from spriteshet file

#ifndef SPRITESHEET_H
#define SPRITESHEET_H

// Libraries
#include <string>
#include<SDL2/SDL.h>
#include<SDL_image.h>

class spriteSheet{

    public:

        // Initializes variables
        spriteSheet();

        // Deallocate memory
        ~spriteSheet();

        // Load texture from file
        bool loadFromFile( std::string path, SDL_Renderer* );

        // Deallocate texture
        void free();

        // Render texture on screen at (x,y), defaults to non-clip if no clipbox provided
        void render( int x, int y, SDL_Renderer*, SDL_Rect* clipBox = NULL );

        // Get image dimensions
        int getWidth();
        int getHeight();

        // Actual texture
        SDL_Texture* texture;

        // Texture widths and heights
        int width, height;

        private:

};

#endif // SPRITE_H
