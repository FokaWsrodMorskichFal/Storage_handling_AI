#pragma once

#include "Box.hpp"
#include "Parameters.hpp"

#include <vector>

class Shipment {
    std::array<int, Parameters::N_COLORS> shipment;
public:
    std::array<int, Parameters::N_COLORS> getShipment() const { return shipment; };
};