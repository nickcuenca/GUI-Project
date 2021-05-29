//
// Created by Nicolas Cuenca on 5/28/2021.
//

#include "MemeTyping.h"


MemeTyping::MemeTyping(const sf::Color&  color) {

//    Cursor(int x, int y, int width, int length);

    Cursor* cursor = new Cursor(1400, 200, 5, 15);

    //    TextBox(int x, int y, int length, int width);
    TextBox* textBox = new TextBox(1400, 200, 100, 350);

//    (Cursor *c, int limit, TextBox *textBox1);
    typingTop = new Typing(cursor, 1800, textBox);
    this->color = color;



    Cursor* cursor2 = new Cursor(1400, 450, 5, 15);

    //    TextBox(int x, int y, int length, int width);
    TextBox* textBox2 = new TextBox(1400, 450, 100, 350);

//    (Cursor *c, int limit, TextBox *textBox1);
    typingBot = new Typing(cursor2, 1800, textBox2);

}

void MemeTyping::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*typingTop);
    window.draw(*typingBot);
    for (int i = 0; i < typingTop->getCharacterContainer().size(); i++) {
        Letter* letterTop = new Letter(*typingTop->getCharacterContainer()[i]);
        letterTop->setX(450 + (i * 20) % 600);
        letterTop->setY(100 + (i/30) * 30);
        letterTop->setColor(color);
        window.draw(*letterTop);
    }
    for (int i = 0; i < typingBot->getCharacterContainer().size(); i++) {
        Letter* letterBot = new Letter(*typingBot->getCharacterContainer()[i]);
        letterBot->setX(450 +(i*20) % 600);
        letterBot->setY(550 + (i/30) * 30);
        letterBot->setColor(color);
        window.draw(*letterBot);
    }
}


void MemeTyping::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    typingTop->addEventHandler(window, event);
    typingBot->addEventHandler(window, event);

}

void MemeTyping::setColor(const sf::Color &color){
    this->color = color;
}

void MemeTyping::update() {

}

