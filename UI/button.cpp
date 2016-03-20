#include "button.h"

button::button(){}

button::button( std::string t, screen* r ){

    renderScreen = r;

    loadText( t );

}

button::~button(){

}

void button::loadText( std::string t ){

    text.loadFromRenderedText( t, {0,0,0}, renderScreen->renderer, renderScreen->screenFontSmall );
    // Vector contains the text dimensions
    vec<int> textDimensions;
    SDL_QueryTexture( text.texture, NULL, NULL, &textDimensions.x, &textDimensions.y );
    // Set button dimensions at text dimensions plus padding
    textDimensions = textDimensions + padding;
    setDimensions( textDimensions );

}

void button::render(){

    renderBox( location.x, location.y );
    // Render appropriate text inside button box
    text.render( location.x+padding.x/2, location.y+padding.y/2, renderScreen->renderer );

}

void button::render( vec<int> a ){

     renderBox( a.x, a.y );
    // Render appropriate text inside button box
    text.render( a.x+padding.x/2, a.y+padding.y/2, renderScreen->renderer );

}

bool button::mouseClick( vec<int> mousePos ){

    vec<int> boundary = location+dimensions;

    if ( mousePos > location && mousePos < boundary ){

        click();
        return true;

    }
    else { return false; }
}

