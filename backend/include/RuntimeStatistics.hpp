#pragma once

#include "Parameters.hpp"

#include <array>

class RuntimeStatistics {
    std::array<double, Parameters::N_WORKERS> meanSpeed;
    std::array<int, Parameters::N_WORKERS> differentBoxesTouched; // distinct boxes
    std::array<double, Parameters::N_WORKERS> minDistanceToBox; // for early training
    double neededBoxesYShift; // signed sum of moved boxes from the shipment
    double unneededBoxesShift;
    double timeDeliveryZoneEmpty;
    double shipmentFinishTime;
};