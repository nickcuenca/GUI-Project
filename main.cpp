#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextInput.h"
#include "InputBox.h"
#include "FileTree.h"
#include "Background.h"
#include "Slider.h"
#include "Menu.h"
#include "MemeGenerator.h"


int main() {
    int count = 0;
    sf::RenderWindow  window({1920, 1080, 32},"MonkeMemenator v. 69420");
    window.setFramerateLimit(60);

    MemeGenerator memeGenerator;

    sf::Texture* texture;
    if(!texture->loadFromFile("badluckbrian.jpg")){
        cout << "Failed to load " << endl;
    }

    sf::RectangleShape rectangleShape;
    rectangleShape.setTexture(texture);
    rectangleShape.setSize(sf::Vector2f{500, 400});
    rectangleShape.setPosition(600, 200);

    std::vector<std::string> names = {"New meme", "Open meme", "Save meme", "Close meme"};
    std::vector<std::string> names2 = {"Red", "Black", "Blue", "Green"};
    std::vector<std::string> names3 = {"Extra 1", "Extra 2", "Extra 3"};



//    FileNode *fileNode  = new FileNode("Directory 1", 10, 50, 130, 500);
//    fileNode->addChild("File 1");
//    fileNode->addChild("Directory 2");
//    FileTree *fileTree = new FileTree(fileNode);
//    fileTree->push("Directory 2", "File 3");
//    fileTree->push("Directory 2", "File 4");
//    fileNode->addChild("File 2");


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

//            menu1.getMenuBar()->addEventHandler(window, event);

//            fileTree->addEventHandler(window, event);
//            fileTree->updateY();

            memeGenerator.addEventHandler(window, event);

        }

        
        window.clear();
        window.draw(memeGenerator);
//        window.draw(rectangleShape);


        window.display();
    }

    return 0;
}
