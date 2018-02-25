// =================================================================================================
// C++ Variadic Functions
// =================================================================================================

#include <iostream>
#include <cstdarg>

using namespace std;

void dump (const char *format...)
{
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


void main () {
    cout << "Variadic Functions.\n\n";

    dump ("bfcdcb", false, 1.37, 'x', 11, 't', true);
}
