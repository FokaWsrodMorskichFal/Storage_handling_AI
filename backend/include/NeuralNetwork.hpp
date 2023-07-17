#pragma once

#include "WorkerOutput.hpp"
#include "WorkerInput.hpp"

#include <Eigen/Core>
#include <vector>

class NeuralNetwork {
public: // delete this line
    std::vector<Eigen::MatrixXd> layers;
public:
    NeuralNetwork();
    NeuralNetwork(std::vector<int>);
    NeuralNetwork(const std::vector<Eigen::MatrixXd>&);

    /**
     * @brief Evaluates one pass of input vector through all layers.
     * 
     * @return WorkerOutput - NN output vector represented as WorkerOutput instance
     */
    WorkerOutput evaluate(const WorkerInput&) const;
    std::vector<Eigen::MatrixXd>& getLayers() { return layers; };
};