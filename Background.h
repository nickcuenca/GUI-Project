//
// Created by Nicolas Cuenca on 5/24/2021.
//

#ifndef PROJECT_BACKGROUND_H
#define PROJECT_BACKGROUND_H
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

class Background : public sf::Drawable {
private:
    sf::Texture picOfLayout, backgroundTexture, enterButtonTexture, bananaTexture;
    sf::Sprite sprite, banana;
    sf::Font globalFont;
    sf::Text commandCenter;
    sf::RectangleShape portrait, enterButton;
    sf::SoundBuffer buffer;
    sf::Sound song;

    sf::RectangleShape commandCenterRectangle;
    sf::RectangleShape *memeRectangle;
public:
    sf::RectangleShape *getMemeRectangle();

public:
    Background();
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    //Precondition: A splash screen object is created
    //Postcondition: Splash Screen can now be drawn on screen.
    void playSong();
    //Precondition: A Song object is created.
    //Postcondition: A Song is now setup.
    void setRec();
    void setCC();
};


#endif //PROJECT_BACKGROUND_H
