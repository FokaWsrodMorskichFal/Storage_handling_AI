#pragma once

#include "Population.hpp"

#include <vector>

class Crosser {
public:
    virtual Population cross(const Population&) const = 0;
};