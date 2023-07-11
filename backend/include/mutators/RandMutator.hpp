#pragma once

#include "Population.hpp"
#include "Mutator.hpp"

#include <vector>

class RandMutator : public Mutator {
public:
    Population mutate(const Population&) const override;
};