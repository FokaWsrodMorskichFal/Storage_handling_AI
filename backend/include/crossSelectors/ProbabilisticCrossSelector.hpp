#pragma once

#include "CrossSelector.hpp"

class ProbabilisticCrossSelector : public CrossSelector {
public:
    Population chooseForCrossing(const Population&) const override;
};