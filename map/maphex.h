// Stores individual map hex properties
// Inherets hex co-ord properties from "hex.h"

#ifndef MAPHEX_H
#define MAPHEX_H

// Inheritance
#include "hex.h"

class mapHex : public hex{

    public:

        mapHex();

        // Sets both sets of co-ords from a grid vector
        mapHex( vec<int> );

        // Sets both sets co-ords from a hex vector
        mapHex( hexVec );

        ~mapHex();

        // Elevation, terrain, attrition value of this hex
        int elevation, terrain, attrition;

        // Set the elevation value of the hex
        void setElevation( int x);

        // Set the terrain value of the hex
        void setTerrain( int x );

    protected:
    private:

};

#endif // MAPHEX_H
