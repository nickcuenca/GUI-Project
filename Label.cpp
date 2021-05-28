//
// Created by Nicolas Cuenca on 4/9/2021.
//

#include "Label.h"
Label::Label() {
    font.loadFromFile("OpenSans-Bold.ttf");
    text.setFont(font);
    text.setString(labelInstruction);
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 20);
}

void Label::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}


