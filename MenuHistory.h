//
// Created by Nicolas Cuenca on 5/7/2021.
//

#ifndef PROJECT_MENUHISTORY_H
#define PROJECT_MENUHISTORY_H
#include "MenuHistory.h"
#include "MenuSnapshot.h"
#include "Stack.h"
class MenuHistory {
public:
    MenuHistory();
    int size();
    MenuSnapshot* top();
    void pop();
    void push(MenuSnapshot* pSnapshot);

private:
    Stack<MenuSnapshot*> *history;
};


#endif //PROJECT_MENUHISTORY_H
