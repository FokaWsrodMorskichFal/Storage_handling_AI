#pragma once

#include "NeuralNetwork.hpp"
#include "Parameters.hpp"

#include <array>

class Specimen {
public: // delete this line
    double fitness;
    std::array<NeuralNetwork, Parameters::N_WORKERS> neuralNetworks;
public:
    Specimen();
    Specimen(const std::array<NeuralNetwork, Parameters::N_WORKERS>&);
    void setFitness(double fitness);
    const std::array<NeuralNetwork, Parameters::N_WORKERS>& getNNs() const { return neuralNetworks; };
    inline bool operator<(const Specimen& rhs) const { return fitness > rhs.fitness; };
};