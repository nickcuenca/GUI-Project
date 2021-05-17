//
// Created by Nicolas Cuenca on 5/14/2021.
//

#include "FileItem.h"


void FileItem::setIcon(Image::image icon) {
//    if (!iconPic.loadFromFile("images/folder.png"));
//    if (!iconPic.loadFromFile("images/file.png"));
    Image img;
    iconPic = img.getImage(icon);

    this->icon.setTexture(iconPic);
    this->icon.setScale(0.1, 0.1 );
    this->icon.setPosition(box->getX()  + 350, box->getY());

}

void FileItem::update() {
    cout << names.size() << endl;
    this->menu = new DropdownMenu(box, names, true);
    if(names.size() > 0){
        this->setIcon(Image::image::FOLDER);
    } else {
        this->setIcon(Image::image::FILE);
    }
}

FileItem::FileItem(Image::image icon, std::string text, int x, int y, int length, int width): Item(x,y, length, width, text){
    box = new InputBox(x, y, length, width, text);
    this->menu = new DropdownMenu(box, names, true);
    this->text = text;
    this->setIcon(icon);
}

DropdownMenu* FileItem::getMenu() const {
    return menu;
}

std::string FileItem::getString() const{
    return text;
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*menu);
    window.draw(icon);
    //_sleep(100);
}

void FileItem::addName(std::string name){
    names.push_back(name);
    update();
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    menu->addEventHandler(window, event);
}



