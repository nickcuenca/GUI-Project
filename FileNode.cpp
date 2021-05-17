//
// Created by Nicolas Cuenca on 5/14/2021.
//

#include "FileNode.h"

FileNode::FileNode(std::string text, int x, int y, int length, int width) {
    data = new FileItem(Image::image::FILE, text, x, y, length, width);
}

bool FileNode::isLeaf() const {
    return children.empty();
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    data->draw(window, states);
}

FileItem* &FileNode::getData() {
    return data;
}



void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    data->addEventHandler(window, event);
}

vector<FileNode *> &FileNode::getChildren() {
    return children;
}

void FileNode::addChild(std::string string1) {
    children.push_back(new FileNode(string1, data->getX() + 50, data->getY() + (children.size() + 1) * data->getLength(), data->getLength() , data->getWidth()));
    data->addName(string1);
}

void FileNode::update() {

}
