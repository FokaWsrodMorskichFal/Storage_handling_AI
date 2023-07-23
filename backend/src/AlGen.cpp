#include "AlGen.hpp"
#include "Simulator.hpp"

#include <algorithm>

AlGen::AlGen(std::shared_ptr<CrossSelector> crossSelector, std::shared_ptr<Crosser> crosser, std::shared_ptr<Mutator> mutator)
: crossSelector(crossSelector), crosser(crosser), mutator(mutator), population(Parameters::POPULATION_SIZE) {}

void AlGen::nextEpoch() {
    // Evaluation
    for (Specimen& specimen : population) {
        Warehouse warehouse;
        Simulator simulator(warehouse, specimen);
        double fitness = simulator.simulate();
        specimen.setFitness(fitness);
    }
    sort(population.begin(), population.end());
    // Selection
    Population chosenForCrossing = crossSelector->chooseForCrossing(population);
    // Crossing
    Population children = crosser->cross(chosenForCrossing);
    // Mutation
    Population mutatedChildren = mutator->mutate(children);
    // Replace old population
    population = chosenForCrossing;
    chosenForCrossing.insert(chosenForCrossing.end(), mutatedChildren.begin(), mutatedChildren.end());
}