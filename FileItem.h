//
// Created by Nicolas Cuenca on 5/14/2021.
//

#ifndef PROJECT_FILEITEM_H
#define PROJECT_FILEITEM_H
#include "GUI_components.h"
#include "Image.h"
#include "Item.h"
#include "MouseEvents.h"
#include "DropdownMenu.h"

//This class is similar to your Item class. In addition to the normal background and text,
//the FileItem class will also have an icon. This icon indicates whether the FileItem is a directory or a file.
class FileItem : public GUI_components, public Item {
public:
    //Constructors
    FileItem();
    FileItem(Image::image icon, string text, int x, int y, int length, int width);
    FileItem(const FileItem& copy);
//GUIComponent pure virtual functions, refer to the TextInput Project for Info
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    void update();

    void addName(std::string name);
    //uses an string to change the icon to a folder or file
    void setIcon(Image::image icon);
    std::string getString() const;

    DropdownMenu * getMenu() const;

private:
    //this is the folder or file icon
    InputBox *box;
    std::vector<std::string> names;
    DropdownMenu *menu;
    sf::Texture iconPic;
    sf::Sprite icon;
    float padding = 5;
    std::string text;
    int x;
    int y;

};


#endif //PROJECT_FILEITEM_H
