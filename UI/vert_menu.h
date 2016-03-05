#ifndef MENU_H
#define MENU_H

#include <vector>
#include "button.h"

class vert_menu:public UI_element{

    public:

        vert_menu( std::string t, screen* r );

        ~vert_menu();

        // Vector of buttons in menu
        std::vector< button > buttonList ;

        // Title texture
        textSprite title;

        // Push a button to the buttonList vector
        // and set the size of the menu based on widest button or title
        void addButton( std::string t );

        // Render at location
        void render();

        // Render the menu including buttons ( & set location )
        void render( vec<int> x );

        // Check button list for mouseclicks
        bool mouseCheck( vec<int> mousePos );

    protected:
    private:

};

#endif // MENU_H
