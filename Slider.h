//
// Created by Nicolas Cuenca on 5/27/2021.
//

#ifndef PROJECT_SLIDER_H
#define PROJECT_SLIDER_H
#include "GUI_components.h"
#include "MouseEvents.h"
class Slider : public GUI_components {
private:
    sf::CircleShape *button;
    sf::Text sliderText, percentageText; //percentage can be changed
    std::string sliderString, percentageString;
    sf::Font font;
    int min, max, x, y, circleX, circleY, lineLength;
    bool dragged;
public:
    Slider(int x, int y, int lineLength, std::string sliderString);
    void setText(std::string sliderString);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    int getPercentage();


};


#endif //PROJECT_SLIDER_H
