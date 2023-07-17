#pragma once

#include "CrossSelector.hpp"

class ProbabilisticCrossSelector : public CrossSelector {
    std::vector<bool> crossingMask;
public:
    ProbabilisticCrossSelector();
    void generateMask();
    Population chooseForCrossing(const Population&) const override;
};

