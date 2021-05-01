//
// Created by Nicolas Cuenca on 4/5/2021.
//

#include "Snapshot.h"



Snapshot::Snapshot(vector<Letter *> vec, int cursor_x, int cursor_y){
    this->vec = vec;
    this->cursor_x = cursor_x;
    this->cursor_y = cursor_y;
}

vector<Letter *> Snapshot::getVec() {
    return vec;
}

int Snapshot::getCursorX() const {
    return cursor_x;
}

int Snapshot::getCursorY() const {
    return cursor_y;
}

Snapshot::Snapshot() {

}
