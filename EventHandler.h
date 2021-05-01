//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_EVENTHANDLER_H
#define PROJECT_EVENTHANDLER_H
#include <SFML/Graphics.hpp>

class EventHandler {
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //PROJECT_EVENTHANDLER_H
