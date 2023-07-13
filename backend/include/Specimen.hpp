#pragma once

#include "Worker.hpp"
#include "Parameters.hpp"

#include <array>

class Specimen {
    double fitness;
    std::array<Worker, Parameters::N_WORKERS> workers;
public:
    Specimen();
    void setFitness(double fitness);
    std::array<Worker, Parameters::N_WORKERS>& getWorkers() { return workers; };
    inline bool operator<(const Specimen& rhs) const { return fitness > rhs.fitness; };
};