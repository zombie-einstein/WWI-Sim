#include "menu.h"
#include  <iostream>
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

menu::~menu(){
    // Free title texture
    title.free();
    // Free all text textures associated with buttons
    for( std::vector<button>::iterator it = buttonList.begin() ; it != buttonList.end(); ++it ) {
        // Make all buttons same width
        it->text.free();

    }
}

void menu::addButton( std::string t ){

    button newButton( t, renderScreen);
    // Set button location relative to corner of menu
    newButton.setLocation( vec( padding.x/2, dimensions.y ) );

    // Push button to vector
    buttonList.push_back( newButton );

    dimensions.y += newButton.dimensions.y + padding.y/2;
    // If new button is wider than current menu then resize
    if( (newButton.dimensions.x + padding.x) > dimensions.x ){

        dimensions.x = newButton.dimensions.x + padding.x;

    }
}

void menu::render( int x, int y ){
    // Render containing menu box
    renderBox( x, y );
    // Render title at top of box
    title.render( x+padding.x/2, y+padding.y/2, renderScreen->renderer);
    // Render all button elements in vector
    for( std::vector<button>::iterator it = buttonList.begin() ; it != buttonList.end(); ++it ) {
        // Make all buttons same width
        it->dimensions.x = dimensions.x-padding.x;
        // Draw button and text
        it->render( x+it->location.x, y+it->location.y );

    }
}
