//
// Created by Nicolas Cuenca on 5/24/2021.
//

#ifndef PROJECT_BACKGROUND_H
#define PROJECT_BACKGROUND_H
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

class Background : public sf::Drawable {
private:
    sf::Texture backgroundTexture, rageComics;
    sf::Sprite sprite, sprite2;
    sf::Font globalFont;
    sf::Text commandCenter, topCaption, botCaption, memeGenerator;
    sf::SoundBuffer buffer;
    sf::Sound song;
    sf::Texture texture;
    sf::RectangleShape commandCenterRectangle;
    sf::RectangleShape memeRectangle;

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
    void setRotationRectangle(float angle);
    void setMemeRectangle(std::string imgName);

    void eraseMeme();
    sf::RectangleShape *getMemeRectangle();
};


#endif //PROJECT_BACKGROUND_H
