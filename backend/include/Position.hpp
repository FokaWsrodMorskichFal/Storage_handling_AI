#pragma once

struct Position {
    double x;
    double y;
    double distance(const Position&) const; 

    Position(double x=.0, double y=.0) : x(x), y(y) {}
};