#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Color {
  public:
    Color(double red, double green, double blue) : r(red), g(green), b(blue) {}

    ostream& print(ostream& out) const {

        auto priorPrecision = out.precision();

        out << fixed << setprecision(4)
            << '[' << r << "," << g << "," << b << ']'
            << setprecision(priorPrecision) << defaultfloat;

        return out;
    }

    double r, g, b;
};


ostream& operator<<(ostream& out, const Color& color) {
    return color.print(out);
}


int main() {

    auto c = Color(0.125, 0.25, 0.618033988749895);

    cout << "color: " << c << "\n"; // "color: [0.1250, 0.5000, 0.6180]"

    return 0;
}
