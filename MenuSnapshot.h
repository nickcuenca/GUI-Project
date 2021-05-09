//
// Created by Nicolas Cuenca on 5/2/2021.
//

#ifndef PROJECT_MENUSNAPSHOT_H
#define PROJECT_MENUSNAPSHOT_H

#include <string>
#include "Item.h"
#include "InputBox.h"
#include "ItemList.h"
class MenuSnapshot {
private:
    InputBox* inputBox;
//    std::vector<std::string> names;

    ItemList *itemList;
public:
    MenuSnapshot(InputBox* inputBox1, ItemList* itemList1);
    InputBox* getInputbox();
    ItemList* getItemlist();
};


#endif //PROJECT_MENUSNAPSHOT_H
