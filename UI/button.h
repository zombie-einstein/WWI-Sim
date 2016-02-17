#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <string>
// Inheritance
#include "ui_element.h"
// Dependencies
#include "textsprite.h"

class button: public UI_element{

    public:

        button();

        // Initialize button with contained text and screen to be rendered to
        // Method then loads SDL textsprite from font file
        button( std::string t, screen* r );

        ~button();

        textSprite text;

        // Load an appropriatte text texture and resize the button
        void loadText( std::string t );
        // Render button as an SDL primative with text
        void render( int x, int y );

    protected:
    private:
};

#endif // BUTTON_H
