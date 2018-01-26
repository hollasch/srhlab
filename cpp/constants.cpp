#include <math.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    // Basic Constants

    double pi      = acos(-1.0);
    double piHalf  = pi/2;
    double piDiv4  = pi/4;
    double twoPi   = 2*pi;
    double deg2rad = pi / 180.0;
    double rad2deg = 180.0 / pi;

    double root2   = sqrt(2.0);
    double root3   = sqrt(3.0);
    double e       = 2.7182818284590451;
    double loge    = log(e);
    double log2    = log(2.0);
    double log10   = log(10.0);

    printf ("\n");
    printf ("pi      = %23.20lf\n", pi);
    printf ("piHalf  = %23.20lf\n", piHalf);
    printf ("piDiv4  = %23.20lf\n", piDiv4);
    printf ("twoPi   = %23.20lf\n", twoPi);
    printf ("deg2rad = %23.20lf\n", deg2rad);
    printf ("rad2deg = %23.20lf\n", rad2deg);
    printf ("root2   = %23.20lf\n", root2);
    printf ("root3   = %23.20lf\n", root3);
    printf ("e       = %23.20lf\n", e);
    printf ("loge    = %23.20lf\n", loge);
    printf ("log2    = %23.20lf\n", log2);
    printf ("log10   = %23.20lf\n", log10);
}
