//
// Created by Nicolas Cuenca on 4/29/2021.
//

#include "SFML/Graphics.hpp"
#include "DropdownMenu.h"

DropdownMenu::DropdownMenu(InputBox *inputBox, std::vector<std::string> _names, bool file_menu) {
    
//    cout << "NAMES" << "Input box" << inputBox->getString() <<"" <<  _names.size() << endl;
    this->names.clear();
    for(int i = 0; i < _names.size(); i++){
        this->names.push_back(_names[i]);
    }
    this->inputBox = inputBox;
    this->itemList = new ItemList(inputBox->getX(), inputBox->getY(), inputBox->getLength(), inputBox->getWidth());

    
    for (int i = 0; i < this->names.size(); i++) {
            itemList->pushToList(names[i], file_menu);
    }
    dropdownVisible = false;

    this->menuHistory_ = new MenuHistory();
    this->file_menu = file_menu;
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*inputBox);
    if (dropdownVisible){
        window.draw(*itemList);
//        cout << "DROPDOWN" << inputBox->getString() << "Address: " << inputBox << names.size() << endl;
    }
//    _sleep(100);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if(MouseEvents<InputBox>::mouseClicked(*inputBox, window)){
        dropdownVisible = true;
//        cout << "DROPDOWN22212" << inputBox->getString()  << " " << inputBox <<  names.size() << endl;
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


        if(MouseEvents<InputBox>::mouseClicked(*itemList->getItems()[i], window) && dropdownVisible && !file_menu) {
            menuHistory_->push(new MenuSnapshot(new InputBox(*inputBox), new ItemList(*itemList)));
            std::string tempString = inputBox->getString();
            inputBox->setString(itemList->getItems()[i]->getString());
            itemList->getItems()[i]->setString(tempString);
            dropdownVisible = false;
        }
        
        
        



//        if(MouseEvents<InputBox>::mouseClicked(*itemList->getItems()[i], window) && dropdownVisible && file_menu) {
//            FileItem * item = (FileItem *) itemList->getItems()[i];
//            item->addEventHandler(window, event);
//        }
    }

}

void DropdownMenu::update() {

}

