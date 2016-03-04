#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

#define PI 3.14159265
#include <math.h>

class variables{

    public:

    variables( int clipWidth ){ isoScaling = clipWidth / ( (sqrtThree+1)*cosThirty ); }

    double thirtyDegree = 30*PI/180;
    double sqrtThree    = sqrt(3);
    double cosThirty    = cos(thirtyDegree);
    double sinThirty    = sin(thirtyDegree);
    double isoScaling;

};

#endif // VARIABLES_H_INCLUDED
