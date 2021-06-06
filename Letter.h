//
// Created by Nicolas Cuenca on 4/9/2021.
//

#ifndef PROJECT_LETTER_H
#define PROJECT_LETTER_H
#include "SFML/Graphics.hpp"

class Letter : public sf::Drawable {
private:

    sf::Color color;
public:
    void setColor(const sf::Color &color, int opacity);

private:
    char character;
    sf::Text toDraw;
    int x;
    int y;
    sf::Font font;

public:
    Letter(char character, int x, int y );
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    Letter (const Letter& letter);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const; //This function is to draw your text
    char getCharacter();
};


#endif //PROJECT_LETTER_H
