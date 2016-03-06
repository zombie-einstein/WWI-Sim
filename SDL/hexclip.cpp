#include "hexclip.h"

hexclip::hexclip(){

}

hexclip::hexclip( int n, int m ){

    // Constructor sets clip box
    setClipBox( n, m );

}

void hexclip::setClipBox( int n, int m ){
    // Construct with clip box
    clipBox.x  = n *clipWidth;
    clipBox.y  = m *clipHeight;
    clipBox.w  = clipWidth;
    clipBox.h  = clipHeight;

}
