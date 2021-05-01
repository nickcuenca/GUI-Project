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
    sf::Vector2i position = sf::Mouse::getPosition();

    std::cout << "1: "  << position.y <<" " << object.getY()  << " " << object.getLength() << std::endl;
    std::cout << "3: " << ( object.getY() + object.getLength() >= position.y) << std::endl;

    if(object.getX() <= position.x && object.getX() + object.getWidth() >= position.x  && object.getY() <= position.y
    && object.getY() + 300 >= position.y){
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



#include "MouseEvents.cpp"
#endif //PROJECT_MOUSEEVENTS_CPP
