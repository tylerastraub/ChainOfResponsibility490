#include "diamondHandler.h"

int DiamondHandler::handle(Material m){
    mats = m;
    if(mats == DIAMOND){
        return 3;
    }
}

char DiamondHandler::getDisplayChar(){
    return 'D';
}