#pragma once

#include "Specimen.hpp"

#include <vector>

class Crosser {
public:
    virtual std::vector<Specimen> cross(const std::vector<Specimen>&) const = 0;
};