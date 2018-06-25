#include <stdio.h>
#include <limits>

double ItoD (__int64 x) {
    return *(reinterpret_cast<double*>(&x));
}

void test (__int64 ai, __int64 bi) {
    double a = ItoD(ai), b = ItoD(bi);
    bool close = std::fabs(a-b) < std::numeric_limits<double>::epsilon();
    printf ("%.16f and %.16f %s close.\n", a, b, close ? "are " : "are not");
}

int main()
{
    test (0x3fe0000000000000L,
          0x3fe0000000000001L);

    test (0x3ff0000000000000L,
          0x3ff0000000000001L);
}
