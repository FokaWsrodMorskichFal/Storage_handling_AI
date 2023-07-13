#include "NeuralNetwork.hpp"

#include <cmath>

using namespace Eigen;

NeuralNetwork::NeuralNetwork() {
    int l1NodeCount = 10;
    int l2NodeCount = 10;
    MatrixXd l1 = MatrixXd::Random(l1NodeCount, WorkerInput::inputSize());
    MatrixXd l2 = MatrixXd::Random(l2NodeCount, l1NodeCount);
    MatrixXd l3 = MatrixXd::Random(WorkerOutput::outputCount(), l2NodeCount);
    layers = {l1, l2, l3};
}

NeuralNetwork::NeuralNetwork(std::vector<Eigen::MatrixXd> layers)
: layers(layers) {}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

WorkerOutput NeuralNetwork::evaluate(const WorkerInput& workerInput) const {
    VectorXd res;
    res = workerInput.toVector();
    for (const auto& layer : layers) {
        res = (layer * res).unaryExpr(&sigmoid);
    }
    return WorkerOutput::fromVector(res);
}