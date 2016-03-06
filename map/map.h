// Map class, stores a vector of maphex's and links to a list of terrain sprites

#ifndef MAP_H
#define MAP_H

// Libraries
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

// Header files
#include "maphex.h"
#include "hexspritelist.h"
#include "variables.h"

class map{

    public:
        // Constructor sets width and height of map
        // and fills the vector with the appropriate map hexs
        map( int WIDTH, int HEIGHT, hexSpriteList *terrain, variables *V );

        ~map();

        // Map dimensions in hexs
        int width, height;

        // Map pixel max and mins (relative to origin)
        vec<int> pixelMax, pixelMin;

        // Switch for showing rendering map boundary & grid lines
        bool renderBoundary = false, renderGridLines = false;

        // Pointer to set of terrrain sprites
        // associates map with terrain sprites
        hexSpriteList * terrainSprites;

        // Points to variables to translate map to pixels
        variables * varPtr;

        // Initial empty 2D vector of hexes
        std::vector< std::vector<mapHex> > hexes;

        // Populate vector with hexes with
        // appropriatte hex and array co-ordinates
        void fillHexes( int WIDTH, int HEIGHT );

        // Render hex sprites to their appropriate screen, from info in hex vector
        void render();

        // Read in a map from textfile
        void loadFromFile( const char* path );

        // Switch grid lines on off
        void gridLineSwitch();

    protected:
    private:

};

#endif // MAP_H
