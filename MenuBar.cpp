//
// Created by Nicolas Cuenca on 5/5/2021.
//

#include "MenuBar.h"
#include "MouseEvents.h"
MenuBar::MenuBar(std::vector<DropdownMenu *> dropdownMenus) {
    this->dropdownMenus = dropdownMenus;
    this->menuHistory1 = new MenuHistory();

}
void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for (int i = 0; i < dropdownMenus.size() ;i++) {
        dropdownMenus[i]->addEventHandler(window, event);
    }
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < dropdownMenus.size() ; i++) {
        window.draw(*dropdownMenus[i]);
    }

    _sleep(100);
}

void MenuBar::update() {

}

