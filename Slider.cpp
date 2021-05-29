//
// Created by Nicolas Cuenca on 5/27/2021.
//

#include <iostream>
#include "Slider.h"
#include <sstream>
Slider::Slider(int x, int y, int lineLength, std::string sliderString) {
    button = new sf::CircleShape(10, 10);
    this->sliderString = sliderString;
    this->percentageString = "";
    this->x = x;
    this->y = y;
    this->lineLength = lineLength;
    this->circleX = x + (lineLength /2) - 5;
    this->circleY = y - 8;
    setText(sliderString);

    font.loadFromFile("OpenSans-Bold.ttf");
    if (!font.loadFromFile( "OpenSans-Bold.ttf")) {
        std::cout << "Could not load font." << std::endl;
        return;
    }

    this->sliderText.setPosition(x - 210, y - 15);
    this->percentageText.setPosition(x + lineLength + 15, y - 15);
    this->sliderText.setFont(font);
    this->percentageText.setFont(font);

    this->dragged = false;
    this->button->setPosition(circleX, circleY);

}

void Slider::setText(std::string sliderString) {
    this->sliderText.setString(sliderString);
    this->sliderText.setCharacterSize(22);
    this->sliderText.setFillColor(sf::Color::Red);
    int percentage = ((x + lineLength) - circleX) * 100/(lineLength);
    percentageText.setString( std::to_string(100 - percentage) + "%");

    this->percentageText.setCharacterSize(22);
    this->percentageText.setFillColor(sf::Color::Red);
}

int Slider::getPercentage() {
    std::string s = this->percentageText.getString();
    stringstream ans(s);
    int x = 0;
    ans >> x;
    return x;
}


void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f(x, y)),
                    sf::Vertex(sf::Vector2f(x + lineLength, y))
            };


    window.draw(line, 2, sf::Lines);
    window.draw(sliderText);

    window.draw(percentageText);
    window.draw(*button);
}


void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::CircleShape>::mouseClickedCircle(*button, window)) {
        dragged = !dragged;
    }
    if (dragged){
        sf::Mouse mouse;
        sf::Vector2f newPos = sf::Vector2f(mouse.getPosition(window));
        if ((newPos.x >= x) && (newPos.x <= x + lineLength) && (y - 20 < newPos.y) && (newPos.y < y + 20)){
            circleX = newPos.x;
            button->setPosition(circleX, circleY);
            setText(sliderString);
        }
    }
}

void Slider::update() {}