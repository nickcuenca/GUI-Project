//
// Created by Nicolas Cuenca on 5/14/2021.
//

#include "FileTree.h"
////PRIVATES
void FileTree::push(FileNode *&root, std::string parent, std::string item) {
    if (root->getData()->getString().compare(parent) == 0){
        root->addChild(item);
        return;
    }
    vector<FileNode*> children = root->getChildren();
    for (FileNode* node : children){
        push(node, parent, item);
    }
}

void FileTree::traverse(FileNode *&curr, sf::RenderWindow &window, sf::Event event) {
    curr->addEventHandler(window, event);
}


void FileTree::traverseDraw(FileNode *root, sf::RenderTarget &window, sf::RenderStates states) const{
}


void FileTree::push(std::string parent, std::string item) {
    push(root, parent, item);

}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    root->draw(window, states);
}



void FileTree::applySnapshot(const Snapshot &snapshot) {

}

void FileTree::updateY(){
    int val = 0;
    this->updateY(root, val);
}

void FileTree::updateY(FileNode *&curr, int &offset){
    curr->getData()->setY(root->getData()->getY() + offset);
    curr->getData()->setIcon(curr->getData()->getIcon());

    offset += curr->getData()->getLength();
    for(int i = 0; i < curr->getChildren().size() && curr->getData()->getDropdown(); i++){
        updateY(curr->getChildren()[i], offset);
    }
}


void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    traverse(root, window, event);
}

void FileTree::update() {
    updateY();
    cout << " " << endl;
}

FileTree::FileTree(FileNode *root, sf::RectangleShape *img) {
    this->root = root;
    this->img = img;
}

////PUBLICs

