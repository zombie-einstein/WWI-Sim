#include "ui_element.h"

UI_element::UI_element(){

}

UI_element::~UI_element()
{
    //dtor
}

void UI_element::setLocation( vec x ){

    location = x;

}

void UI_element::setDimensions( vec d ){

    dimensions = d;

}

void UI_element::renderBox( int x, int y ){

    // Draw filled rectangle with black border
    SDL_Rect buttonRectangle = { x, y, dimensions.x, dimensions.y };
    SDL_SetRenderDrawColor( renderScreen->renderer, UIBackGroundColor[0], UIBackGroundColor[1], UIBackGroundColor[2], UIBackGroundColor[3] );
    SDL_RenderFillRect( renderScreen->renderer, &buttonRectangle);
    SDL_SetRenderDrawColor( renderScreen->renderer, 0, 0, 0, 255 );
    SDL_RenderDrawRect( renderScreen->renderer, &buttonRectangle);

}
