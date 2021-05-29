//
// Created by Nicolas Cuenca on 4/5/2021.
//
#ifndef PROJECT_MOUSEEVENTS_CPP
#define PROJECT_MOUSEEVENTS_CPP

#include <iostream>
#include "MouseEvents.h"
#include "SFML/Graphics.hpp"
// returns true if the mouse clicks on the object
template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i position = sf::Mouse::getPosition(window);
            if (object.getX() <= position.x && object.getX() + object.getWidth() >= position.x &&
                object.getY() <= position.y && object.getY() + object.getLength() >= position.y) {
                return true;
            }
        }
    return false;
}
template<class T>
bool MouseEvents<T>::mouseHovered(T &object, sf::RenderWindow &window) {
        sf::Vector2i position = sf::Mouse::getPosition(window);
        if (object.getX() <= position.x && object.getX() + object.getWidth() >= position.x &&
            object.getY() <= position.y && object.getY() + object.getLength() >= position.y) {
            return true;
        }
        return false;
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        countClicks(event);
        return true;
    }
    return false;

}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked() {
    if(clicks == 2){
        clicks = 0;
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked() {
    if(clicks == 3){
        clicks = 0;
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    return false;
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    return false;
}

template<class T>
void MouseEvents<T>::countClicks(sf::Event event) {
  clicks++;
}

template<class T>
bool MouseEvents<T>::mouseClickedCircle(T& object, sf::RenderWindow& window) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i position = sf::Mouse::getPosition(window);
        sf::Vector2f circlePosition = object.getOrigin();
        std::cout << (circlePosition.x - object.getRadius() <  position.x) << std::endl;
        std::cout << (position.x < circlePosition.x + object.getRadius()) << std::endl;
        std::cout << (circlePosition.y - object.getRadius() <  position.y) << std::endl;
        std::cout << (position.y < circlePosition.y + object.getRadius()) << std::endl;
        std:: cout << " " << std::endl;


        if ((circlePosition.x - object.getRadius() <  position.x || position.x < circlePosition.x + object.getRadius()) &&
                (circlePosition.y - object.getRadius() <  position.y || position.y < circlePosition.y + object.getRadius())) {
            return true;
        }
    }
    return false;}


#include "MouseEvents.cpp"
#endif //PROJECT_MOUSEEVENTS_CPP
