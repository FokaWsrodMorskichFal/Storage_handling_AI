#include "Population.hpp"
#include "Simulator.hpp"
#include "Warehouse.hpp"

#include <Eigen/Core>
#include <iostream>

using namespace Eigen;
using namespace std;

int main() {
    Population pop(1);
    Warehouse warehouse;
    Simulator sim(warehouse, pop[0]);
    sim.simulate();
    return 0;
}