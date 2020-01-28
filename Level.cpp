#include "Level.h"

#include <utility>

Level::Level() {
    _layerDepth = 3;
    _levelWidth = 80;
    _digger = nullptr;
}

Level::Level(std::vector<HandleDig*> layers) {
    _layers = std::move(layers);
    _layerDepth = 3;
    _levelWidth = 80;
}

Level::~Level() {
    for(auto it : _layers) {
        delete it;
    }

    delete _digger;
}

void Level::setLayers(std::vector<HandleDig*> layers) {
    _layers = std::move(layers);
}

void Level::setDigger(Digger* digger) {
    _digger = digger;
}

void Level::setMessage(std::string message) {
    _topMessage = message;
}

int Level::getLayerDepth() {
    return _layerDepth;
}

void Level::displayLevel() {
    // give some space at top
    for(int i = 0; i < 20; ++i) {
        std::cout << std::endl;
    }
    std::cout << _topMessage << std::endl;

    if(_digger->getYPos() == 0) {
        for(int i = 0; i < _digger->getXPos(); ++i) {
            std::cout << " ";
        }
        // character for digger
        std::cout << "&";
    }
    std::cout << std::endl;

    int y = 1;
    for(auto layer : _layers) {
        for(int i = 0; i < _layerDepth; ++i) {
            for(int x = 0; x < _levelWidth; ++x) {
                if(x == _digger->getXPos() &&
                   y <= _digger->getYPos()) {
                    if(y == _digger->getYPos()) {
                        std::cout << "&";
                    } else {
                        std::cout << " ";
                    }
                } else {
                    std::cout << layer->getDisplayChar();
                }
            }
            std::cout << std::endl;
            ++y;
        }
    }
}

