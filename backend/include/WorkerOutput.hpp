#pragma once

#include <Eigen/Core>

constexpr int OUTPUT_SIZE = 4;

namespace WorkerGrabAction {
    constexpr int GRAB_ACTION = 1;
    constexpr int IDLE = 0;
    constexpr int DROP_ACTION = -1;
}

class WorkerOutput {
public:
    double xVel;
    double yVel;
    int grabAction; // -TRESHOLD = drop, +TRESHOLD = grab
    double smell;
private:
    static int determineGrabAction(double);
public:
    WorkerOutput(double=.0, double=.0, int=0, double=.0);

    /**
     * @brief Returns the number of output params.
     * 
     * @return constexpr int - number of output params
     */
    static const int outputCount() { return OUTPUT_SIZE; };

    /**
     * @brief Converts vector of doubles into WorkerOutput instance.
     * 
     * @param outputVec vector produced by NN evaluation
     * @return WorkerOutput - named actions of the warehouse worker
     */
    static WorkerOutput fromVector(const Eigen::VectorXd&);
};