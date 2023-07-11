#include "WorkerInput.hpp"
#include "NeuralNetwork.hpp"

#include <Eigen/Core>
#include <iostream>

using namespace Eigen;
using namespace std;

int main() {
    NeuralNetwork nn;
    WorkerOutput output = nn.evaluate(WorkerInput());
    return 0;
}