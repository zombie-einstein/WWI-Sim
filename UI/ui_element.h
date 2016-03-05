#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include "screen.h"
#include "vec.h"

class UI_element
{
    public:
        // Declare, then add elements to UI
        // then render to a location
        UI_element();

        ~UI_element();

        // Padding for elements inside UI element
        static vec<int> padding;

        // So menu's have coherent look
        static int UIBackGroundColor[4];

        // Pointer to the screen that the elemet will render to
        screen* renderScreen = NULL;
        // Location (top left corner) of element
        vec<int> location;
        // Dimsensions of element
        vec<int> dimensions;

        // Methods for setting these values
        void setLocation( vec<int> x );

        void setDimensions( vec<int> d );

        // Render the background UI box
        void renderBox( int x, int y );

    protected:
    private:
};

#endif // UI_ELEMENT_H
