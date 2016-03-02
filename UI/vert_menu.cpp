#include "vert_menu.h"
#include  <iostream>
vert_menu::vert_menu( std::string t, screen* r ){

    renderScreen = r;

    title.loadFromRenderedText( t, {0,0,0}, renderScreen->renderer, renderScreen->screenFontSmall );
    // Vector to contain the text dimensions
    vec titleDimensions;

    SDL_QueryTexture( title.texture, NULL, NULL, &titleDimensions.x, &titleDimensions.y );
    // Set button dimensions at text dimensions plus padding
    titleDimensions = titleDimensions + padding;

    setDimensions( titleDimensions );

}

vert_menu::~vert_menu(){
    // Free title texture
    title.free();
    // Free all text textures associated with buttons
    for( std::vector<button>::iterator it = buttonList.begin() ; it != buttonList.end(); ++it ) {
        // Make all buttons same width
        it->text.free();

    }
}

void vert_menu::addButton( std::string t ){

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

void vert_menu::render(){

    // Render containing menu box
    renderBox( location.x, location.y );
    // Render title at top of box
    title.render( location.x+padding.x/2, location.y+padding.y/2, renderScreen->renderer);
    // Render all button elements in vector
    for( std::vector<button>::iterator it = buttonList.begin() ; it != buttonList.end(); ++it ) {
        // Make all buttons same width
        it->dimensions.x = dimensions.x-padding.x;
        // Draw button and text
        it->render( vec( location.x+it->location.x, location.y+it->location.y ) );

    }
}

void vert_menu::render( vec a ){

    // Render containing menu box
    renderBox( a.x, a.y );
    // Render title at top of box
    title.render( a.x+padding.x/2, a.y+padding.y/2, renderScreen->renderer);
    // Render all button elements in vector
    for( std::vector<button>::iterator it = buttonList.begin() ; it != buttonList.end(); ++it ) {
        // Make all buttons same width
        it->dimensions.x = dimensions.x-padding.x;
        // Draw button and text
        it->render( vec( a.x+it->location.x, a.y+it->location.y ) );
    }
}

bool vert_menu::mouseCheck( vec mousePos ){

    vec boundary = location + dimensions;

    if (  mousePos > location && mousePos < boundary ){

        for( std::vector<button>::iterator it = buttonList.begin() ; it != buttonList.end(); ++it ){
            if( it->mouseClick( mousePos - location ) ){ std::cout << "Button Clicked \n"; return true; }
        }

    }
    return false;
}
