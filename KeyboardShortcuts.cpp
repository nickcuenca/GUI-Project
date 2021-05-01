//
// Created by Nicolas Cuenca on 4/5/2021.
//

#include "KeyboardShortcuts.h"
#include "SFML/Graphics.hpp"
bool KeyboardShortcuts::isUndo(sf::RenderWindow &window, sf::Event event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
        return true;
    return false;
}
