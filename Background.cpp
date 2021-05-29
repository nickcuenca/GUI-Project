//
// Created by Nicolas Cuenca on 5/24/2021.
//

#include <iostream>
#include "Background.h"

Background::Background() {

    globalFont.loadFromFile("OpenSans-Bold.ttf");
    if (!globalFont.loadFromFile( "OpenSans-Bold.ttf")) {
        std::cout << "Could not load font." << std::endl;
        return;
    }

    backgroundTexture.loadFromFile("bsfun.jpg");
    sprite.setTexture(backgroundTexture);
    setCC();
    setRec();
    buffer.loadFromFile("sax.wav");
    song.setBuffer(buffer);
    playSong();
}

void Background::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(sprite);
    window.draw(commandCenterRectangle);
    window.draw(commandCenter);
    window.draw(*memeRectangle);

//    window.draw(banana);
//    window.draw(name);
//    window.draw(className);
//    window.draw(crn);
//    window.draw(semester);
//    window.draw(portrait);
//    window.draw(descriptionOfGame);
//    window.draw(enterButton);
//    window.draw(enterGameString);
//    window.draw(directions);
//    window.draw(funky);
}

void Background::playSong() {
    song.play();
    song.setVolume(35.f);
    song.setLoop(true);
}

void Background::setRec() {
    commandCenterRectangle.setSize(sf::Vector2f(1840, 350));
    commandCenterRectangle.setPosition(40, 690);
    commandCenterRectangle.setFillColor(sf::Color(0,0,0,100));
    memeRectangle = new sf::RectangleShape();

    memeRectangle->setSize(sf::Vector2f(900, 600));
    memeRectangle->setPosition(400, 70);
    memeRectangle->setFillColor(sf::Color(0,0,0,100));
}

void Background::setCC() {
    commandCenter.setFont(globalFont);
    commandCenter.setString("Command Center");
    commandCenter.setCharacterSize(40);
    commandCenter.setPosition((1840/2 - 130), 700);
    commandCenter.setFillColor(sf::Color::White);
}

sf::RectangleShape *Background::getMemeRectangle()  {
    return memeRectangle;
}


