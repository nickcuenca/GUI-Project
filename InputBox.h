//
// Created by Nicolas Cuenca on 4/29/2021.
//

#ifndef PROJECT_INPUTBOX_H
#define PROJECT_INPUTBOX_H
#include "TextBox.h"
//This is the box the display the selected Item. You may already have this class developed from the previous TextInput project. Feel free, in fact, PLEASE reuse classes if you are able to.
class InputBox : public TextBox {
private:
    sf::Text inputWord;
    sf::Font myFont;
    std::string input;
    sf::Color myColor;
public:

    InputBox(int x, int y, int length, int width, std::string input);
    InputBox(const InputBox & box);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const; //This function is to draw your text

    void setString(string input);
    std::string getString() const;
};


#endif //PROJECT_INPUTBOX_H
