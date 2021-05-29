//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_MOUSEEVENTS_H
#define PROJECT_MOUSEEVENTS_H
#include "SFML/Graphics.hpp"
template <class T>
class MouseEvents {

public:
    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked( sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();

    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();

    // returns if the object has been clicked and the mouse has dragged over the object
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);

    // returns tru if the mouse is hovered over the object
    static bool hovered(T& object, sf::RenderWindow& window);

    static bool mouseClicked(T& object, sf::RenderWindow& window);
    static bool mouseHovered(T& object, sf::RenderWindow& window);

    static bool mouseClickedCircle(T& object, sf::RenderWindow& window);

private:
    // this is what I used to determine if a double click or triple click occurred
    // you don't have to use this if you don't want to
    static sf::Clock clock;
    static int clicks;
    static void countClicks(sf::Event event);
};


#include "MouseEvents.cpp"
#endif //PROJECT_MOUSEEVENTS_H
