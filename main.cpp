#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextInput.h"
int main() {
    int count = 0;
    sf::RenderWindow window({1920, 1080, 32}, "TYPE IT NOW!");
    TextInput textInput(100, 100, 100, 1500);
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
        }


        window.clear();
        window.draw(textInput);
        window.display();
    }
    return 0;
}
