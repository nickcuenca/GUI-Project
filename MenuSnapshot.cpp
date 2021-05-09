//
// Created by Nicolas Cuenca on 5/2/2021.
//

#include "MenuSnapshot.h"
MenuSnapshot::MenuSnapshot(InputBox* inputBox1, ItemList* itemList1) {
    this->inputBox = inputBox1;
    this->itemList = itemList1;

}

InputBox* MenuSnapshot::getInputbox() {
    return inputBox;
}

ItemList* MenuSnapshot::getItemlist() {
    return itemList;
}

