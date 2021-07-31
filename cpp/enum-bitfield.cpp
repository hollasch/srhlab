#include <iostream>
#include <string>

using namespace std;

enum Foo : uint8_t {
    NONE  = 0u,
    RED   = 1u << 0,
    GREEN = 1u << 1,
    BLUE  = 1u << 2,
    ALL   = 0xff,
};

void report(Foo c) {
    if (c & RED)   std::cout << 'R';
    if (c & GREEN) std::cout << 'G';
    if (c & BLUE)  std::cout << 'B';
    std::cout << '\n';
}

int main() {
    auto baz = uint8_t(1) | uint8_t(2);
    cout << "type of Foo:                  " << typeid(Foo).name()                  << '\n';
    cout << "type of uint8_t:              " << typeid(uint8_t).name()              << '\n';
    cout << "type of Foo::RED:             " << typeid(Foo::RED).name()             << '\n';
    cout << "type of Foo::RED | Foo::Blue: " << typeid(Foo::RED | Foo::BLUE).name() << '\n';
    cout << "type of uint8_t | uint8_t:    " << typeid(baz).name()                  << '\n';

    report(GREEN);
    // report(0);           // ERROR: Cannot convert argument 1 from 'int' to 'Component'
    // report(RED | BLUE);  // ERROR: Cannot convert argument 1 from 'int' to 'Component'

    return 0;
}
