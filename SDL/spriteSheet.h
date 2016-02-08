#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <string>
#include<SDL2/SDL.h>
#include<SDL_image.h>

class spriteSheet{
    public:
        spriteSheet();   // Initializes variables

        ~spriteSheet();  // Deallocate memory

        bool loadFromFile( std::string path, SDL_Renderer* );

        void free();    // Deallocate texture

        void render( int x, int y, SDL_Renderer*, SDL_Rect* clipBox = NULL );   // Render texture at (x,y)

        // Get image dimensions
        int getWidth();
        int getHeight();

        SDL_Texture* texture;   // Actual texture

        int width, height;

        private:

};

#endif // SPRITE_H
