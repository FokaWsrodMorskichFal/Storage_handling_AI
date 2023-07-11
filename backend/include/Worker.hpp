#pragma once

#include "NeuralNetwork.hpp"
#include "WorkerInput.hpp"
#include "WorkerOutput.hpp"

class Worker {
    NeuralNetwork neuralNetwork;
public:
    WorkerOutput makeAction(const WorkerInput&) const;
};