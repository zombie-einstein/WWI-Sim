#include "map.h"

map::map( int WIDTH, int HEIGHT, hexSpriteList *terrain ){
    width  = WIDTH;
    height = HEIGHT;

    terrainSprites = terrain;

    fillHexes( WIDTH, HEIGHT );

}

map::~map()
{
    //dtor
}

void map::fillHexes( int WIDTH, int HEIGHT ){

    for( int i = 0; i < WIDTH; i++){
        // Temporary vector of columns
        std::vector <mapHex> column;

        for( int j = 0; j < HEIGHT; j++){

            //vec tempVec(i,j);
            column.push_back(mapHex(vec(i,j)));

        }

        hexes.push_back(column);

    }

}

void map::render( vec offsets[5] ){

    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){
         // Calculate the values added to place hex correctly on screen
         vec EAST = offsets[2]*hexes[i][j].hexLocation.e;
         vec NEAST= offsets[3]*hexes[i][j].hexLocation.ne;
         vec NWEST= offsets[4]*hexes[i][j].hexLocation.nw;
         // Render a sprite for each hex at this location on screen
         terrainSprites->render( offsets[0] +offsets[1] +EAST +NEAST + NWEST, hexes[i][j].terrain );

        }
    }

}

void map::loadFromFile( const char* path ){

    std::ifstream mapfile(path);
    //mapfile.open(path);
    std::string input;

    if( mapfile.is_open() ){

        for( int i = height-1; i > -1; i-- ){
                std::getline(mapfile,input);
            for( int j = 0; j < width; j++ ){

                int temp = (input[j] - '0');
                hexes[j][i].setTerrain(temp);

            }
        }
        mapfile.close();
    }
    else{ printf("Could not load map file"); }
}
