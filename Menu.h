//
// Created by Nicolas Cuenca on 5/5/2021.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H
#include "Item.h"
#include "DropdownMenu.h"
#include "GUI_components.h"
#include "MenuBar.h"

//This class should reuse the Item and ItemList class from the previous assignment.
//the Item object is clicked, it should toggle the ItemList object.
class Menu{
private:
    std::vector<std::vector<std::string>> allItems;
    std::vector<DropdownMenu*> dropdownMenus;
    int starting_x;
    int starting_y;
    int length;
    int width;
    std::vector<std::string> inputboxNames;
    MenuBar *menuBar;

public:
    Menu(std::vector<std::vector<std::string>> allItems, int starting_x, int starting_y, int length, int width, std::vector<std::string> inputboxNames);
    MenuBar *getMenuBar() const;

};


#endif //PROJECT_MENU_H
