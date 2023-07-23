#pragma once 

#include "Crosser.hpp"

class ExchangeCrosser : public Crosser {
public:
    Population cross(const Population&) const override;
};