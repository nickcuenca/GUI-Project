//
// Created by Nicolas Cuenca on 4/5/2021.
//

#include "Typing.h"
#include "Snapshot.h"
#include <iostream>

Typing::Typing(Cursor *cursor, int limit, TextBox *textBox1) {
    myFont.loadFromFile("OpenSans-Bold.ttf");
    if (!myFont.loadFromFile( "OpenSans-Bold.ttf")) {
        std::cout << "Could not load font." << std::endl;
        return;
    }
    this->textBox1 = textBox1;
    this-> cursor = cursor;
    this->history = new History();
    this->states1 = new States();
    this->limit = limit;
    this->blink = true;
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            if(history->size() != 0){
                history->pop();
                if(history->size() == 0){
                    characterContainer.clear();
                } else {
                    Snapshot * currTop = history->top();
                    characterContainer = currTop->getVec();
                    cursor->setX(currTop->getCursorX());
                    cursor->setY(currTop->getCursorY());
                }
            }
        }
    }

    else if(event.text.unicode == 0x000008 && characterContainer.size() != 0){
           characterContainer.pop_back();
           cursor->moveLeft();
           Snapshot *curr = new Snapshot(characterContainer, cursor->getX(), cursor->getY());
           history->push(curr);
    }
    else if (event.type == sf::Event::TextEntered && event.text.unicode != 0x000008 && cursor->getX() < limit ) {
        characterContainer.push_back(new Letter(static_cast<char>(event.text.unicode), cursor->getX(), cursor->getY()));
        cursor->moveRight();
        Snapshot *curr = new Snapshot(characterContainer, cursor->getX(), cursor->getY());
        history->push(curr);
    } else if (event.type == sf::Event::TextEntered && cursor->getX() >= limit){
        characterContainer.push_back(new Letter(static_cast<char>(event.text.unicode), cursor->getX(), cursor->getY()));
        textBox1 = new TextBox(textBox1->getX(), textBox1->getY(), textBox1->getLength() + 30, textBox1->getWidth());
        cursor->setX(100);
        cursor->moveDown();
        Snapshot *curr = new Snapshot(characterContainer, cursor->getX(), cursor->getY());
        history->push(curr);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        textBox1 = new TextBox(textBox1->getX(), textBox1->getY(), textBox1->getLength() + 30, textBox1->getWidth());
    }





}




void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*textBox1);
    for (int i = 0; i < characterContainer.size(); i++) {
        window.draw(*characterContainer[i]);
    }
    if (states1->isStateEnable(static_cast<ObjectStates>(1))){
        if(blink) {
            window.draw(*cursor);
        }
        states1->disableState(static_cast<ObjectStates>(1));
    }
}

States *Typing::getStates() {
    return states1;
}


void Typing::setBlink(){
    blink = !blink;
}
