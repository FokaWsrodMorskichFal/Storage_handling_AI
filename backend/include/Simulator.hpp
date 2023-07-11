#pragma once

#include "Population.hpp"
#include "SimulatorParameters.hpp"
#include "RuntimeStatistics.hpp"

class Simulator {
    double calculateFitness(const RuntimeStatistics&) const;
public:
    void simulate(const SimulatorParameters&, Population&) const;
};