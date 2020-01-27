#ifndef DIRTHANDLER_H
#define DIRTHANDLER_H

#include "HandleDig.h"

class DirtHandler : public HandleDig {
public:
    int handle(Material m); //tbd what goes in here
    char getDisplayChar();
};

#endif



