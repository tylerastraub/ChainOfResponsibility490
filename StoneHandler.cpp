#include "stoneHandler.h"

int StoneHandler::handle(Material m){
    mats = m;
    if(mats == STEEL){
        return 2;
    }
    else{
        return nextHandle->handle(mats);
    }
}

char StoneHandler::getDisplayChar(){
    return 'S';
}
