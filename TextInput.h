
//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_TEXTINPUT_H
#define PROJECT_TEXTINPUT_H
#include "Cursor.h"
#include "Label.h"
#include "TextBox.h"
#include "Letter.h"
#include "Typing.h"
#include "MouseEvents.h"
#include "States.h"
//handles what characters are typed and manipulates what appears on screen
class TextInput:  public GUI_components{
private:
    Cursor *cursor1;
    Label *label1;
    TextBox *textbox1;
    Typing *typing;

    int x, y, length, width;
public:
    TextInput(int x, int y, int length, int width);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const; //This function is to draw your text
    Typing * getTyping();
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    //Snapshot& getSnapshot();
    void applySnapshot(const Snapshot& snapshot);

};


#endif //PROJECT_TEXTINPUT_H
