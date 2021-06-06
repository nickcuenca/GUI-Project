//
// Created by Nicolas Cuenca on 5/28/2021.
//

#ifndef PROJECT_MEMEGENERATOR_H
#define PROJECT_MEMEGENERATOR_H
#include "Slider.h"
#include "Background.h"
#include "InputBox.h"
#include "Menu.h"
#include "GUI_components.h"
#include "TextInput.h"
#include "FileTree.h"
#include "MemeTyping.h"


class MemeGenerator : public GUI_components {
private:
    std::vector<Slider*> vectorOfSliders;
    Background *background;
    Menu* menu1;
    MemeTyping* memeTyping;
    FileTree* fileTree;
    bool show_file_tree;
    sf::Texture texture;

public:
    MemeGenerator();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};



#endif //PROJECT_MEMEGENERATOR_H
