//
// Created by Nicolas Cuenca on 5/7/2021.
//

#include "MenuHistory.h"
MenuHistory::MenuHistory() {
    history = new Stack<MenuSnapshot *>();
}

int MenuHistory::size() {
    return history->size();
}

void MenuHistory::pop() {
    history->pop();
}

MenuSnapshot * MenuHistory::top(){
    return history->top();
}

void MenuHistory::push(MenuSnapshot *pSnapshot) {
    history->push(pSnapshot);
}

