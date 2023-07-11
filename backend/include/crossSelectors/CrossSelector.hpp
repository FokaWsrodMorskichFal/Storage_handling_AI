#pragma once

#include "Population.hpp"

class CrossSelector {
public:
    virtual Population chooseForCrossing(const Population&) const = 0;
};