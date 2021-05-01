//
// Created by Nicolas Cuenca on 4/5/2021.
//

#include "States.h"

States::States() {
    for (int i = 0; i < LASTSTATE; i++) {
        states[static_cast<ObjectStates>(i)] = false;
    }
}

bool States::isStateEnable(ObjectStates state) {
    if (states.count(state) > 0)
        return states[state];
    return false;
}

void States::enableState(ObjectStates state) {
    states[state] = true;
}

void States::disableState(ObjectStates state) {
    states[state] = false;
}

