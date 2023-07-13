#pragma once

#include "Population.hpp"
#include "RuntimeStatistics.hpp"

class Simulator {
    double calculateFitness(const RuntimeStatistics&) const;
public:
    double BoxWorkerDist(Worker&, Box&) const;
    void simulate(Population&) const;
};