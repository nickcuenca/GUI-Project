//
// Created by Nicolas Cuenca on 4/9/2021.
//
#include "stdio.h"
#include "Letter.h"
#include "iostream"

using namespace std;
Letter::Letter(char character, int x, int y) {
    this->character = character;
    color = sf::Color::Red;
    this -> x=  x;
    this -> y = y;

    font.loadFromFile("OpenSans-Bold.ttf");
    toDraw.setFont(font);
    toDraw.setString(character);
    toDraw.setPosition(x, y);
    toDraw.setFillColor(color);
    toDraw.setCharacterSize(25);

}

void Letter::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(toDraw);
}

Letter::Letter(const Letter &letter) {
    character = letter.character;
//    if (isdigit(character)){
//        color = sf::Color::Red;
//    } else if (isalpha(character)){
//        color = sf::Color::Blue;
//    } else {
//        color = sf::Color::Green;
//    }

    color = letter.color;
    x = letter.x;
    y = letter.y;
    font = letter.font;
    toDraw = letter.toDraw;
}

int Letter::getX() {
    return x;
}

int Letter::getY() {
    return y;
}

void Letter::setX(int x) {
    this->x = x;
    toDraw.setPosition(x, y);
}

void Letter::setY(int y) {
    this->y = y;
    toDraw.setPosition(x, y);
}

void Letter::setColor(const sf::Color &color, int opacity) {
    this->color = color;
    toDraw.setFillColor(sf::Color(color.r,color.g, color.b, 255 * opacity/100.0));
}

char Letter::getCharacter(){
    return character;
};
