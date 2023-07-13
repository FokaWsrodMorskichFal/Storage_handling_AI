#pragma once

class Box {
    int id;
    double x;
    double y;
    int color;
    bool isHeld;
public:
    Box(double=0., double=0., int=0);
    double getX() const { return x; };
    double getY() const { return y; };
    int getColor() const { return color; };
    bool checkIfHeld() const { return isHeld; };
    void setPos(double, double);
    void setColor(int);
    void setHeld() { isHeld = true; };
    void setDropped() { isHeld = false; };
    inline bool operator==(const Box& rhs) const { return id == rhs.id; };
    ~Box();
};