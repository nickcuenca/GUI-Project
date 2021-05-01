//
// Created by Nicolas Cuenca on 4/9/2021.
//
#include "stdio.h"
#include "Letter.h"
#include "iostream"
using namespace std;
Letter::Letter(char character, int x, int y) {
    this->character = character;
    if (isdigit(character)){
        color = sf::Color::Red;
    } else if (isalpha(character)){
        color = sf::Color::Blue;
    } else {
        color = sf::Color::Green;
    }
    this -> x=  x;
    this -> y = y;

    font.loadFromFile("OpenSans-Bold.ttf");
    toDraw.setFont(font);
    toDraw.setString(character);
    toDraw.setPosition(x, y);
    toDraw.setFillColor(color);
    toDraw.setCharacterSize(50);

}

void Letter::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(toDraw);
}