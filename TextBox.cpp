//
// Created by Nicolas Cuenca on 4/5/2021.
//

#include "TextBox.h"

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

int TextBox::getX() {
    return x;
}

int TextBox::getLength() {
    return length;
}

int TextBox::getWidth() {
    return width;
}

int TextBox::getY() {
    return y;
}

void TextBox::setLength(int length) {
    this->length = length;
}
