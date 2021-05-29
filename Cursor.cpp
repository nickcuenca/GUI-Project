//
// Created by Nicolas Cuenca on 4/5/2021.
//

#include "Cursor.h"

Cursor::Cursor(int x, int y,int width, int length) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->length = length;

    rectangle.setPosition(x, y);
    rectangle.setSize(sf::Vector2f(width, length));
    rectangle.setFillColor(sf::Color::Blue);
}


void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rectangle);
}

int Cursor::getX(){
    return x;
}

int Cursor::getY(){
    return y;
}


void Cursor::moveRight() {
    x = x  + 20;
    rectangle.setPosition(x, y);
}

void Cursor::moveLeft() {
    x = x - 20;
    rectangle.setPosition(x, y);
}

void Cursor::setY(int i) {
    y = i;
}


void Cursor::setX(int i) {
    x = i;
}

void Cursor::moveDown() {
    y = y + 20;
    rectangle.setPosition(x, y);
}
