//
// Created by Nicolas Cuenca on 5/28/2021.
//

#ifndef PROJECT_MEMETYPING_H
#define PROJECT_MEMETYPING_H
#include "Typing.h"
#include "GUI_components.h"
#include "Cursor.h"
#include "TextBox.h"

class MemeTyping : public GUI_components{
private:
    Typing* typingTop;
    Typing* typingBot;
    sf::Color color;
    int topOpacity;
    int bottomOpacity;
    int topXPosition;
    int bottomXPosition;
    int topYPosition;
    int bottomYPosition;
public:
    MemeTyping(const sf::Color &color, int topOpacity, int bottomOpacity, int topXPercentage, int bottomXPercentage, int topYPercentage, int bottomYPercentage);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    //Precondition: A splash screen object is created
    //Postcondition: Splash Screen can now be drawn on screen.
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    void setColor(const sf::Color &color);

    void setTopOpacity(const int opacity);
    void setBottomOpacity(const int opacity);

    void setTopXPercentage(const int xPercent);

    void setBottomXPercentage(const int xPercent);

    void setTopYPercentage(const int yPercent);

    void setBottomYPercentage(const int yPercent);
//    void setRotationMemeRectangle(const float angle);
};


#endif //PROJECT_MEMETYPING_H
