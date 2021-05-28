//
// Created by Nicolas Cuenca on 4/5/2021.
//

#include "TextBox.h"

using namespace std;
TextBox::TextBox(int x, int y, int length, int width) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->length = length;

    rectangle.setPosition(x, y);
    rectangle.setSize(sf::Vector2f(width, length));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(5);
}


void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rectangle);
}

int TextBox::getX() const {
    return x;
}

int TextBox::getLength() const{
    return length;
}

int TextBox::getWidth() const {
    return width;
}

int TextBox::getY() const {
    return y;
}

void TextBox::setY(int y) {
    this->y = y;
    rectangle.setPosition(x, y);
}

void TextBox::setLength(int length) {
    this->length = length;
}

void TextBox::highlightBlue() {
    this->rectangle.setFillColor(sf::Color::Blue);
}

void TextBox::reset() {
    this->rectangle.setFillColor(sf::Color::White);
}
