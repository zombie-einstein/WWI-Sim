#ifndef BUTTON_H
#define BUTTON_H

// Libraries
#include <SDL2/SDL.h>
#include <string>
#include <functional>
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

        // Texture with button text
        textSprite text;

        // Declare pointer to action of button
        //void (*click)();
        std::function<void()> click;

        // Load an appropriatte text texture and resize the button
        void loadText( std::string t );

        // Render button ( at location )
        void render();

        // Render button as an SDL primative with text
        void render( vec<int> a );

        // Checks wether a mouse click is over button and acts appropriately
        bool mouseClick( vec<int> mousPos );

    protected:
    private:
};

#endif // BUTTON_H
