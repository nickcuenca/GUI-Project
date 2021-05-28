//
// Created by Nicolas Cuenca on 5/14/2021.
//

#include "FileItem.h"


void FileItem::setIcon(Image::image icon) {
//    if (!iconPic.loadFromFile("images/folder.png"));
//    if (!iconPic.loadFromFile("images/file.png"));
    Image img;
    iconPic = img.getImage(icon);
    this->icon_img = icon;
    this->icon.setTexture(iconPic);
    this->icon.setScale(0.1, 0.1 );
    this->icon.setPosition(getX()  + 350, getY());
}

Image::image FileItem::getIcon() const{
    return icon_img;
}

void FileItem::update() {
}


void FileItem::setY(int y){
    TextBox::setY(y);
    InputBox::update();
}

FileItem::FileItem(Image::image icon, std::string text, int x, int y, int length, int width): Item(x,y, length, width, text){
    this->text = text;
    this->length = length;
    this->width = width;
    this->setIcon(icon);
    this->dropdown_menu = false;
}

bool FileItem::getDropdown(){
    return dropdown_menu;
}

std::string FileItem::getString() const{
    return text;
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Item::draw(window, states);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<FileItem>::mouseClicked(*this, window)){
        dropdown_menu =! dropdown_menu;
    }
    if(MouseEvents<FileItem>::mouseHovered(*this, window)){
        this->highlightBlue();
    } else {
        this->reset();
    }
}


