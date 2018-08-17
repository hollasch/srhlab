#include <stdio.h>
#include <cmath>
#include <cstdint>

// This program tests whether two double-precision floating-point values compare as different using
// the (fabs(a-b) < epsilon) test. As the values grow, epsilon compares against fewer and fewer
// bits, until no value larger than some max can never differ from its next larger representation
// by epsilon or less.

const double epsilon { 1e-15 };

double nextLarger (double x) {
    // Return the next larger representable double value.
    auto i = 1 + *(reinterpret_cast<uint64_t*>(&x));
    return *(reinterpret_cast<double*>(&i));
}

bool different (double a, double b) {
    // Return the result of an epsilon check.
    return std::fabs(a - b) < epsilon;
}

void main() {
    double a = 1;

    for (auto loopCount = 0;  loopCount < 20;  ++loopCount) {
        printf ("different(%23.16f, %23.16f): %s\n", a, nextLarger(a), different(a,nextLarger(a)) ? "true" : "false");
        a *= 2;
    }
}
