#ifndef MENU_H
#define MENU_H

#include <vector>
#include "button.h"

class menu:public UI_element{

    public:

        menu( std::string t, screen* r );

        ~menu();

        // Vector of buttons in menu
        std::vector< button > buttonList = std::vector<button>();
        //button buttonList;
        // Title texture
        textSprite title;

        // Push a button to the buttonList vector
        // and set the size of the menu based on widest button or title
        void addButton( std::string t );

        // Render the menu including buttons
        void render( int x, int y);

    protected:
    private:

};

#endif // MENU_H
