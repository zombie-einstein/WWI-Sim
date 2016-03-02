#include "vec.h"
#include "hexvec.h"

vec::vec(){
    x = 0;
    y = 0;
}

vec::vec( int X, int Y){

    x = X;
    y = Y;

}

vec::~vec()
{
    //dtor
}

hexVec vec::convertToHex(){

    hexVec tempHexVec( x, 0.5*(y + y%2), 0.5*(y - y%2) );
    return tempHexVec;

}

vec vec::operator+( vec& object ){

    vec temp;

    temp.x = x +object.x;
    temp.y = y +object.y;

    return temp;
}

vec vec::operator-( vec& object ){

    vec temp;

    temp.x = x -object.x;
    temp.y = y -object.y;

    return temp;
}

vec vec::operator*( int a){

    vec temp;

    temp.x  = a *x;
    temp.y  = a *y;

    return temp;
}

bool vec::operator>( vec& object ){

    return ( x > object.x && y > object.y );

}

bool vec::operator<( vec& object ){

    return ( x < object.x && y < object.y );

}
