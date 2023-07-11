#pragma once

#include "Parameters.hpp"

#include <array>
#include <Eigen/Core>

constexpr int INPUT_SIZE = 22;

class WorkerInput {
    double xPos;
    double yPos;
    double xNN;
    double yNN;
    double smellNN;
    int areaLoad; // <-1, 1> 
    std::array<bool, Parameters::N_COLORS> heldBox;
    std::array<bool, Parameters::N_COLORS> colorsNN;
    std::array<bool, Parameters::N_COLORS> neededBox;
    std::array<std::array<double, 2>, Parameters::N_COLORS> boxPositions;
    Eigen::VectorXd boolArrayToVec(std::array<bool, Parameters::N_COLORS>) const;
    Eigen::VectorXd flatten(std::array<std::array<double, 2>, Parameters::N_COLORS>) const;
public:
    /**
     * @brief Construct a new WorkerInput object. Used for DEBUG.
     * 
     * @todo delete when better solution for providing input params is introduced
     */
    WorkerInput();

    /**
     * @brief Returns the number of input params after flattening all arrays + 1 (constant for bias).
     * 
     * @return constexpr int - number of input params
     */
    static constexpr int inputSize() { return INPUT_SIZE; }

    /**
     * @brief Converts the WorkerInput instance into a vector of doubles which can
     * be used as an input for neural network.
     * 
     * @todo this can be probably optimized by creating std:array, loading all the data
     * into it using std::copy and then converting to VectorXd using Euler::Map
     * 
     * @return VectorXd - vector of doubles describing WorkerInput
     */
    Eigen::VectorXd toVector() const;
};