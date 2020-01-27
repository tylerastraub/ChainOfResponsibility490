#ifndef DIAMONDHANDLER_H
#define DIAMONDHANDLER_H

#include "HandleDig.h"

class DiamondHandler : public HandleDig {
public:
    int handle(Material m); 
    char getDisplayChar();
};

#endif



