//
// Created by Nicolas Cuenca on 5/14/2021.
//

#ifndef PROJECT_FILETREE_H
#define PROJECT_FILETREE_H
#include "GUI_components.h"
#include "FileNode.h"

//This is a N-Ary tree that links FileNodes together.
class FileTree : public GUI_components{
private:
    //the root node of the tree
    FileNode* root;
    sf::RectangleShape *img;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item);

    void updateY(FileNode* &curr, int &offset);

    //traverses the tree ad adds the evenhandlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
public:
    //constructors
    FileTree();
    FileTree(FileNode* root, sf::RectangleShape *img);


    //this is the public version of push
    void push(std::string parent, std::string item = "NULL");

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //does nothing now
    virtual void applySnapshot(const Snapshot& snapshot);

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
//    //does nothing now
//    virtual Snapshot& getSnapshot();
//    //does nothing now
//    virtual sf::FloatRect getGlobalBounds();

    void updateY();
    void traverseDraw(FileNode *root, sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //PROJECT_FILETREE_H
