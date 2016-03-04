#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <functional>
#include <math.h>
#include "map.h"
#include "screen.h"
#include "hexspritelist.h"
#include "keyboard.h"
#include "textsprite.h"
#include "vert_menu.h"
#include "mouse.h"

#define PI 3.14159265

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

            // Vector of hex direction offsets
            // for this given hex size

            double thirtyDegree = 30*PI/180;

            double isometricScaling = hexclip::clipWidth / ( (sqrt(3)+1)*cos(thirtyDegree) );

            vec offsets[5];

            // Location of origin
            offsets[0] = vec( 0 , 200);
            // Offset from origin to top corner of sprite
            offsets[1] = vec( 0.5*isometricScaling*cos(thirtyDegree), -1.5*isometricScaling*sin(thirtyDegree) );
            // Translate one cell east
            offsets[2] = vec( sqrt(3)*isometricScaling*cos(thirtyDegree), sqrt(3)*isometricScaling*sin(thirtyDegree) );
            // Translate one cell north-east
            offsets[3] = vec( 0.5*(3+sqrt(3))*isometricScaling*cos(thirtyDegree), -0.5*(3-sqrt(3))*isometricScaling*sin(thirtyDegree) );
            // Translate one cell north-west
            offsets[4] = vec( 0.5*(3-sqrt(3))*isometricScaling*cos(thirtyDegree), -0.5*(3+sqrt(3))*isometricScaling*sin(thirtyDegree) );

            // Make text sprite (white)
            textSprite title;
            title.loadFromRenderedText("WWI SIM v0.1", { 255, 255, 255 }, mainScreen.renderer, mainScreen.screenFontLarge );

            textSprite smallExample;
            smallExample.loadFromRenderedText("small text example", { 255, 255, 255 }, mainScreen.renderer, mainScreen.screenFontSmall );

            button testButton( "A test button", &mainScreen );

            vert_menu testMenu( "Test Menu", &mainScreen );
            testMenu.addButton("Move Menu to corner");
            testMenu.addButton("Move Menu back");
            testMenu.setLocation( vec(50,150));

            // Use bind to attach function definitions to class members
            testMenu.buttonList[0].click = std::bind( &vert_menu::setLocation, &testMenu, vec(10,10) );
            testMenu.buttonList[1].click = std::bind( &vert_menu::setLocation, &testMenu, vec(50,150) );

            //Main loop flag
			bool quit = false;

            //Event handler
			SDL_Event event;

            // Store mouse position
            vec mousePos(0,0);

            // Test map
            map testMap(12,8, &terrain);

            testMap.loadFromFile("data/testmap.txt");

            // **** Main application loop starts here ****

			//While application is running
			while( !quit ){

                // Continually update mouse position vector
                SDL_GetMouseState( &mousePos.x, &mousePos.y );

                // Check for mouse scrolling
                mouseScrolling( mainScreen.dimensions, mousePos, offsets[0], 1 );

				//Handle events on queue
				while( SDL_PollEvent( &event ) != 0 ){
					//User requests quit
					if( event.type == SDL_QUIT || event.type == SDLK_ESCAPE ){
						quit = true;
					}
					if( event.type == SDL_KEYDOWN){

                        mapControl(event, offsets[0], 10);

                        switch( event.key.keysym.sym ){

                        // Exit main window
                        case SDLK_ESCAPE:   quit = true; break;

                        // Go to fullscreen (and change screen variables)
                        case SDLK_F1:       SDL_SetWindowFullscreen(mainScreen.window, SDL_WINDOW_FULLSCREEN);
                                            SDL_GetWindowSize( mainScreen.window, &mainScreen.dimensions.x, &mainScreen.dimensions.y );
                                            break;

                        }
					}
					if ( event.type == SDL_MOUSEBUTTONDOWN ){

                        testMenu.mouseCheck( mousePos );
                        mousePos = vec ( mousePos.x - offsets[0].x, offsets[0].y - mousePos.y );

                        double newMousePosX = mousePos.x/isometricScaling;
                        double newMousePosY = mousePos.y/isometricScaling;

                        newMousePosX = 0.5*( newMousePosX/cos(thirtyDegree) - newMousePosY/sin(thirtyDegree) );
                        newMousePosY = 0.5*( newMousePosX/cos(thirtyDegree) + newMousePosY/sin(thirtyDegree) );

                        double findEastX = -newMousePosX/sqrt(3)+newMousePosY-0.5;
                        double findEastY = 2*newMousePosX/sqrt(3);

                        double findNWestX = newMousePosX/sqrt(3)+newMousePosY-0.5;
                        double findNWestY = newMousePosX/sqrt(3)-newMousePosY+0.5;

                        vec mouseGridVec;

                        mouseGridVec.x = floor( ( floor(findEastY)-floor(findEastX) )/3 );
                        mouseGridVec.y = floor( ( floor(findNWestX)-floor(findNWestY) )/3 );

                        std::cout << "(" << floor(findEastX) << "," << floor(findEastY) << ")";
                        std::cout << "(" << floor(findNWestX) << "," << floor(findNWestY) << ")";
                        std::cout << "(" << mouseGridVec.x << "," << mouseGridVec.y << ")\n";

					}
				}

                // Clean, render sprite and update
                mainScreen.clean();

                testMap.render(offsets);

                title.render(50,50,mainScreen.renderer);
                smallExample.render(50,75,mainScreen.renderer);

                testMenu.render();

                mainScreen.update();

			}

            // **** Main loop ended here

            stopSDL();

        }


    return 0;
}
