#pragma once

class RNG {
public:
    static double uniformRandom(double lowerbound = 0.0, double upperbound = 1.0);
    static int uniformRandom(int lowerbound, int upperbound);
    static bool testEvent(double chance);
};