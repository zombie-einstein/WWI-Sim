#ifndef UNIT_H
#define UNIT_H

#include "hex.h"

class unit: public hex{

    public:

        unit();

        unit( vec<int> );

        unit( hexVec );

        ~unit();

    protected:
    private:
};

#endif // UNIT_H
