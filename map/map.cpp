#include "map.h"

map::map( int WIDTH, int HEIGHT, hexSpriteList *terrain, variables *V ){

    width  = WIDTH;
    height = HEIGHT;

    terrainSprites = terrain;

    varPtr = V;

    // Generate the full vector of hexs
    fillHexes( WIDTH, HEIGHT );

    // Calculate Min and Max pixel values of the map relative to the origin
    vec<int> temp( WIDTH+1, HEIGHT );

    pixelMin.x = 0;
    pixelMin.y = temp.convertToHex().ne*V->ne.y+ temp.convertToHex().nw*V->nw.y;
    pixelMax.x = temp.convertToHex().e*V->e.x + temp.convertToHex().ne*V->ne.x + temp.convertToHex().nw*V->nw.x;
    pixelMax.y = varPtr->e.y * WIDTH ;

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
            column.push_back(mapHex(vec<int>(i,j)));

        }

        hexes.push_back(column);

    }

}

void map::render(){

    for( int i = 0; i < width; i++ ){
        for( int j = 0; j < height; j++ ){

            terrainSprites->render( hexes[i][j].hexLocation, hexes[i][j].terrain, varPtr );

            if ( renderGridLines ){

                terrainSprites->render( hexes[i][j].hexLocation, 5, varPtr );

            }
        }
    }

    // Render the map boundary (for testing purposes)
    if ( renderBoundary ){

        SDL_Rect mapRect = { varPtr->origin.x, varPtr->origin.y + pixelMin.y, pixelMax.x, pixelMax.y-pixelMin.y };
        SDL_SetRenderDrawColor( terrainSprites->renderer, 255, 0, 0, 255 );
        SDL_RenderDrawRect( terrainSprites->renderer, &mapRect);

    }
}

void map::loadFromFile( const char* path ){

    std::ifstream mapfile(path);
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

void map::gridLineSwitch(){

     renderGridLines = !renderGridLines;

}
