#include <stdio.h>
#include <cmath>
#include <cstdint>
#include <limits>

// This program tests whether two double-precision floating-point values compare as different using
// the (fabs(a-b) < epsilon) test. As the values grow, epsilon compares against fewer and fewer
// bits, until no value larger than some max can ever differ from its next larger representation
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

int main() {
    double a = 1;

    for (auto loopCount = 0;  loopCount < 20;  ++loopCount) {
        printf ("different(%23.16f, %23.16f): %s\n", a, nextLarger(a), different(a,nextLarger(a)) ? "true" : "false");
        a *= 2;
    }

    // Shows the difference between 1.0 and epsilon. Epsilon is the smallest number such that 1+e != 1.
    // Here, we subtract and add e/2 to show that 1 + e/2 == 1.

    printf("\n");

    double fmhe = 1.0 - std::numeric_limits<double>::epsilon() / 2.0;
    double fphe = 1.0 + std::numeric_limits<double>::epsilon() / 2.0;
    printf ("1.0 - e/2 (%.23f) == 1.0: %s\n", fmhe, (1.0 == fmhe) ? "true" : "false");
    printf ("1.0 + e/2 (%.23f) == 1.0: %s\n", fphe, (1.0 == fphe) ? "true" : "false");

    return 0;
}
