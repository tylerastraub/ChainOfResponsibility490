#include "Level.h"

Level::Level(std::vector<HandleDig*> layers) {
    _layers = layers;
    _layerDepth = 3;
    _levelWidth = 80;
}

Level::~Level() {
    for(auto it : _layers) {
        delete it;
    }

    delete digger;
}

void Level::setLayers(std::vector<HandleDig*> layers) {
    _layers = layers;
}

void Level::displayLevel() {
    std::cout << std::endl;
    if(digger->getYPos() == 0) {
        for(int i = 0; i < digger->getXPos(); ++i) {
            std::cout << " ";
        }
        std::cout << "*";
    }
    std::cout << std::endl;

    int y = 1;
    for(auto layer : _layers) {
        int x = 0;
        for(int i = 0; i < _layerDepth; ++i) {
            for(; x < _levelWidth; ++x) {
                if(x == digger->getXPos() &&
                   y <= digger->getYPos()) {
                    std::cout << " ";
                } else {
//                    std::cout << layer->getDisplayChar():
                }
                std::cout << std::endl;
            }
        }

        ++y;
    }
}

