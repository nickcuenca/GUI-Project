//
// Created by Nicolas Cuenca on 4/9/2021.
//

#ifndef PROJECT_LABEL_H
#define PROJECT_LABEL_H
#include "SFML/Graphics.hpp"

class Label : public sf::Drawable {
private:
    sf::Text text;
    sf::Font font;
    std::string labelInstruction = "Enter your information:\n";
public:
    Label();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const; //This function is to draw your text
};


#endif //PROJECT_LABEL_H
