#pragma once

#include "Box.hpp"
#include "Parameters.hpp"

#include <array>

class Shipment {
    std::array<int, Parameters::N_COLORS> order;
public:
    Shipment();
    std::array<int, Parameters::N_COLORS> getOrder() const { return order; };
};