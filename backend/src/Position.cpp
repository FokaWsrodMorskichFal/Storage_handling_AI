#include "Position.hpp"

#include <cmath>

double Position::distance(const Position& other) const {
    return sqrt(pow(x - other.x, 2.) + pow(y - other.y, 2.));
}
