#include <concepts>
#include <iostream>

//======================================================================================================================
// template-values
//
//     An illustration of C++ templates and template specialization to declare templated _types_.
//======================================================================================================================

using namespace std;

// By default, don't "support" a type. "support" is just an arbitrary placeholder here, you can use
// this to model arbitrary properties of your types.

template<typename T> constexpr bool supported = false;

/// We support bools
template<> constexpr bool supported<bool> = true;

/// We support all signed integers. Solved through a concept.
template<std::signed_integral T> constexpr bool supported<T> = true;

string toString(bool value) {
    return value ? "true" : "false";
}

int main() {
    cout << "Support bool: "         << toString(supported<bool>) << '\n';
    cout << "Support int: "          << toString(supported<int>) << '\n';
    cout << "Support unsigned int: " << toString(supported<unsigned int>) << '\n';
    cout << "Support const char*: "  << toString(supported<const char*>) << '\n';

    double d;
    cout << "Support double: " << toString(supported<decltype(d)>) << '\n';


    return 0;
}
