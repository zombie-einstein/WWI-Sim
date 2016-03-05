#include "hexspritelist.h"

hexSpriteList::hexSpriteList( std::string path, int n, SDL_Renderer* r ){

    // Set number of hexes to use
    numSprites  = n;
    // Set path of hex sheet associated with list
    sheetPath   = path;
    // Fill the vector of hex clipsheets
    fillHexVector();
    // Set pointer to desired renderer
    renderer    = r;
    // Load spritesheet assocaited with these hexes to renderer
    loadMedia();
}

hexSpriteList::~hexSpriteList(){
    // On destruction free texture
    hexSheet.free();

}

void hexSpriteList::fillHexVector(){

    for ( int i = 0; i < numSprites; i++ ){
        hexes.push_back( hexclip(i,0) );
    }
}

bool hexSpriteList::loadMedia(){

    //  Success flag
    bool success = true;

    // Load sprite A
    if( !hexSheet.loadFromFile( sheetPath, renderer ) ){
        printf( "Failed to load texture ");
        success = false;
    }

    return success;
}

void hexSpriteList::render( vec<int> location, int n ){

    hexSheet.render( location.x, location.y, renderer, &hexes[n].clipBox );

}

void hexSpriteList::render( int x, int y, int n ){

    hexSheet.render( x, y, renderer, &hexes[n].clipBox );

}
