//
// Created by Nicolas Cuenca on 5/14/2021.
//

#ifndef PROJECT_FILENODE_H
#define PROJECT_FILENODE_H
#include "vector"
#include "SFML/Graphics.hpp"
#include "FileItem.h"
#include "Image.h"
#include "GUI_components.h"

//This is the Node for your File Tree. It will contain a FileItem as the data,
//and Node* vector to hold the nodes children (you can also use a map or linked list if you choose).
class FileNode : public GUI_components {
//This is the data represented in the tree
    FileItem* data;
    int x;
    int y;
    int length;
    int width;
    std::string text;
    //this is all the child nodes in the tree, a vector would also work just fine
    std::vector<FileNode*> children;

    //this tells the draw function whether or not to show the node's children
    //this is done by toggling a state on and off
    void toggleChlidren();

    //this is called in the draw function to reposition the children so they
    //are indented and below the parent
    void reposition() const;
public:
    // this is so I can use the iterator for the children map publicly
    typedef typename std::map<std::string, FileNode*>::iterator iterator;
    FileNode(std::string text, int x, int y, int length, int width);

    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //This is not currently used
//    virtual void applySnapshot(const Snapshot& snapshot);

    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //does nothing now
    void update();
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem* &getData();
    void setData(const FileItem* &data);
    vector<FileNode*>& getChildren();

    void addChild(std::string string1);
    //iterators
    iterator begin();
    iterator end();

};


#endif //PROJECT_FILENODE_H
