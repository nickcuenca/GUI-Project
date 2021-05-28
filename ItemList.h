//
// Created by Nicolas Cuenca on 4/29/2021.
//

#ifndef PROJECT_ITEMLIST_H
#define PROJECT_ITEMLIST_H
#include <vector>
#include <string>
#include "Item.h"
//This is a list of Items. The items should be vertically aligned.
class ItemList : public sf::Drawable {
private:
//    std::vector<FileItem*> listOfFiles;
    std::vector<Item*>  listOfItems;
    
    int x, y, length, width;
    bool file_menu;
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    ItemList(int x, int y, int i, int i1, bool file_menu = false);
    void pushToList(std::string word, bool file_menu = false);
    ItemList(const ItemList &lst);
    vector<Item *> getItems();
//    vector<FileItem *> getFiles();
    void clearList();
};


#endif //PROJECT_ITEMLIST_H
