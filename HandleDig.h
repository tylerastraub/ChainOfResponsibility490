#ifndef HANDLEDIG_H
#define HANDLEDIG_H

#include "Material.h"

class HandleDig {
protected:
  HandleDig* nextHandle;
  Material mats;
public:
  HandleDig();
  void setNext(HandleDig* n = nullptr);
  void addHandler();
 virtual int handle(Material m) = 0;
 virtual char getDisplayChar() = 0;
};

#endif



