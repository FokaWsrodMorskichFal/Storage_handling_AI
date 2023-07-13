#include "Box.hpp"

Box::Box(double x, double y, int color) : x(x), y(y), color(color), isHeld(false) {
    static int lastId = 0;
    id = lastId;
    lastId++;
}

void Box::setPos(double x, double y) {
    this->x = x;
    this->y = y;
}

void Box::setColor(int color) {
    this->color = color;
}

#include <iostream>
Box::~Box() {
    std::cout << "I got deleted! [" << id << "]\n";
}
