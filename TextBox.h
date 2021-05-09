//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_TEXTBOX_H
#define PROJECT_TEXTBOX_H
#include "SFML/Graphics.hpp"
#include "GUI_components.h"

class TextBox : public sf::Drawable {
private:
    sf::RectangleShape rectangle;
    int x, y, width, length;
public:
    TextBox(int x, int y, int length, int width);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const; //This function is to draw your text
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getLength() const;

    void highlightBlue();
    void reset();
    void setLength(int length);
};


#endif //PROJECT_TEXTBOX_H
