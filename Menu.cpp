//
// Created by Nicolas Cuenca on 5/5/2021.
//

#include "Menu.h"
Menu::Menu(std::vector<std::vector<std::string>> allItems, int starting_x, int starting_y, int length, int width, std::vector<std::string> inputboxNames) {
    this->allItems = allItems;
    this->starting_x = starting_x;
    this->starting_x = starting_y;
    this->starting_x = length;
    this->starting_x = width;
    this->inputboxNames = inputboxNames;
    for (int i = 0; i < this->allItems.size(); i++){
        InputBox *inputBox = new InputBox(starting_x + i * width, starting_y, length, width, inputboxNames[i]);
        this->dropdownMenus.push_back(new DropdownMenu(inputBox, allItems[i]));
    }
    this->menuBar = new MenuBar(dropdownMenus);
}

MenuBar *Menu::getMenuBar() const {
    return menuBar;
}

