//
// Created by Nicolas Cuenca on 4/29/2021.
//

#include "ItemList.h"

ItemList::ItemList(int x, int y, int length, int width, bool file_menu) {
    this->x = x;
    this->y = y;
    this->length = length;
    this->width = width;
}

ItemList::ItemList(const ItemList &lst){
    this->x = lst.x;
    this-> y = lst.y;
    this->length = lst.length;
    this->width = lst.width;
    for(int i = 0; i < lst.listOfItems.size(); i++){
        pushToList(lst.listOfItems[i]->getString());
    }
}

void ItemList::pushToList(std::string word, bool file_menu) {
    listOfItems.push_back(new Item(x , y + length * (listOfItems.size() + 1), length, width, word));
}

vector<Item *> ItemList::getItems(){
    return listOfItems;
}

void ItemList::clearList(){
    listOfItems.clear();
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < listOfItems.size() ; i++) {
        window.draw(*listOfItems[i]);
    }
}

