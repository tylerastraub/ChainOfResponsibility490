#include "dirtHandler.h"

int DirtHandler::handle(Material m){
    mats = m;
    if(mats == WOOD){
        return 1;
    }
    else{
       return nextHandle->handle(mats);
    }
}

char DirtHandler::getDisplayChar(){
    return 'd';
}
