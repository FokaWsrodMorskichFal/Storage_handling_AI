#include "RandMutator.hpp"
#include "RNG.hpp"

#include <algorithm>

using namespace std;

double tryMutate(double x) {
    if (RNG::testEvent(MUT_PROB)) {
        return clamp(x + (RNG::testEvent(0.5) ? -1 : 1) * MUT_INFLU, -1., 1.);
    }
    return x;
}

Population RandMutator::mutate(const Population& population) const {
    Population mutatedPops;
    for(auto& pop : population){
        array<NeuralNetwork, Parameters::N_WORKERS> NNs = pop.getNNs();
        for(auto& NN : NNs){
            std::vector<Eigen::MatrixXd>& layers = NN.getLayers();
            for(auto& layer : layers){
                layer = layer.unaryExpr(&tryMutate);
            }
        }
        mutatedPops.push_back(Specimen(NNs));
    }
    return mutatedPops;
}