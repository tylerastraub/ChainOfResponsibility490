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
            "Dig with cardboard",
            "Dig with wood shovel",
            "Dig with steel pickaxe",
            "Dig with diamond pickaxe",
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
        case 4:
            _currentMaterial = DIAMOND;
            break;
        default:
            _exitFlag = true;
            break;
    }
}

std::vector<HandleDig *> DigApp::createLayers() {
    HandleDig* diamond = new DiamondHandler();
    HandleDig* stone = new StoneHandler();
    HandleDig* dirt = new DirtHandler();
    HandleDig* grass = new GrassHandler();

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
    Digger* digger = new Digger(0, 0);

    createMenu();
    displayMenu();
    handleMainMenuInput(_mainMenu->getInput());

    if(_exitFlag) {
        exit();
        return;
    }

    std::vector<HandleDig*> layers = createLayers();
    digger->setMaxDigDepth(layers[0]->handle(_currentMaterial) *
                           level->getLayerDepth());
    level->setLayers(layers);
    level->setDigger(digger);
    level->displayLevel();

    // move digger to center
    auto startTime = std::chrono::system_clock::now();
    int counter = 0;
    while(counter < 40){
        auto currentTime = std::chrono::system_clock::now();
        auto timeElapsed = currentTime - startTime;
        // 1 second = 1,000,000 count
        if(timeElapsed.count() >= 150000){
            startTime = std::chrono::system_clock::now();
            digger->move(1, 0);
            level->displayLevel();
            ++counter;
        }
    }

    // display message for 4 seconds
    level->setMessage("time to dig!");
    level->displayLevel();
    counter = 0;
    startTime = std::chrono::system_clock::now();
    while(counter < 1) {
        auto currentTime = std::chrono::system_clock::now();
        auto timeElapsed = currentTime - startTime;
        // 1 second = 1,000,000 count
        if(timeElapsed.count() >= 4000000){
            ++counter;
        }
    }

    // dig!
    level->setMessage("");
    level->displayLevel();
    startTime = std::chrono::system_clock::now();
    while(digger->getYPos() < digger->getMaxDigDepth()) {
        auto currentTime = std::chrono::system_clock::now();
        auto timeElapsed = currentTime - startTime;
        // 1 second = 1,000,000 count
        if(timeElapsed.count() >= 500000){
            startTime = std::chrono::system_clock::now();
            digger->move(0, 1);
            level->displayLevel();
        }
    }

    // let user know of digger's defeat
    level->setMessage("darn, my shovel can't dig past this material!");
    level->displayLevel();
    counter = 0;
    startTime = std::chrono::system_clock::now();
    while(counter < 1) {
        auto currentTime = std::chrono::system_clock::now();
        auto timeElapsed = currentTime - startTime;
        // 1 second = 1,000,000 count
        if(timeElapsed.count() >= 4000000){
            ++counter;
        }
    }

    // loop again - user may quit from menu at any time
    std::cout << std::endl;
    level->setMessage("");
    run();
}

void DigApp::exit() {
    delete _mainMenu;
}