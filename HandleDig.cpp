#include "HandleDig.h"

HandleDig::HandleDig(){
    nextHandle = 0;
}

void HandleDig::setNext(HandleDig* h){
    nextHandle = h;
}

void HandleDig::addHandler(){

}



int HandleDig::handle(Material m){
    nextHandle->handle(m);
}

