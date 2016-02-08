#ifndef HEXSPRITELIST_H
#define HEXSPRITELIST_H


#include <vector>
#include <string>

#include "spriteSheet.h"
#include "hexclip.h"
#include "vec.h"


class hexSpriteList
{
    public:

        // Initialize with spriteSheet path and number of sprites to load
        hexSpriteList( std::string path, int n, SDL_Renderer* );

        ~hexSpriteList();

        int numSprites;

        std::string sheetPath;

        SDL_Renderer* renderer;

        spriteSheet hexSheet;

        std::vector<hexclip> hexes;

        // Generate the list of hex's
        void fillHexVector();

        // Load a sprite to screen
        bool loadMedia();

        // Render a specific hex (from vector)
        void render( vec location, int hexNum );

        // Render a specific hex (from vector)
        void render( int x, int y, int hexNum );


    protected:

    private:
};

#endif // HEXSPRITELIST_H
