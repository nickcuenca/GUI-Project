//
// Created by Nicolas Cuenca on 5/27/2021.
//

#include "Slider.h"

Slider::Slider(int x, int y, int lineLength, std::string sliderString) {
    this->sliderString = sliderString;
    this->percentageString = percentageString;
    this->x = x;
    this->y = y;
    this->lineLength = lineLength;
    setText(sliderString, percentageString);
    this->circleX = (x + lineLength)/2;
    this->circleY = y;


}

void Slider::setText(std::string sliderString, std::string percentageText) {
    this->sliderText.setString(sliderString);
    this->sliderText.setCharacterSize(10);
    this->sliderText.setFillColor(sf::Color::Red);

    this->percentageText.setString(percentageText);
    this->percentageText.setCharacterSize(10);
    this->percentageText.setFillColor(sf::Color::Red);
}


void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f(10, 10)),
                    sf::Vertex(sf::Vector2f(150, 150))
            };
    sf::CircleShape *button = new sf::CircleShape(2, 30);
    button->setPosition(circleX, circleY);


    window.draw(line, 2, sf::Lines);
    window.draw(sliderText);
    window.draw(percentageText);
    window.draw(*button);

}


void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {


}

void Slider::update() {}