#ifndef GRASSHANDLER_H
#define GRASSHANDLER_H

#include "HandleDig.h"
#include "Material.h"

class GrassHandler : public HandleDig {
public:
    int handle(Material m);
    char getDisplayChar();
};

#endif



