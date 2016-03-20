// General unit class, inherets hex location properties

#ifndef UNIT_H
#define UNIT_H

// Inheritance
#include "hex.h"

class unit: public hex{

    public:

        unit();

        unit( vec<int> );

        unit( hexVec );

    protected:
    private:

};

#endif // UNIT_H
