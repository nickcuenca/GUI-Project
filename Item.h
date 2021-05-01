//
// Created by Nicolas Cuenca on 4/29/2021.
//

#ifndef PROJECT_ITEM_H
#define PROJECT_ITEM_H
#include "InputBox.h"
//This is a simple item in the list, it should consist of a simple box with the item name centered.
class Item : public InputBox {
private:
public:
    Item(int x, int y, int length, int width, std::string input);
};


#endif //PROJECT_ITEM_H
