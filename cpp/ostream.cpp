#include <iomanip>
#include <iostream>
#include <string>


class Color {
  public:
    Color(double red, double green, double blue) : r(red), g(green), b(blue) {}

    std::ostream& print(std::ostream& out) const {

        auto priorPrecision = out.precision();

        out << std::fixed << std::setprecision(4)
            << '[' << r << "," << g << "," << b << ']'
            << std::setprecision(priorPrecision) << std::defaultfloat;

        return out;
    }

    double r, g, b;
};


std::ostream& operator<<(std::ostream& out, const Color& color) {
    return color.print(out);
}


int main() {

    std::cout << "\nsetfill and setw only apply to the immediately following non-manipulator output item.\n";
    std::cout << std::setfill('+') << std::setw(20) << 37 << '\n';
    std::cout << 37 << "\n";
    std::cout << std::setfill('+') << std::setw(20) << 37 << 45 << '\n';
    std::cout << '[' << std::setfill('+') << std::setw(20) << 37 << ']'
              << '[' << std::setfill('+') << std::setw(20) << 37 << ']' << '\n';
    std::cout << '[' << std::setfill('+') << std::setw(20) << 37 << ']' << '[' << 37 << ']' << '\n';

    std::cout << "\nHex output with leading zeros.\n";
    std::cout << "Hex 1: " << std::setfill('0') << std::setw(8) << std::hex << 1 << "\n";
    std::cout << "Hex 1 long: " << std::setfill('0') << std::setw(16) << std::hex << 0x123456789aL << "\n";

    std::cout << "\nhex/dec modifiers persist until set to something else.\n";
    std::cout << std::hex << 37 << '\n';   // 25
    std::cout << 37 << '\n';          // 25
    std::cout << std::dec << 37 << '\n';   // 37

    std::cout << "\nExample using 'std::ostream& print()' member function.\n";
    auto c = Color(0.125, 0.25, 0.618033988749895);
    std::cout << "color: " << c << "\n"; // "color: [0.1250, 0.5000, 0.6180]"

    return 0;
}
