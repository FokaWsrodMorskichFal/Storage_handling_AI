#include "Worker.hpp"
#include "SimulatorParameters.hpp"

#include <cmath>
#include <algorithm>

using namespace std;
using namespace Parameters;
using namespace SimulatorParameters;

Worker::Worker() : Worker(NeuralNetwork()) {}

Worker::Worker(NeuralNetwork nn, double x, double y)
: neuralNetwork(nn), x(x), y(y), smell(0), heldBox(nullptr), traveledDistance(0) {}

WorkerOutput Worker::decideAction(WorkerInput& input) const {
    input.xPos = x;
    input.yPos = y;
    array<bool, N_COLORS> heldBoxMask = {false};
    if (doesHoldBox()) {
        heldBoxMask[getHeldBox().getColor()] = true;
    }
    input.heldBox = heldBoxMask;
    return neuralNetwork.evaluate(input);
}

void Worker::holdBox(Box& box) {
    if (box.checkIfHeld()) {
        return;
    }
    box.setHeld();
    heldBox = make_shared<Box>(box);
}

bool Worker::dropBox() {
    if (doesHoldBox()) {
        heldBox->setDropped();
        heldBox->setPos(x, y);
        heldBox = nullptr;
        return true;
    }
    return false;
}

void Worker::moveBy(double dx, double dy) {
    dx = clamp(dx, minX-x, maxX-x);
    dy = clamp(dy, minY-y, maxY-y);
    traveledDistance += sqrt(pow(dx, 2) + pow(dy, 2));
    x += dx;
    y += dy;
}

double Worker::distance(const Worker& other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}