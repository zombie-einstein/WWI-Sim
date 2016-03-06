#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

// Libraries
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <functional>
#include <math.h>

// Header Files
#include "variables.h"
#include "map.h"
#include "screen.h"
#include "hexspritelist.h"
#include "keyboard.h"
#include "textsprite.h"
#include "vert_menu.h"
#include "mouse.h"

// Declare SDL control functions (SDL_Controls.cpp)
bool startSDL();
void stopSDL();

// Static hex width and height for sprite sheet
int hexclip::clipWidth  = 100;
int hexclip::clipHeight = 58;

// Padding of UI elements (total)
vec<int> UI_element::padding(10,10);

// UI background color static (RGBA)
int UI_element::UIBackGroundColor[4] = { 200, 200, 200, 255 };


int main ( int argc, char* args[] )
{
    if ( startSDL() ){

            // Initialize a screen class
            screen mainScreen;

            // Create screen
            mainScreen.init("SIM", 800, 400);

            // Create hexlists
            hexSpriteList terrain( "sprites/terrain_hex.png", 6, mainScreen.renderer );
            hexSpriteList units( "sprites/unit_hex.png", 4, mainScreen.renderer );
            hexSpriteList selectSprite( "sprites/select.png", 2, mainScreen.renderer );

            // Load desired font to main screen
            mainScreen.loadFonts("sprites/BOMBARD.ttf");

            // Initialize hex variables for given sprite width and origin
            variables vars( vec<int>(0,200), hexclip::clipWidth );

            // Make title text sprite (white)
            textSprite title;
            title.loadFromRenderedText("WWI SIM v0.1", { 255, 255, 255 }, mainScreen.renderer, mainScreen.screenFontLarge );

            textSprite smallExample;
            smallExample.loadFromRenderedText("small text example", { 255, 255, 255 }, mainScreen.renderer, mainScreen.screenFontSmall );

            //Main loop flag
			bool quit = false;

            //Event handler
			SDL_Event event;

            // Test map
            map testMap(12,8, &terrain, &vars);

            testMap.loadFromFile("data/testmap.txt");

            // Create mouse object
            mouse mouseA( &vars, &selectSprite, mainScreen.dimensions, testMap.pixelMin, testMap.pixelMax );


            // Make a test menu
            vert_menu testMenu( "Test Menu", &mainScreen );
            testMenu.addButton("Move Menu to corner");
            testMenu.addButton("Move Menu back");
            testMenu.addButton("Grid Lines On/Off");
            testMenu.setLocation( vec<int>(50,50));

            // Use bind to attach function definitions to class members
            testMenu.buttonList[0].click = std::bind( &vert_menu::setLocation, &testMenu, vec<int>(10,10) );
            testMenu.buttonList[1].click = std::bind( &vert_menu::setLocation, &testMenu, vec<int>(50,150) );
            testMenu.buttonList[2].click = std::bind( &map::gridLineSwitch, &testMap );

            //================= Main application loop starts here ======================//

			//While application is running
			while( !quit ){

                // Continually update mouse position vector
                mouseA.updatePosition();
                // Convert screen position to hex vector
                mouseA.convertToHex();
                // Check for mouse scrolling
                mouseA.mouseScrolling();

				//Handle events on queue
				while( SDL_PollEvent( &event ) != 0 ){

					//User requests quit
					if( event.type == SDL_QUIT || event.type == SDLK_ESCAPE ){
						quit = true;
					}
					if( event.type == SDL_KEYDOWN){

                        mapControl(event, vars.origin, 10);

                        switch( event.key.keysym.sym ){

                        // Exit main window
                        case SDLK_ESCAPE:   quit = true;
                                            break;

                        // F1 to go fullscreen
                        case SDLK_F1:       mainScreen.goFullscreen();
                                            break;

                        }
					}

					if ( event.type == SDL_MOUSEBUTTONDOWN ){

                        testMenu.mouseCheck( mouseA.screenLocation );
                        mouseA.printCoOrds();

					}
				}

                // Clean, render sprites and update
                mainScreen.clean();

                testMap.render();    // Render map

                mouseA.renderHex(1); // Render mouse hex
                mouseA.renderHex(0); // Render mouse hex border

                // Render title
                title.render( mainScreen.dimensions.x -50 -title.width, 50, mainScreen.renderer );
                //smallExample.render(50,75,mainScreen.renderer);

                // Render menu
                testMenu.render();

                // Update the screen
                mainScreen.update();

			}

            // **** Main loop ended here

            stopSDL();

        }

    return 0;

}
