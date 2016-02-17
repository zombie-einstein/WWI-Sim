#include "spriteSheet.h"

using namespace std;


spriteSheet::spriteSheet(){
    texture = NULL;
    width   = 0;
    height  = 0;
}

spriteSheet::~spriteSheet(){

}

bool spriteSheet::loadFromFile( std::string path, SDL_Renderer* renderer ){

    free(); //Get rid of preexisting texture

    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

    if( loadedSurface == NULL ){
        printf( "Unable to load image! Error: ", path.c_str()," - ", IMG_GetError() );
    }
    else{
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL ){
            printf( "Unable to create texture! Error: ", path.c_str(), SDL_GetError() );
        }
        else{
            width   = loadedSurface->w;
            height  = loadedSurface->h;
        }

        SDL_FreeSurface( loadedSurface );
    }

    texture = newTexture;
    return texture != NULL;
}

void spriteSheet::free(){
    if( texture != NULL ){
        SDL_DestroyTexture( texture );
        texture = NULL;
        width   = 0;
        height  = 0;
    }
}

void spriteSheet::render( int x, int y, SDL_Renderer* mainRenderer, SDL_Rect* clipBox ){
    // Set rendering space
    SDL_Rect renderRect = { x, y, width, height };
    // Set clipping box
    if( clipBox != NULL ){
        renderRect.w = clipBox->w;
        renderRect.h = clipBox->h;
    }
    // Render to screen
    SDL_RenderCopy( mainRenderer, texture, clipBox, &renderRect );
}

int spriteSheet::getWidth(){ return width; }

int spriteSheet::getHeight(){ return height; }

