#include "AlGen.hpp"
#include "ExchangeCrosser.hpp"
#include "ProbabilisticCrossSelector.hpp"
#include "RandMutator.hpp"
#include "RNG.hpp"

#include <Eigen/Core>
#include <iostream>
#include <memory>

using namespace Eigen;
using namespace std;

int main() {
    srand(RNG::uniformRandom(0, 213769420));
    shared_ptr<CrossSelector> crossSelector = make_shared<ProbabilisticCrossSelector>(ProbabilisticCrossSelector());
    shared_ptr<Crosser> crosser = make_shared<ExchangeCrosser>(ExchangeCrosser());
    shared_ptr<Mutator> mutator = make_shared<RandMutator>(RandMutator());
    AlGen alGen(crossSelector, crosser, mutator);
    alGen.nextEpoch();
    return 0;
}