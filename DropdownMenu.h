//
// Created by Nicolas Cuenca on 4/29/2021.
//

#ifndef PROJECT_DROPDOWNMENU_H
#define PROJECT_DROPDOWNMENU_H
#include "GUI_components.h"
#include "Item.h"
#include "ItemList.h"
#include "InputBox.h"
#include "MouseEvents.h"
#include "MenuHistory.h"



//This is the class that brings the Item, ItemList and InputBox together. This class must also be a child of GUIComponent
class DropdownMenu : public GUI_components {
private:
    InputBox* inputBox;
    std::vector<std::string> names;

    ItemList *itemList;
    bool dropdownVisible;
    MenuHistory* menuHistory_;
    bool file_menu;
public:
    DropdownMenu(InputBox *inputBox, std::vector<std::string> names, bool file_menu = false);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
};


#endif //PROJECT_DROPDOWNMENU_H
