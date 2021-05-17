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

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window, event);
    vector<FileNode*> children = root->getChildren();
    for (FileNode* node : children){
        traverse(node, window, event);
    }
}


void FileTree::traverseDraw(FileNode *root, sf::RenderTarget &window, sf::RenderStates states) const{
    root->draw(window, states);
    /*
    vector<FileNode*> children = root->getChildren();
    for (FileNode* node : children){
        traverseDraw(node, window, states);
    }
     */
}


void FileTree::push(std::string parent, std::string item) {
    push(root, parent, item);

}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    traverseDraw(root, window, states);
}

void FileTree::applySnapshot(const Snapshot &snapshot) {

}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    traverse(root, window, event);
}

void FileTree::update() {
}

FileTree::FileTree(FileNode *root) {
    this->root = root;
}

////PUBLICs

