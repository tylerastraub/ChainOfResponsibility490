#include "DigApp.h"
#include "Material.h"

#include <iostream>
#include <chrono>

void DigApp::createMenu() {
    std::vector<std::string> menuItems = {
            "Dig with cardboard shovel",
            "Dig with wood shovel",
            "Dig with steel shovel",
            "Quit"
    };
    _menu = new Menu(menuItems);
}

void DigApp::displayMenu() {
    _menu->display();
}

void DigApp::run() {
    createMenu();
    displayMenu();

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