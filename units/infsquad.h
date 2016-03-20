// Infantry Squad. lowest level of unit organisation
// Inherets unit class

#ifndef INFSQUAD_H
#define INFSQUAD_H

// Inheritance
#include "unit.h"

// Dependencies
#include "hexspritelist.h"

class infSquad: public unit{

    public:

        infSquad();

        infSquad( vec<int> x, int type );

        infSquad( hexVec x, int type);

        int infType;

        void render( hexSpriteList* infSprites );

    protected:
    private:

};

#endif // INFSQUAD_H
