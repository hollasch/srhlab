#include <math.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    double zero = 0.;
    double nan = 0. / zero;
    double inf = 1. / zero;

    bool naneq = nan == nan;
    bool infeq = inf == inf;

    printf ("nan = %g\n", nan);
    printf ("inf = %g\n", inf);
    printf ("nan == nan => %s\n", naneq ? "true" : "false");
    printf ("inf == inf => %s\n", infeq ? "true" : "false");
}
