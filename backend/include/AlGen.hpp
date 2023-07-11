#pragma once

#include "Specimen.hpp"
#include "Simulator.hpp"
#include "Population.hpp"
#include "CrossSelector.hpp"
#include "Crosser.hpp"
#include "Mutator.hpp"

#include <memory>

class AlGen {
    Population population;
    Simulator simulator;
    std::shared_ptr<CrossSelector> crossSelector;
    std::shared_ptr<Crosser> crosser;
    std::shared_ptr<Mutator> mutator;
public:

};