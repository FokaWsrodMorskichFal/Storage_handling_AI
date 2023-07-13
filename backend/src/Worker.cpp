#include "Worker.hpp"

#include <cmath>

using namespace std;

Worker::Worker(double x, double y) : x(x), y(y), smell(0), heldBox(nullptr) {}

WorkerOutput Worker::decideAction(const WorkerInput& input) const {
    return neuralNetwork.evaluate(input);
}

void Worker::holdBox(Box& box) {
    box.setHeld();
    heldBox = make_shared<Box>(box);
}

bool Worker::dropBox() {
    if (doesHoldBox()) {
        heldBox->setDropped();
        heldBox = nullptr;
        return true;
    }
    return false;
}

void Worker::reset(double x, double y) {
    this->x = x;
    this->y = y;
    dropBox();
}

double Worker::distance(const Worker& other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}