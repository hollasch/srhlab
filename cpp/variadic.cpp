// =================================================================================================
// C++ Variadic Functions
// =================================================================================================

#include <iostream>
#include <cstdarg>

using namespace std;


std::string boolToString(bool b) {
    return b ? "true" : "false";
}


void dumpVarargs (const char *format...) {
    va_list arguments;
    va_start (arguments, format);

    while (*format) {
        switch (*format) {
            case 'd': {
                int n = va_arg(arguments, int);
                cout << n << ' ';
                break;
            }

            case 'c': {
                int n = va_arg(arguments, int);
                cout << static_cast<char>(n) << ' ';
                break;
            }

            case 'f': {
                double d = va_arg(arguments, double);
                cout << d << ' ';
                break;
            }

            case 'b': {
                bool b = va_arg(arguments, bool);
                cout << b << ' ';
                break;
            }
        }
        ++format;
    }

    cout << '\n';
    va_end(arguments);
}


bool IsOneOf (int value, std::initializer_list<int> candidates) {
    // For an arbitrary number of arguments of the same type, use an initializer list.

    for (auto c : candidates)
        if (value == c) return true;

    return false;
}


int main () {
    cout << "Variadic Functions.\n\n";

    dumpVarargs ("bfcdcb", false, 1.37, 'x', 11, 't', true);

    cout << '\n';
    cout << "IsOneOf(7, {0,9,13}) -> " << boolToString(IsOneOf(7, {0,9,13})) << '\n';
    cout << "IsOneOf(7, {0,7,13}) -> " << boolToString(IsOneOf(7, {0,7,13})) << '\n';
    cout << "IsOneOf(7, {0,2,4,6,8,10,12,14,16,18}) -> "
         << boolToString(IsOneOf (7, {0,2,4,6,8,10,12,14,16,18})) << '\n';
    cout << "IsOneOf(7, {}) -> " << boolToString(IsOneOf(7, {})) << '\n';
    cout << "IsOneOf(7, {7}) -> " << boolToString(IsOneOf(7, {7})) << '\n';

    return 0;
}
