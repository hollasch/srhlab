#include <math.h>
#include <stdio.h>

#include <iostream>
#include <limits>

using namespace std;
using fLimits = std::numeric_limits<float>;

#pragma warning(disable:4723) // potential divide by 0

int main (int argc, char *argv[])
{
    double zero = 0.;
    double nan = 0. / zero;
    double inf = 1. / zero;

    bool naneq = nan == nan;
    bool infeq = inf == inf;

    cout << '\n';

    cout << "NaN = " << nan << '\n';
    cout << "inf = " << inf << '\n';
    cout << "NaN == NaN => " << (naneq ? "true" : "false") << '\n';
    cout << "inf == inf => " << (infeq ? "true" : "false") << '\n';
    cout << '\n';

    cout << "NaN < 10 = " << (nan < 10 ? "true" : "false") << '\n';
    cout << "NaN == 10 = " << (nan == 10 ? "true" : "false") << '\n';
    cout << "NaN != 10 = " << (nan != 10 ? "true" : "false") << '\n';
    cout << "NaN > 10 = " << (nan > 10 ? "true" : "false") << '\n';
    cout << '\n';

    cout << "0 * infinity = " << 0.0 * inf << '\n';
    cout << '\n';

    cout << "std::numeric_limits<float>::max = " << fLimits::max() << '\n';
    cout << "std::numeric_limits<float>::min = " << fLimits::min() << '\n';
    cout << "std::numeric_limits<float>::lowest = " << fLimits::lowest() << '\n';
    cout << "std::numeric_limits<float>::epsilon = " << fLimits::epsilon() << '\n';
    cout << '\n';

    cout << "pow(10,500) = " << pow(10,500) << '\n';
    cout << '\n';

    double x = 0x1p-1074;
    cout << "smallest double denorm: " << x << '\n';
    cout << "std::numeric_limits<double>::denorm_min(): " << std::numeric_limits<double>::denorm_min() << '\n';

    cout << '\n';
    return 0;
}
