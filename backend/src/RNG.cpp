#include "RNG.hpp"
#include <random>

using namespace std;

// <a, b)
double RNG::uniformRandom(double lowerbound, double upperbound) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_real_distribution<> urd(lowerbound, upperbound);
    return urd(gen);
}

// <a, b>
int RNG::uniformRandom(int lowerbound, int upperbound) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> uid(lowerbound, upperbound);
    return uid(gen);
}

bool RNG::testEvent(double chance) {
    return (uniformRandom() <= chance);
}