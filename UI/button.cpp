#include "button.h"

button::button(){}

//button::button( const button& other ){



//}

button::button( std::string t, screen* r ){

    renderScreen = r;

    loadText( t );

}

button::~button(){
    //dtor
}

void button::loadText( std::string t ){

    text.loadFromRenderedText( t, {0,0,0}, renderScreen->renderer, renderScreen->screenFontSmall );
    // Vector to contain the text dimensions
    vec textDimensions;
    SDL_QueryTexture( text.texture, NULL, NULL, &textDimensions.x, &textDimensions.y );
    // Set button dimensions at text dimensions plus padding
    textDimensions = textDimensions + padding;
    setDimensions( textDimensions );

}

void button::render( int x, int y ){

    renderBox( x, y );
    // Render appropriate text inside button box
    text.render( x+padding.x/2, y+padding.y/2, renderScreen->renderer );

}
