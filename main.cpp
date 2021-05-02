#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextInput.h"
#include "InputBox.h"
#include "DropdownMenu.h"
int main() {
    int count = 0;
    sf::RenderWindow  window({1920, 1080, 32},"TYPE IT NOW!");
    TextInput textInput(100, 100, 100, 1500);
    InputBox *inputBox = new InputBox(10, 550, 100, 300, "MIlK");
    std::vector<std::string> names = {"BANANA", "COOKIES", "OREOS", "EGGS"};
    DropdownMenu dropdownMenu(inputBox, names);
    window.setKeyRepeatEnabled(false);
    bool blink = true;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
              textInput.getTyping()->addEventHandler(window, event);
             textInput.addEventHandler(window, event);
             textInput.getTyping()->setBlink();
             dropdownMenu.addEventHandler(window, event);
        }


        window.clear();
        window.draw(textInput);
        window.draw(dropdownMenu);
        window.display();
    }
    return 0;
}
