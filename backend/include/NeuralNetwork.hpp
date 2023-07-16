#pragma once

#include "WorkerOutput.hpp"
#include "WorkerInput.hpp"

#include <Eigen/Core>
#include <vector>

class NeuralNetwork {
    std::vector<Eigen::MatrixXd> layers;
public:
    NeuralNetwork();
    NeuralNetwork(std::vector<int>);

    /**
     * @brief Evaluates one pass of input vector through all layers.
     * 
     * @return WorkerOutput - NN output vector represented as WorkerOutput instance
     */
    WorkerOutput evaluate(const WorkerInput&) const;
};