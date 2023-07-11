#pragma once

#include <Eigen/Core>

constexpr int OUTPUT_SIZE = 4;

class WorkerOutput {
    double xVel;
    double yVel;
    double grabAction; // -TRESHOLD = drop, +TRESHOLD = grab
    double smell;
public:
    WorkerOutput(double, double, double, double);

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