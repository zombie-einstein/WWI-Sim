#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED

#include<math.h>
#include "vec.h"
#include "variables.h"
#include <iostream>

void mouseScrolling( vec screenSize, vec mousePos, vec &origin, int scrollRate );

vec convertMouseToHex( vec mousePos, vec offsets, variables* v );

#endif // MOUSE_H_INCLUDED
