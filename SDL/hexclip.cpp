#include "hexclip.h"

hexclip::hexclip(){

}

hexclip::hexclip( int x, int y ){

    // Constructor sets clip box
    setClipBox( x, y );

}

hexclip::~hexclip()
{
    // Destructor ( Clear clip box?)
}

void hexclip::setClipBox( int x, int y ){
    // Construct with clip box
    clipBox.x  = x *clipWidth;
    clipBox.y  = y *clipHeight;
    clipBox.w  = clipWidth;
    clipBox.h  = clipHeight;

}
