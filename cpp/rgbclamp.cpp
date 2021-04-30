#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;


int intensity (double x) {
    return (x <= 0.0) ? 0
         : (x >= 1.0) ? 255
         : std::min(int(256.0 * x), 255);
}

int main () {
    double inputs[] {
        0, 0.001, 0.01, 0.1, 0.5, 0.9, 0.99, 0.999, 1.0, -5, 5,
        -1e37, 1e37, -std::numeric_limits<double>::infinity(), +std::numeric_limits<double>::infinity()
    };

    for (auto input : inputs) {
        cout << setw(8) << input << ": " << intensity(input) << "\n";
    }

    return 0;
}
