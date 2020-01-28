#include "diamondHandler.h"

int DiamondHandler::handle(Material m){
    // this is always the base layer and thus should be the broadest member of
    // the chain
    return 3;
}

char DiamondHandler::getDisplayChar(){
    return 'D';
}