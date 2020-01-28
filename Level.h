#ifndef CHAINOFRESPONSIBLITY490_LEVEL_H
#define CHAINOFRESPONSIBLITY490_LEVEL_H

#include "HandleDig.h"
#include "Digger.h"
#include <vector>
#include <iostream>

class Level {
public:
    Level();
    Level(std::vector<HandleDig*> layers);
    ~Level();

    void setLayers(std::vector<HandleDig*> layers);
    void setDigger(Digger* digger);
    void setMessage(std::string message);
    int getLayerDepth();
    void displayLevel();
private:
    int _layerDepth;
    int _levelWidth;
    std::vector<HandleDig*> _layers;
    Digger* _digger;
    std::string _topMessage;
};

#endif //CHAINOFRESPONSIBLITY490_LEVEL_H
