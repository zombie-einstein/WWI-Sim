// Container for variables used to convert a hex grid to pixels and vice versa
// Values depend on chosen width of hexsprite (no associated .cpp file)

#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#define PI 3.14159265
#include <math.h>
#include <vec.h>

class variables{

    public:

    // Constructor creates variables dependent on sprite width
    variables( vec<int> ORIGIN,  int clipWidth ){

        origin      = ORIGIN;
        isoScaling  = clipWidth / ( (sqrtThree+1)*cosThirty );
        toSprite    = vec<int>( 0.5*isoScaling*cosThirty, -1.5*isoScaling*sinThirty );
        e           = vec<int>( sqrtThree*isoScaling*cosThirty, sqrtThree*isoScaling*sinThirty );
        ne          = vec<int>( 0.5*(3+sqrtThree)*isoScaling*cosThirty, -0.5*(3-sqrtThree)*isoScaling*sinThirty );
        nw          = vec<int>( 0.5*(3-sqrtThree)*isoScaling*cosThirty, -0.5*(3+sqrtThree)*isoScaling*sinThirty );

    }

    // Thirty degrees in radians (used for isometric)
    double thirtyDegree = 30*PI/180;
    // Square root of 3 scaling factor
    double sqrtThree    = sqrt(3);
    // Store Cos and Sin of thirty degrees
    double cosThirty    = cos(thirtyDegree);
    double sinThirty    = sin(thirtyDegree);
    // Scaling factor between iso hex sprites and unit carteisan hex
    double isoScaling;

    // Integer vectors for:
    // - Origin of hex grid on screen
    // - Vector from origin to top left corner of iso hex sprite
    // - Vectors on screen that translate in hex directions
    vec<int> origin, toSprite, e, ne, nw;

};

#endif // VARIABLES_H_INCLUDED
