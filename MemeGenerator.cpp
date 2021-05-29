//
// Created by Nicolas Cuenca on 5/28/2021.
//
#ifndef PROJECT_MEMEGENERATOR_CPP
#define PROJECT_MEMEGENERATOR_CPP
#include "MemeGenerator.h"

MemeGenerator::MemeGenerator() {
    Slider* slider1a  = new Slider(275, 860, 200, "Top text opacity: ");
    Slider* slider1b = new Slider(275, 930, 200, "Top text X-Axis: ");
    Slider* slider1c = new Slider(275, 1000, 200, "Top text Y-Axis: ");
    Slider* slider2a = new Slider (775, 860, 200, "Top text opacity: ");
    Slider* slider2b = new Slider(775, 930, 200, "Top text X-Axis: ");
    Slider* slider2c = new Slider (775, 1000, 200, "Top text Y-Axis: ");
    Slider* slider3a= new Slider (1275, 860, 200, "MEME SKEWER: ");
    Slider* slider3b = new Slider (1275, 930, 200, "MEME OPACITY: ");
    Slider* slider3c = new Slider (1275, 1000, 200, "MEME DEEPFRYER: ");
    vectorOfSliders.push_back(slider1a);
    vectorOfSliders.push_back(slider1b);
    vectorOfSliders.push_back(slider1c);
    vectorOfSliders.push_back(slider2a);
    vectorOfSliders.push_back(slider2b);
    vectorOfSliders.push_back(slider2c);
    vectorOfSliders.push_back(slider3a);
    vectorOfSliders.push_back(slider3b);
    vectorOfSliders.push_back(slider3c);
    std::vector<std::string> names = {"New meme", "Open meme", "Delete meme"};
    std::vector<std::string> names2 = {"Black", "Blue", "Green"};
    std::vector<std::string> names3 = {"Extra 1", "Extra 2", "Extra 3"};

    std::vector<std::vector<std::string>> allItems;
    std::vector<std::string> inputboxNames = {"File", "Red", "Extras"};
    allItems.push_back(names);
    allItems.push_back(names2);
    allItems.push_back(names3);

    background = new Background();
    cout << "HIIII" << endl;

    menu1 = new Menu(allItems, 2, 2, 50, 150, inputboxNames);

    memeTyping = new MemeTyping(sf::Color::Red);

    FileNode *fileNode  = new FileNode("Meme Templates", 10, 50, 130, 500);
    fileNode->addChild("2012 Memes");
    fileTree = new FileTree(fileNode, background->getMemeRectangle());
    //fileNode->addChild("Cats");
    fileTree->push("2012 Memes", "Bad Luck Brian");
    fileTree->push("2012 Memes", "Good Guy Greg");
   // fileTree->push("Cats", "cat 1");
    show_file_tree = false;

}


void MemeGenerator::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*background);
    for (int i = 0; i < 9; i++) {
        window.draw(*vectorOfSliders[i]);
    }
    window.draw(*menu1->getMenuBar());
    window.draw(*memeTyping);
    if(show_file_tree){
        window.draw(*fileTree);
    }
}


void MemeGenerator::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for (int i = 0; i < 9; i++) {
        vectorOfSliders[i]->addEventHandler(window, event);
    }
    menu1->getMenuBar()->addEventHandler(window, event);
    memeTyping->addEventHandler(window, event);
    vector<std::string> choices = menu1->getChoices();

    if(choices[1].compare("Red") == 0) {
        memeTyping->setColor(sf::Color::Red);
    } else if(choices[1].compare("Black") == 0) {
        memeTyping->setColor(sf::Color::Black);
    } else if(choices[1].compare("Blue") == 0){
        memeTyping->setColor(sf::Color::Blue);
    } else {
        memeTyping->setColor(sf::Color::Green);
    }

    show_file_tree = choices[0].compare("Open meme") == 0;
    if(show_file_tree){
        fileTree->addEventHandler(window, event);
    }

    if(FileItem::background.compare("Bad Luck Brain") == 0){
        if(!texture.loadFromFile("badluckbrian.jpg")){
            cout << "Failed to load " << endl;
        }
        background->getMemeRectangle()->setTexture(&texture);
    }

}

void MemeGenerator::update() {

}
//#include "MemeGenerator.cpp"
#endif //PROJECT_MEMEGENERATOR_H

