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

    // setfill and setw only apply to the immediately following non-manipulator output item.
    cout << setfill('+') << setw(20) << 37 << '\n';
    cout << 37 << '\n';
    cout << setfill('+') << setw(20) << 37 << 45 << '\n';
    cout << '[' << setfill('+') << setw(20) << 37 << ']' << '[' << setfill('+') << setw(20) << 37 << ']' << '\n';
    cout << '[' << setfill('+') << setw(20) << 37 << ']' << '[' << 37 << ']' << '\n';

    // hex/dec modifiers persist until set to something else.
    cout << '\n';
    cout << hex << 37 << '\n';   // 25
    cout << 37 << '\n';          // 25
    cout << dec << 37 << '\n';   // 37

    auto c = Color(0.125, 0.25, 0.618033988749895);

    cout << '\n' << "color: " << c << "\n"; // "color: [0.1250, 0.5000, 0.6180]"

    return 0;
}
