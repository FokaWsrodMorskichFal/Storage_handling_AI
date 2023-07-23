#include "ExchangeCrosser.hpp"
#include "Parameters.hpp"
#include "RNG.hpp"

Specimen cross2Parents(const Specimen& a, const Specimen& b){
    std::array<NeuralNetwork, Parameters::N_WORKERS> aNNs = a.getNNs();
    std::array<NeuralNetwork, Parameters::N_WORKERS> bNNs = b.getNNs();
    std::array<bool, Parameters::N_WORKERS> mask = {false};
    int counter = Parameters::N_WORKERS / 2;
    int index;
    while(counter){
        index=RNG::uniformRandom(0, Parameters::N_WORKERS-1);
        if(!mask[index]){
            mask[index] = true;
            counter--;
        }
    }
    for(int i=0;i<Parameters::N_WORKERS;i++){
        if(mask[i]){
            aNNs[i] = bNNs[i];
        }
    }
    return Specimen(aNNs);
}

Population ExchangeCrosser::cross(const Population& parents) const {
    Population kids;
    int numberOfParents = parents.size();
    int a, b;
    while(kids.size()<Parameters::POPULATION_SIZE - numberOfParents){
        a=RNG::uniformRandom(0, numberOfParents-1);
        b=RNG::uniformRandom(0, numberOfParents-1);
        kids.push_back(cross2Parents(parents[a], parents[b]));
    }
    return kids; 
}