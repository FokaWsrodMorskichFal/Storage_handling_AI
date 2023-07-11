#pragma once

#include "Population.hpp"

#include <vector>

class Mutator {
public:
    virtual Population mutate(const Population&) const = 0;
};