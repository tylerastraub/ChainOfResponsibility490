#ifndef CHAINOFRESPONSIBLITY490_MENU_H
#define CHAINOFRESPONSIBLITY490_MENU_H

#include <iostream>
#include <vector>

class Menu {
public:
    Menu(std::vector<std::string> menuItems);
    ~Menu() = default;

    void display();
    int getInput();
private:
    std::vector<std::string> _menuItems;
};

#endif //CHAINOFRESPONSIBLITY490_MENU_H
