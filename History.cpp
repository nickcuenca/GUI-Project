//
// Created by Nicolas Cuenca on 4/5/2021.
//

#include "History.h"


History::History() {
    history = new Stack<Snapshot *>();
}

int History::size() {
    return history->size();
}

void History::pop() {
    history->pop();
}

Snapshot * History::top(){
    return history->top();
}

void History::push(Snapshot *pSnapshot) {
    history->push(pSnapshot);
}


