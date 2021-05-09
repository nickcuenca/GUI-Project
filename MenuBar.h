//
// Created by Nicolas Cuenca on 5/5/2021.
//

#ifndef PROJECT_MENUBAR_H
#define PROJECT_MENUBAR_H
#include "SFML/Graphics.hpp"
#include "DropdownMenu.h"
#include "MenuHistory.h"
//This class will hold a number of Item lists and align them horizontally.
class MenuBar : public GUI_components {
private:
    std::vector<DropdownMenu*> dropdownMenus;
    MenuHistory *menuHistory1;
public:
    MenuBar(std::vector<DropdownMenu*> dropdownMenus);
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void update();

};


#endif //PROJECT_MENUBAR_H
