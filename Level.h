#ifndef CHAINOFRESPONSIBLITY490_LEVEL_H
#define CHAINOFRESPONSIBLITY490_LEVEL_H

#include "HandleDig.h"
#include "Digger.h"
#include <vector>
#include <iostream>

class Level {
public:
    Level() = default;
    Level(std::vector<HandleDig*> layers);
    ~Level();

    void setLayers(std::vector<HandleDig*> layers);
    void displayLevel();
private:
    int _layerDepth;
    int _levelWidth;
    std::vector<HandleDig*> _layers;
    Digger* digger;
};

#endif //CHAINOFRESPONSIBLITY490_LEVEL_H
