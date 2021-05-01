//
// Created by Nicolas Cuenca on 4/29/2021.
//

#include "InputBox.h"
#include <iostream>
void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    TextBox::draw(window, states);
    window.draw(inputWord);
}


InputBox::InputBox(int x, int y, int length, int width, std::string input) : TextBox(x, y, length, width){
    this->inputWord.setString(input);
    this->input = input;
    myFont.loadFromFile("OpenSans-Bold.ttf");
    if (!myFont.loadFromFile("OpenSans-Bold.ttf")) {
        std::cout << "Could not load font." << std::endl;
        return;
    }
    this->inputWord.setFont(myFont);
    this->inputWord.setCharacterSize(50);
    this->inputWord.setColor(sf::Color::Black);
    this->inputWord.setPosition(x, y);
}

void InputBox::setString(std::string input){
    this->inputWord.setString(input);
    this->input = input;
}

std::string InputBox::getString() {
    return input;
}
