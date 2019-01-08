//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_POINT_H
#define MILESTONE2_POINT_H

#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y);
    int getX() const;
    int getY() const;
    bool operator==(Point other);
    string to_string();
};


#endif //MILESTONE2_POINT_H
