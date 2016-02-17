#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "map.h"
#include "screen.h"
#include "hexspritelist.h"
#include "keyboard.h"
#include "textsprite.h"
#include "menu.h"

// Define SDL control functions
bool startSDL();
void stopSDL();

// Static hex width and height for sprite sheet
int hexclip::clipWidth  = 100;
int hexclip::clipHeight = 58;
// Padding of UI elements (total)
vec UI_element::padding(10,10);
// UI background color (RGBA)
int UI_element::UIBackGroundColor[4] = { 200, 200, 200, 255 };

int main ( int argc, char* args[] )
{
    if ( startSDL() ){
            // Initialize a screen class
            screen mainScreen;
            // Create screen
            mainScreen.init("SIM", 1280, 480);

            // Create hexlist with 4 hexes rendered by mainScreen
            hexSpriteList terrain( "sprites/terrain_hex.png", 5, mainScreen.renderer );
            hexSpriteList units( "sprites/unit_hex.png", 4, mainScreen.renderer );

            // Load desired font to main screen
            mainScreen.loadFonts("sprites/BOMBARD.ttf");

            // Make text sprite (white)
            textSprite title;
            title.loadFromRenderedText("WWI SIM v0.1", { 255, 255, 255 }, mainScreen.renderer, mainScreen.screenFontLarge );

            textSprite smallExample;
            smallExample.loadFromRenderedText("small text example", { 255, 255, 255 }, mainScreen.renderer, mainScreen.screenFontSmall );

            button buttons[2] = { button ( "Button", &mainScreen ), button( "Button B", &mainScreen ) };

            //testButton.setLocation(vec(10,10));

            menu testMenu( "Menu", &mainScreen );
            testMenu.addButton("A button");
            testMenu.addButton("A longer button");
            //Main loop flag
			bool quit = false;

            //Event handler
			SDL_Event event;

            // Vector of hex direction offsets
            // for this given hex size
            vec offsets[4];

            offsets[0] = vec(  0 , 200); // Location of origin i.e. cell(0,0) on screen
            offsets[1] = vec(  62, 36 ); // Moves one cell east
            offsets[2] = vec(  22,-49 ); // Moves one cell north-east
            offsets[3] = vec(  85,-13 ); // Moves one cell north-west

            // Test map
            map testMap(12,8, &terrain);

            testMap.loadFromFile("data/testmap.txt");

            // **** Main application loop starts here ****

			//While application is running
			while( !quit ){
				//Handle events on queue
				while( SDL_PollEvent( &event ) != 0 ){
					//User requests quit
					if( event.type == SDL_QUIT || event.type == SDLK_ESCAPE ){
						quit = true;
					}
					if( event.type == SDL_KEYDOWN){

                        mapControl(event, offsets[0], 10);

                        switch( event.key.keysym.sym ){

                        case SDLK_ESCAPE:   quit = true; break;

                        case SDLK_F1:       SDL_SetWindowFullscreen(mainScreen.window, SDL_WINDOW_FULLSCREEN); break;

                        }
					}
				}

                // Clean, render sprite and update
                mainScreen.clean();

                testMap.render(offsets);

                title.render(50,50,mainScreen.renderer);
                smallExample.render(50,75,mainScreen.renderer);


                testMenu.render(50,150);

                mainScreen.update();

			}

            // **** Main loop ended here

            stopSDL();

        }


    return 0;
}
