// Creates a vector of clipboxes and links them with a sprite sheet a screen renderer

#ifndef HEXSPRITELIST_H
#define HEXSPRITELIST_H

// Libraries
#include <vector>
#include <string>

// Header Files
#include "spriteSheet.h"
#include "hexclip.h"
#include "hexvec.h"
#include "vec.h"
#include "variables.h"


class hexSpriteList{

    public:

        // Initialize with spriteSheet path and number of sprites to load
        hexSpriteList( std::string path, int n, SDL_Renderer* );

        ~hexSpriteList();

        // Number of sprites in list
        int numSprites;

        // Sprite sheet path
        std::string sheetPath;

        // Renderer to be used
        SDL_Renderer* renderer;

        spriteSheet hexSheet;

        std::vector<hexclip> hexes;

        // Generate the list of hex's
        void fillHexVector();

        // Load a sprite to screen
        bool loadMedia();

        // Render a specific hex (from vector)
        void render( vec<int> location, int hexNum );

        // Render a specific hex (from vector)
        void render( int x, int y, int hexNum );

        // Render a specific hex (from a hex grid location relative to the origin)
        void render( hexVec hexLocation, int hexNum, variables* vars );

    protected:

    private:
};

#endif // HEXSPRITELIST_H
