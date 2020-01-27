#ifndef STONEHANDLER_H
#define STONEHANDLER_H

#include "HandleDig.h"

class StoneHandler : public HandleDig {
public:
    int handle(Material m);
    char getDisplayChar();
};

#endif



