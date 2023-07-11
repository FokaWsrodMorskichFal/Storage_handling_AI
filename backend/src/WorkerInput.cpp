#include "WorkerInput.hpp"

using namespace std;
using namespace Eigen;
using namespace Parameters;

WorkerInput::WorkerInput() {
    xPos = 1.0;
    yPos = .5;
    xNN = .75;
    yNN = -0.75;
    smellNN = 0.3;
    areaLoad = -1;
    heldBox = {false, false, false};
    colorsNN = {false, false, false};
    neededBox = {false, false, false};
    boxPositions = {{{1., 1.}, {1., 1.}, {1., 1.}}};
}

VectorXd WorkerInput::toVector() const {
    VectorXd doubles(7);
    doubles << 1., xPos, yPos, xNN, yNN, smellNN, static_cast<double>(areaLoad);
    VectorXd heldBoxVec = boolArrayToVec(heldBox);
    VectorXd colorsNNVec = boolArrayToVec(colorsNN);
    VectorXd neededBoxVec = boolArrayToVec(neededBox);
    VectorXd boxPositionsVec = flatten(boxPositions);
    VectorXd ret(inputSize());
    ret << doubles, heldBoxVec, colorsNNVec, neededBoxVec, boxPositionsVec;
    return ret;
}

VectorXd WorkerInput::boolArrayToVec(array<bool, N_COLORS> boolArray) const {
    array<double, N_COLORS> doubleArray;
    transform(boolArray.begin(), boolArray.end(), doubleArray.begin(), [](bool b) { return static_cast<double>(b); });
    return Map<VectorXd>(doubleArray.data(), doubleArray.size());
}

VectorXd WorkerInput::flatten(array<array<double, 2>, N_COLORS> dataArray) const {
    array<double, 2 * N_COLORS> flatArray;
    auto flatIter = flatArray.begin();
    for(const auto& innerArray : dataArray) {
        flatIter = copy(innerArray.begin(), innerArray.end(), flatIter);
    }
    return Map<VectorXd>(flatArray.data(), flatArray.size());
}
