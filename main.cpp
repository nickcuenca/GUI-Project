#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextInput.h"
#include "InputBox.h"
#include "DropdownMenu.h"
#include "Menu.h"
int main() {
    int count = 0;
    sf::RenderWindow  window({1920, 1080, 32},"TYPE IT NOW!");
    TextInput textInput(100, 100, 100, 1500);
    InputBox *inputBox = new InputBox(10, 550, 100, 300, "MIlK");
    InputBox *inputBox2 = new InputBox(310, 550, 100, 300, "EAGLE");
    InputBox *inputBox3 = new InputBox(610, 550, 100, 300, "SHAZAM");

    std::vector<std::string> names = {"BANANA", "COOKIES", "OREOS", "EGGS"};
    std::vector<std::string> names2 = {"MONKEY", "ELEPHANT", "LION", "BAT"};
    std::vector<std::string> names3 = {"SUPERMAN", "BATMAN", "CYBORG", "FLASH"};


    std::vector<std::vector<std::string>> allItems;
    std::vector<std::string> inputboxNames = {"MILK", "EAGLE", "SHAZAM"};
    allItems.push_back(names);
    allItems.push_back(names2);
    allItems.push_back(names3);


    Menu menu1(allItems, 10, 350, 130, 300, inputboxNames);


    window.setKeyRepeatEnabled(false);
    bool blink = true;
    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            textInput.getTyping()->addEventHandler(window, event);
            textInput.addEventHandler(window, event);
            textInput.getTyping()->setBlink();
            menu1.getMenuBar()->addEventHandler(window, event);
        }


        window.clear();
        window.draw(textInput);
        window.draw(*menu1.getMenuBar());
        window.display();
    }

    return 0;
}
