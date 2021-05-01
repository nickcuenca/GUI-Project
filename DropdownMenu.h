//
// Created by Nicolas Cuenca on 4/29/2021.
//

#ifndef PROJECT_DROPDOWNMENU_H
#define PROJECT_DROPDOWNMENU_H
#include "GUI_components.h"
#include "Item.h"
#include "ItemList.h"
#include "InputBox.h"

//This is the class that brings the Item, ItemList and InputBox together. This class must also be a child of GUIComponent
class DropdownMenu : public GUI_components, public Item, public ItemList, public InputBox {

};


#endif //PROJECT_DROPDOWNMENU_H
