#pragma once

#include "Crosser.hpp"

/**
 * @brief Chooses pair of agents to cross and performs crossing for them.
 * 
 */
class SimilarCrosser : public Crosser {
public:
    std::vector<Specimen> cross(const std::vector<Specimen>&) const override;
};