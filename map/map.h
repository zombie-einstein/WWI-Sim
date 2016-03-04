#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "maphex.h"
#include "hexspritelist.h"

class map
{
    public:
        // Constructor sets width and height of map
        // and fills the vector with the appropriate map hexs
        map( int WIDTH, int HEIGHT, hexSpriteList *terrain );

        ~map();

        // Map dimensions in hexs
        int width, height;

        // Pointer to set of terrrain sprites
        // associates map with terrain sprites
        hexSpriteList * terrainSprites;

        // Initial empty 2D vector of hexes
        std::vector< std::vector<mapHex> > hexes;

        // Populate vector with hexes with
        // appropriatte co-ordinates
        void fillHexes( int WIDTH, int HEIGHT );

        // Render map on given screen
        void render( vec offsets[5] );

        // Read in a map from textfile
        void loadFromFile( const char* path );

    protected:
    private:
};

#endif // MAP_H
