#ifndef CHAINOFRESPONSIBLITY490_DIGAPP_H
#define CHAINOFRESPONSIBLITY490_DIGAPP_H

#include "Menu.h"

class DigApp {
public:
    DigApp() = default;
    ~DigApp() = default;

    void createMenu();
    void displayMenu();
    void run();
private:
    Menu* _menu;
};

#endif //CHAINOFRESPONSIBLITY490_DIGAPP_H
