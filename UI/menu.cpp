#include "menu.h"

menu::menu( std::string t, screen* r ){

    renderScreen = r;

    title.loadFromRenderedText( t, {0,0,0}, renderScreen->renderer, renderScreen->screenFontSmall );
    // Vector to contain the text dimensions
    vec titleDimensions;

    SDL_QueryTexture( title.texture, NULL, NULL, &titleDimensions.x, &titleDimensions.y );
    // Set button dimensions at text dimensions plus padding
    titleDimensions = titleDimensions + padding;

    setDimensions( titleDimensions );

}

menu::~menu()
{
    //dtor
}

void menu::addButton( std::string t ){

    button newButton;
    // Set button location relative to corner of menu
    newButton.setLocation( vec( padding.x/2, dimensions.y ) );
    // Push button to vector
    buttonList.push_back( newButton );

    //buttonList = newButton;
    buttonList.back().renderScreen = renderScreen;
    // Load text NOTE: This is kind of cluncky, push_back could be used but buttons
    // then need a better copy constructor to properly copy the font texture
    buttonList.back().loadText( t );
    // Expand menu to accomodate new button
    dimensions.y += buttonList.back().dimensions.y + padding.y/2;
    // If new button is wider than current menu then resize
    if( (buttonList.back().dimensions.x + padding.x) > dimensions.x ){

        dimensions.x = buttonList.back().dimensions.x + padding.x;

    }
}

void menu::render( int x, int y ){
    // Render containing menu box
    renderBox( x, y );
    // Render title at top of box
    title.render( x+padding.x/2, y+padding.y/2, renderScreen->renderer);
    // Render all button elements
    //for( auto &i : buttonList ) {

        //buttonList[0].render( x+buttonList[0].location.x, y+buttonList[0].location.y );
        //buttonList[1].render( x+buttonList[1].location.x, y+buttonList[1].location.y );
    //}
}
