//
// Created by Nicolas Cuenca on 5/24/2021.
//

#include "Background.h"

Background::Background() {
    backgroundTexture.loadFromFile("bsfun.jpg");
    sprite.setTexture(backgroundTexture);
    buffer.loadFromFile("sax.wav");
    song.setBuffer(buffer);
    playSong();
}

void Background::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(sprite);
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


