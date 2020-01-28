#include "Menu.h"

#include <utility>
#include "Material.h"

Menu::Menu(std::vector<std::string> menuItems) {
    _menuItems = std::move(menuItems);
}

void Menu::display() {
    for(int i = 0; i < _menuItems.size(); ++i) {
        std::cout << i + 1 << ": " << _menuItems[i] << std::endl;
    }
}

int Menu::getInput() {
    int userInput;
    std::cin >> userInput;
    return userInput;
}