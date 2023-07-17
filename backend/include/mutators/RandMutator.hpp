#pragma once

#include "Population.hpp"
#include "Mutator.hpp"

#include <vector>

const double MUT_PROB = 0.5;   //probability that single weight gets changed
const double MUT_INFLU = 111;

class RandMutator : public Mutator {
public:
    Population mutate(const Population&) const override;
};