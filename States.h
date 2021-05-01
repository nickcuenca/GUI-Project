//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_STATES_H
#define PROJECT_STATES_H

#include <map>

enum ObjectStates{
    HIDDEN, ENABLED, BLINKING, HIGHLIGHTED,
//make all the classes a child of the state

    //blinking is for cursor
    LASTSTATE
};
class States {
private:
    std::map<ObjectStates, bool> states;
public:
    States();
    bool isStateEnable(ObjectStates state);
    void enableState(ObjectStates state);
    void disableState(ObjectStates state);


};


#endif //PROJECT_STATES_H
