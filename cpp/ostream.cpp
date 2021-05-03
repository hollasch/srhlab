#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Color {
  public:
    Color(double red, double green, double blue) : r(red), g(green), b(blue) {}

    ostream& print(ostream& out) const {

        auto priorPrecision = out.precision();

        out << fixed << setprecision(3)
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

    auto c = Color(0.125, 0.250, 0.500);

    cout << "color: " << c << "\n";

    return 0;
}
