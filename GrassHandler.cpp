#include "grassHandler.h"


int GrassHandler::handle(Material m){
    mats = m;
    if(mats == CARDBOARD){
        return 0;
    }
    else{
       return nextHandle->handle(mats);
    }
}

char GrassHandler::getDisplayChar(){
    return 'G';
}