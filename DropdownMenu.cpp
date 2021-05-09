//
// Created by Nicolas Cuenca on 4/29/2021.
//

#include "SFML/Graphics.hpp"
#include "DropdownMenu.h"
DropdownMenu::DropdownMenu(InputBox *inputBox, std::vector<std::string> names) {
    this->names = names;
    this->inputBox = inputBox;
    this->itemList = new ItemList(inputBox->getX(), inputBox->getY(), inputBox->getLength(), inputBox->getWidth());

    for (int i = 0; i < names.size(); i++) {
        itemList->pushToList(names[i]);
    }
    dropdownVisible = false;

    this->menuHistory_ = new MenuHistory();
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*inputBox);
    if (dropdownVisible){
        window.draw(*itemList);
    }
//    _sleep(100);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if(MouseEvents<InputBox>::mouseClicked(*inputBox, window)){
        dropdownVisible = true;
    }
    for(int i = 0; i < itemList->getItems().size(); i++){
        if(MouseEvents<InputBox>::mouseHovered(*itemList->getItems()[i], window) && dropdownVisible) {
            itemList->getItems()[i]->highlightBlue();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){

                    cout << menuHistory_->size() << endl;
                    if(menuHistory_->size() != 0){
                        MenuSnapshot * currTop = menuHistory_->top();
                        menuHistory_->pop();
                        this->inputBox = currTop->getInputbox();
                        this->itemList = currTop->getItemlist();

                        break;
                    }
                }
            }

        } else if(dropdownVisible) {
            itemList->getItems()[i]->reset();
        }


        if(MouseEvents<InputBox>::mouseClicked(*itemList->getItems()[i], window) && dropdownVisible){
            menuHistory_->push(new MenuSnapshot(new InputBox(*inputBox), new ItemList(*itemList)));
            std::string tempString = inputBox->getString();
            inputBox->setString(itemList->getItems()[i]->getString());
            itemList->getItems()[i]->setString(tempString);
            dropdownVisible = false;
        }



    }

}

void DropdownMenu::update() {

}

