//
// Created by Nicolas Cuenca on 4/9/2021.
//

#ifndef PROJECT_LETTER_H
#define PROJECT_LETTER_H
#include "SFML/Graphics.hpp"

class Letter : public sf::Drawable {
private:

    sf::Color color;
    char character;
    sf::Text toDraw;
    int x;
    int y;
    sf::Font font;

public:
    Letter(char character, int x, int y );
    int getX();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const; //This function is to draw your text
};


#endif //PROJECT_LETTER_H
