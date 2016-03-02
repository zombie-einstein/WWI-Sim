#include "screen.h"

screen::screen(){
    // Set window and renderer pointers to NULL
    window      = NULL;
    renderer    = NULL;
}

screen::~screen(){
    // Destror window and renderer
    SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	TTF_CloseFont(screenFontLarge);
	TTF_CloseFont(screenFontSmall);
	// Dereference pointers
	renderer    = NULL;
	window      = NULL;
	// This is a general screen case so don't quit SDL system
}

// Initialize screen
bool screen::init( const char* label, int width, int height ){

    // Initialization flag
    bool success = true ;

    dimensions.x = width;
    dimensions.y = height;

    // create window
    window = SDL_CreateWindow(label, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
    if( window == NULL ){
            printf( "Window ", label, " could not be created! SDL_Error: ", SDL_GetError() );
            success = false;
        }
        else{
            // Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == NULL ){
                printf( "Renderer ", label, "could not be created! SDL Error: ", SDL_GetError() );
                success = false;
            }
            else{
                // Initialize renderer color
                SDL_SetRenderDrawColor( renderer,  0, 0, 0, 255 );
                SDL_RenderPresent( renderer );

                //Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ){
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
                }
				//Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }

    return success;
}

bool screen::loadFonts( const char* path ){

    // Loading success flag
    bool success = true;

    // Load small font
    screenFontSmall = TTF_OpenFont( path, 15 );
    if ( screenFontSmall == NULL ){
        printf( "Failed to load small font: ", path );
        success = false;
    }

    // Load font
    screenFontLarge = TTF_OpenFont( path, 30 );
    if ( screenFontLarge == NULL ){
        printf( "Failed to load large font: ", path );
        success = false;
    }

    return success;
}

void screen::clean(){

    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );

}

void screen::update(){

    SDL_RenderPresent( renderer );

}
