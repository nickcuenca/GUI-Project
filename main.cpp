#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextInput.h"
#include "InputBox.h"
#include "FileTree.h"
#include "Background.h"
#include "Slider.h"

int main() {
    int count = 0;
    Background background;
    sf::RenderWindow  window({1920, 1080, 32},"TYPE IT NOW!");
    TextInput textInput(100, 100, 100, 1500);
    Slider slider1(200, 200, 200, "Set opacity: ");
//    InputBox *inputBox = new InputBox(10, 550, 100, 300, "MIlK");
//    InputBox *inputBox2 = new InputBox(310, 550, 100, 300, "EAGLE");
//    InputBox *inputBox3 = new InputBox(610, 550, 100, 300, "SHAZAM");
//
//    std::vector<std::string> names = {"BANANA", "COOKIES", "OREOS", "EGGS"};
//    std::vector<std::string> names2 = {"MONKEY", "ELEPHANT", "LION", "BAT"};
//    std::vector<std::string> names3 = {"SUPERMAN", "BATMAN", "CYBORG", "FLASH"};
//
//
//
//    std::vector<std::vector<std::string>> allItems;
//    std::vector<std::string> inputboxNames = {"MILK", "EAGLE", "SHAZAM"};
//    allItems.push_back(names);
//    allItems.push_back(names2);
//    allItems.push_back(names3);
//
//
//    Menu menu1(allItems, 10, 350, 130, 300, inputboxNames);



    FileNode *fileNode  = new FileNode("Directory 1", 10, 50, 130, 500);
    fileNode->addChild("File 1");
    fileNode->addChild("Directory 2");
    FileTree *fileTree = new FileTree(fileNode);
    fileTree->push("Directory 2", "File 3");
    fileTree->push("Directory 2", "File 4");
    fileNode->addChild("File 2");


    window.setKeyRepeatEnabled(false);
    bool blink = true;
    
    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
//            textInput.getTyping()->addEventHandler(window, event);
//            textInput.addEventHandler(window, event);
//            textInput.getTyping()->setBlink();
////            menu1.getMenuBar()->addEventHandler(window, event);
            fileTree->addEventHandler(window, event);
            fileTree->updateY();
        }

        
        window.clear();
//        window.draw(background);
//        window.draw(textInput);
//        window.draw(*fileTree);
        window.draw(slider1);
//        window.draw(*menu1.getMenuBar());
        window.display();
    }

    return 0;
}
