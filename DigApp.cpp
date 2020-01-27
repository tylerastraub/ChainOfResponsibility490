#include "DigApp.h"

#include "grassHandler.h"
#include "dirtHandler.h"
#include "stoneHandler.h"
#include "diamondHandler.h"
#include <iostream>
#include <chrono>

DigApp::DigApp() {
    level = new Level();
}

DigApp::~DigApp() {
    exit();
}

void DigApp::createMenu() {
    std::vector<std::string> menuItems = {
            "Dig with cardboard shovel",
            "Dig with wood shovel",
            "Dig with steel shovel",
            "Quit"
    };
    _mainMenu = new Menu(menuItems);
}

void DigApp::displayMenu() {
    _mainMenu->display();
}

void DigApp::handleMainMenuInput(int input) {
    switch(input) {
        case 1:
            _currentMaterial = CARDBOARD;
            break;
        case 2:
            _currentMaterial = WOOD;
            break;
        case 3:
            _currentMaterial = STEEL;
            break;
        default:
            _exitFlag = true;
            break;
    }
}

std::vector<HandleDig *> DigApp::createLayers() {
    HandleDig* diamond = new diamondHandler();
    HandleDig* stone = new stoneHandler();
    HandleDig* dirt = new dirtHandler();
    HandleDig* grass = new grassHandler();

    stone->setNext(diamond);
    dirt->setNext(stone);
    grass->setNext(dirt);
    // order is from top to bottom in terms of displaying
    std::vector<HandleDig*> layers = {
        grass,
        dirt,
        stone,
        diamond
    };

    return layers;
}

void DigApp::run() {
    createMenu();
    displayMenu();
    handleMainMenuInput(_mainMenu->getInput());

    if(_exitFlag) {
        exit();
        return;
    }

    std::vector<HandleDig*> layers = createLayers();
    level->setLayers(layers);
//    auto startTime = std::chrono::system_clock::now();
//    int x = 0;
//    while(x < 10){
//        auto currentTime = std::chrono::system_clock::now();
//        auto timeElapsed = currentTime - startTime;
//        // executes once every second
//        if(timeElapsed.count() >= 1000000){
//            startTime = currentTime;
//            ++x;
//            std::cout << x << std::endl;
//        }
//    }
}

void DigApp::exit() {
    delete _mainMenu;
}