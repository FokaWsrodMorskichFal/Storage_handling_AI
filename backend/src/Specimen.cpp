#include "Specimen.hpp"

Specimen::Specimen() : fitness(0) {}

Specimen::Specimen(const std::array<NeuralNetwork, Parameters::N_WORKERS>& NNs){
    fitness=0;
    neuralNetworks = NNs;
}

void Specimen::setFitness(double fitness) {
    this->fitness = fitness;
}