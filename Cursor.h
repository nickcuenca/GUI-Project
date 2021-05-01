//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_CURSOR_H
#define PROJECT_CURSOR_H
#include "SFML/Graphics.hpp"

class Cursor : public sf::Drawable {
private:
    sf::RectangleShape rectangle;
    int x, y, width, length;
public:
    Cursor(int x, int y, int width, int length);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const; //This function is to draw your text
    void moveRight();
    void moveLeft();
    int getX();
    int getY();

    void setY(int i);

    void setX(int i);
    void moveDown();
};


#endif //PROJECT_CURSOR_H
