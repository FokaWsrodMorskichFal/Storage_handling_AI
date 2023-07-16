#include "NeuralNetwork.hpp"

#include <cmath>

using namespace Eigen;

NeuralNetwork::NeuralNetwork() {}

NeuralNetwork::NeuralNetwork(std::vector<int> hiddenLayerSizes) {
    int layerCols = WorkerInput::inputSize();
    for (auto& layerSize : hiddenLayerSizes) {
        layers.push_back(MatrixXd::Random(layerSize, layerCols));
        layerCols = layerSize;
    }
    layers.push_back(MatrixXd::Random(WorkerOutput::outputCount(), layerCols));
}

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