#include "WorkerOutput.hpp"
#include "SimulatorParameters.hpp"

using namespace Eigen;
using namespace SimulatorParameters;
using namespace WorkerGrabAction;

WorkerOutput::WorkerOutput(double xVel, double yVel, int grabAction, double smell)
: xVel(xVel), yVel(yVel), grabAction(grabAction), smell(smell) {}

int WorkerOutput::determineGrabAction(double grab) {
    if (grab >= grabTreshold) {
        return GRAB_ACTION;
    } else if (grab <= -grabTreshold) {
        return DROP_ACTION;
    }
    return IDLE;
}

WorkerOutput WorkerOutput::fromVector(const VectorXd& outputVec) {
    return WorkerOutput(outputVec[0] * velocityDump, outputVec[1] * velocityDump, determineGrabAction(outputVec[2]) , outputVec[3]);
}