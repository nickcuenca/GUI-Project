//
// Created by Nicolas Cuenca on 4/29/2021.
//

#include "ItemList.h"
ItemList::ItemList(int x, int y, int length, int width) {
    this->x = x;
    this->y = y;
    this->length = length;
    this->width = width;

}
void ItemList::pushToList(std::string word) {
    listOfItems.push_back(new Item(x, y + length * (listOfItems.size() + 1), length, width, word));

}

vector<Item *> ItemList::getItems(){
    return listOfItems;
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < listOfItems.size() ; i++) {
        window.draw(*listOfItems[i]);
    }

//    _sleep(100);
}