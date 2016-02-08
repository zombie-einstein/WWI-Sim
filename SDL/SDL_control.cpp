

#include<SDL2/SDL.h>
#include<SDL_image.h>


bool startSDL(){
    // Successful initialization bool
    bool success = true;
    // Return error and false if failed to initiaite SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0){
        printf( "SDL not initialized! SDL_Error:", SDL_GetError() );
        success = false;
    }
    else{
        // Set texture filtering to linear or return error and false
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY,  "1" ) ){
            printf( "Warning: Linear texture filtering not enabled!" );
            success = false;
        }
    }

     return success;

}

void stopSDL(){
    IMG_Quit();
    SDL_Quit();
}
