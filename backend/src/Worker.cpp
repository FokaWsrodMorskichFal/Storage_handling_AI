#include "Worker.hpp"

#include <cmath>

using namespace std;
using namespace Parameters;

Worker::Worker() : Worker(NeuralNetwork()) {}

Worker::Worker(NeuralNetwork nn, double x, double y) : neuralNetwork(nn), x(x), y(y), smell(0), heldBox(nullptr) {}

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
    x += dx;
    y += dy;
}

double Worker::distance(const Worker& other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}