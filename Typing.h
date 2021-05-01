//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_TYPING_H
#define PROJECT_TYPING_H
#include <SFML/Graphics.hpp>
#include "Letter.h"
#include "Cursor.h"
#include "History.h"
#include "States.h"
#include "TextBox.h"

class Typing : public sf::Drawable {
private:
    sf::Font myFont;
    sf::Color myColor;
    std::string userString;
    std::vector<Letter *> characterContainer;
    Cursor *cursor;
    History *history;
    States *states1;
    TextBox *textBox1;

    int limit;
    bool blink;
public:
    Typing(Cursor *c, int limit, TextBox *textBox1);
    void addEventHandler(sf::RenderWindow &window, sf::Event event); //should be in the pollEvent loop and is used to detect when a key is pressed on the keyboard and concatenates the character to the sf::Text object
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const; //This function is to draw your text
    States * getStates();
    void setBlink();
};


#endif //PROJECT_TYPING_H
