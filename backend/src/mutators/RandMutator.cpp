#include "RandMutator.hpp"
#include "RNG.hpp"

#include <iostream>     //XD kryzysik

using namespace std;

Population RandMutator::mutate(const Population& population) const {
    Population mutatedPops;
    for(auto pop : population){
        array<NeuralNetwork, Parameters::N_WORKERS> NNs = pop.getNNs();
        for(auto& NN : NNs){
            std::vector<Eigen::MatrixXd> layers = NN.getLayers();
            for(auto& layer : layers){
                int r = layer.rows();
                int c = layer.cols();
                for(int i=0;i<r;i++){
                    for(int j=0;j<c;j++){
                        if((RNG::uniformRandom(.0, 1.0))<MUT_PROB){
                            if((RNG::uniformRandom(-1.0, 1.0))<0){
                                layer(i, j) = layer(i, j) - MUT_INFLU;
                            }else{
                                layer(i, j) = layer(i, j) + MUT_INFLU;
                            } 
                        }
                    }
                }
            }
            NN = NeuralNetwork(layers);
        }
        mutatedPops.push_back(Specimen(NNs));
    }
    return mutatedPops;
}
