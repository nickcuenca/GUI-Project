//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_GUI_COMPONENTS_H
#define PROJECT_GUI_COMPONENTS_H
//records sat
#include "SFML/Graphics.hpp"
#include "EventHandler.h"
//#include "SnapshotInterface.h"
#include "Snapshot.h"

class GUI_components : public sf::Drawable, public EventHandler, public sf::Transformable{
//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
   // virtual Snapshot& getSnapshot() = 0;
   // virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //PROJECT_GUI_COMPONENTS_H
