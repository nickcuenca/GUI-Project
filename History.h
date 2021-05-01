//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_HISTORY_H
#define PROJECT_HISTORY_H


#include "Snapshot.h"
#include "Stack.h"
class History {

public:
    History();
    int size();
    Snapshot * top();
    void pop();

    void push(Snapshot *pSnapshot);

private:
    Stack<Snapshot *> *history;
};


#endif //PROJECT_HISTORY_H
