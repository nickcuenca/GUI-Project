//
// Created by Nicolas Cuenca on 4/5/2021.
//

#include "TextInput.h"


TextInput::TextInput(int x, int y, int length, int width) {
    textbox1 = new TextBox(x, y, length, width);
    label1 = new Label();
    cursor1 = new Cursor(x, y,10, length);
    typing = new Typing(cursor1, width + x, textbox1);
    this->x = x;
    this->y = y;
    this->length = length;
    this->width = width;

}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*label1);
    window.draw(*typing);
    _sleep(100);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<TextBox>::mouseClicked(*textbox1, window)){
        typing->getStates()->enableState(static_cast<ObjectStates>(1));
    }
}

Typing *TextInput::getTyping() {
    return typing;
}

void TextInput::update() {

}





//from SnapshotInterface
//Snapshot& getSnapshot(){
//    Snapshot snap();
//    return reinterpret_cast<Snapshot &>(snap);
//}
void TextInput::applySnapshot(const Snapshot& snapshot){
//    cout << "HI" << endl;
}

