//
// Created by Nicolas Cuenca on 4/5/2021.
//

#ifndef PROJECT_SNAPSHOT_H
#define PROJECT_SNAPSHOT_H

#include <string>
#include "Letter.h"

using namespace std;
class Snapshot {
private:
    vector<Letter *> vec;
    int cursor_x;
    int cursor_y;
public:
    Snapshot();
    Snapshot(vector<Letter *> vec, int cursor_x, int cursor_y);
    vector<Letter *> getVec();
    int getCursorX() const;
    int getCursorY() const;
};


#endif //PROJECT_SNAPSHOT_H
