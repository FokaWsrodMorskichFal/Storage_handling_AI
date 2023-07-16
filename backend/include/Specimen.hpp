#pragma once

#include "NeuralNetwork.hpp"
#include "Parameters.hpp"

#include <array>

class Specimen {
    double fitness;
    std::array<NeuralNetwork, Parameters::N_WORKERS> neuralNetworks;
public:
    Specimen();
    void setFitness(double fitness);
    const std::array<NeuralNetwork, Parameters::N_WORKERS>& getNNs() const { return neuralNetworks; };
    inline bool operator<(const Specimen& rhs) const { return fitness > rhs.fitness; };
};