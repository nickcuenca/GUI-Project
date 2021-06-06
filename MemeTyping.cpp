//
// Created by Nicolas Cuenca on 5/28/2021.
//

#include "MemeTyping.h"


MemeTyping::MemeTyping(const sf::Color &color, int topOpacity, int bottomOpacity, int topXPercentage,
                       int bottomXPercentage, int topYPercentage, int bottomYPercentage) {

//    Cursor(int x, int y, int width, int length);

    Cursor* cursor = new Cursor(1400, 200, 5, 15);

    //    TextBox(int x, int y, int length, int width);
    TextBox* textBox = new TextBox(1400, 200, 100, 420);

//    (Cursor *c, int limit, TextBox *textBox1);
    typingTop = new Typing(cursor, 1800, textBox);
    this->color = color;
    this->topOpacity = topOpacity;
    this->bottomOpacity = bottomOpacity;
    this->topXPosition = 450 + 900 * topXPercentage/100;
    this->bottomXPosition = 450  + 900 * bottomXPercentage/100;
    this->topYPosition = 100 + 300 * topYPercentage/100;
    this->bottomYPosition = 400 + 300 * bottomYPercentage/100;

    Cursor* cursor2 = new Cursor(1400, 450, 5, 15);

    //    TextBox(int x, int y, int length, int width);
    TextBox* textBox2 = new TextBox(1400, 450, 100, 420);

//    (Cursor *c, int limit, TextBox *textBox1);
    typingBot = new Typing(cursor2, 1800, textBox2);

}

void MemeTyping::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*typingTop);
    window.draw(*typingBot);
    for (int i = 0; i < typingTop->getCharacterContainer().size(); i++) {
        Letter* letterTop = new Letter(*typingTop->getCharacterContainer()[i]);
        letterTop->setX(topXPosition + (i * 20) % 600);
        letterTop->setY(topYPosition + (i/30) * 30);
        letterTop->setColor(color, topOpacity);
        window.draw(*letterTop);
    }
    for (int i = 0; i < typingBot->getCharacterContainer().size(); i++) {
        Letter* letterBot = new Letter(*typingBot->getCharacterContainer()[i]);
        letterBot->setX(bottomXPosition + (i*20) % 600);
        letterBot->setY(bottomYPosition + (i/30) * 30);
        letterBot->setColor(color, bottomOpacity);
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

void MemeTyping::setTopOpacity(const int opacity){
    this->topOpacity = opacity;
}

void MemeTyping::setBottomOpacity(const int opacity){
    this->bottomOpacity = opacity;
}

void MemeTyping::setTopXPercentage(const int xPercent){
    this->topXPosition = 450 + 850 * xPercent/100;
}

void MemeTyping::setBottomXPercentage(const int xPercent){
    this->bottomXPosition = 450  + 850 * xPercent/100;

}

void MemeTyping::setTopYPercentage(const int yPercent){
    this->topYPosition = 100 + 300 * yPercent/100;
}

void MemeTyping::setBottomYPercentage(const int yPercent){
    this->bottomYPosition = 400 + 300 * yPercent/100;
}

void MemeTyping::update() {

}

//void MemeTyping::setRotationMemeRectangle(const float angle) {
//
//}



