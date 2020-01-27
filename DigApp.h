#ifndef CHAINOFRESPONSIBLITY490_DIGAPP_H
#define CHAINOFRESPONSIBLITY490_DIGAPP_H

#include "Menu.h"

#include "HandleDig.h"
#include "Material.h"
#include "Level.h"
#include <vector>

class DigApp {
public:
    DigApp();
    ~DigApp();

    void createMenu();
    void displayMenu();
    void handleMainMenuInput(int input);
    std::vector<HandleDig*> createLayers();
    void run();
    void exit();
private:
    Menu* _mainMenu;
    Level* level;
    bool _exitFlag = false;
    Material _currentMaterial;
};

#endif //CHAINOFRESPONSIBLITY490_DIGAPP_H
