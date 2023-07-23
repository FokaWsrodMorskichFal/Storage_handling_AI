#pragma once

#include "Population.hpp"
#include "CrossSelector.hpp"
#include "Crosser.hpp"
#include "Mutator.hpp"

#include <memory>

class AlGen {
    Population population;
    std::shared_ptr<CrossSelector> crossSelector;
    std::shared_ptr<Crosser> crosser;
    std::shared_ptr<Mutator> mutator;
public:
    AlGen(std::shared_ptr<CrossSelector>, std::shared_ptr<Crosser>, std::shared_ptr<Mutator>);
    void nextEpoch();
};