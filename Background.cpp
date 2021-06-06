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

    rageComics.loadFromFile("reject.png");
    sprite2.setTexture(rageComics);

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
    window.draw(memeRectangle);
    window.draw(topCaption);
    window.draw(botCaption);
    window.draw(memeGenerator);
    window.draw(sprite2);

}

void Background::playSong() {
    song.play();
    song.setVolume(2.f);
    song.setLoop(true);
}

void Background::setRec() {
    commandCenterRectangle.setSize(sf::Vector2f(1840, 350));
    commandCenterRectangle.setPosition(40, 690);
    commandCenterRectangle.setFillColor(sf::Color(0,0,0,100));

    memeRectangle.setSize(sf::Vector2f(900, 600));
    memeRectangle.setPosition(400, 70);

    sprite2.setPosition(sf::Vector2f{1485, 700});
    sprite2.setScale(sf::Vector2f{0.3, 0.3});
}

void Background::setCC() {
    commandCenter.setFont(globalFont);
    commandCenter.setString("Command Center");
    commandCenter.setCharacterSize(40);
    commandCenter.setPosition((1840/2 - 130), 700);
    commandCenter.setFillColor(sf::Color::White);

    topCaption.setFont(globalFont);
    topCaption.setString("Top Caption:");
    topCaption.setCharacterSize(40);
    topCaption.setPosition(1400, 135);
    topCaption.setFillColor(sf::Color::White);

    botCaption.setFont(globalFont);
    botCaption.setString("Bottom Caption:");
    botCaption.setCharacterSize(40);
    botCaption.setPosition(1400, 390);
    botCaption.setFillColor(sf::Color::White);

    memeGenerator.setFont(globalFont);
    memeGenerator.setString("Welcome to\n MEME\n  GENERATOR!!!");
    memeGenerator.setCharacterSize(40);
    memeGenerator.setPosition(20, 500);
    memeGenerator.setFillColor(sf::Color::White);
}

void Background::setMemeRectangle(std::string imgName)  {\
    memeRectangle.setSize(sf::Vector2f(900, 600));
    memeRectangle.setPosition(400, 70);
    if(imgName.compare("Bad Luck Brian") == 0) {
        if(!texture.loadFromFile("badluckbrian.jpg")){
            std::cout << "Cannot load file" << std::endl;
        }
        memeRectangle.setTexture(&texture);
    } else if(imgName.compare("Good Guy Greg") == 0) {
        if(!texture.loadFromFile("goodguygreg.jpg")){
            std::cout << "Cannot load file" << std::endl;
        }
        memeRectangle.setTexture(&texture);
    } else if(imgName.compare("Grumpy Cat") == 0) {
        if(!texture.loadFromFile("grumpycat.jpg")){
            std::cout << "Cannot load file" << std::endl;
        }
        memeRectangle.setTexture(&texture);
    } else if(imgName.compare("Heavy Breathing Cat") == 0) {
        if(!texture.loadFromFile("heavybreathingcat.jpg")){
            std::cout << "Cannot load file" << std::endl;
        }
        memeRectangle.setTexture(&texture);
    } else if(imgName.compare("Scumbag Steve") == 0) {
        if(!texture.loadFromFile("scumbagsteve.jpg")){
            std::cout << "Cannot load file" << std::endl;
        }
        memeRectangle.setTexture(&texture);
    } else if(imgName.compare("Hide The Pain Harold") == 0) {
        if(!texture.loadFromFile("hidethepainharold.jpg")){
            std::cout << "Cannot load file" << std::endl;
        }
        memeRectangle.setTexture(&texture);
    } else if(imgName.compare("Scared Cat") == 0) {
        if(!texture.loadFromFile("scaredcat.jpg")){
            std::cout << "Cannot load file" << std::endl;
        }
        memeRectangle.setTexture(&texture);
    } else if(imgName.compare("Ancient Aliens Guy") == 0) {
        if(!texture.loadFromFile("ancientaliensguy.jpg")){
            std::cout << "Cannot load file" << std::endl;
        }
        memeRectangle.setTexture(&texture);
    } else if(imgName.compare("Sad Monkey") == 0) {
        if(!texture.loadFromFile("sadmonkey.jpg")){
            std::cout << "Cannot load file" << std::endl;
        }
        memeRectangle.setTexture(&texture);
    }


}

void Background::setRotationRectangle(float angle) {
    memeRectangle.setRotation(angle);

}

void Background::eraseMeme(){
    memeRectangle.setTexture(NULL);
}


