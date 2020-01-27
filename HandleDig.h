#ifndef HANDLEDIG_H
#define HANDLEDIG_H

class HandleDig {
protected:
  HandleDig* nextHandle;
public:
  HandleDig();
  void setNext(HandleDig* n = nullptr;);
  void addHandler();
 virtual void handle(); //tbd what goes in here
};

#endif



