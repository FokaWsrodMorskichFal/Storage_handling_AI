#include "Population.hpp"
#include "RandMutator.hpp"

#include <Eigen/Core>
#include <iostream>

using namespace Eigen;
using namespace std;



int main() {
    Population pop1(1);
    cout << (((pop1[0].neuralNetworks)[0]).layers)[0] << endl;
    RandMutator randMutator;
    Population pop2 = randMutator.mutate(pop1);
    cout << "######### MUTATION #########" << endl;
    cout << ((pop2[0].neuralNetworks)[0].layers)[0] << endl;
    cout << "######### MUTATION #########" << endl;
    cout << ((pop1[0].neuralNetworks)[0].layers)[0] << endl;
    return 0;
}