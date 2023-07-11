#include "WorkerOutput.hpp"

using namespace Eigen;

WorkerOutput::WorkerOutput(double xVel, double yVel, double grabAction, double smell)
: xVel(xVel), yVel(yVel), grabAction(grabAction), smell(smell) {}

WorkerOutput WorkerOutput::fromVector(const VectorXd& outputVec) {
    return WorkerOutput(outputVec[0], outputVec[1], outputVec[2], outputVec[3]);
}