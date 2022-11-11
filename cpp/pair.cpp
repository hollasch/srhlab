#include <iostream>
#include <vector>

using namespace std;

pair<bool,double> f() {
    return { true, 3.7 };
}

void report(bool b, double d) {
    cout << (b ? "true" : "false") << ", " << d << "\n";
}

int main() {
    // Get pair return from function.
    cout << "\n# Pair Return Values\n";
    auto x = f();
    report(x.first, x.second);

    // Function application
    cout << "\n# Function Application\n";
    std::apply(report, x);

    // Destructuring
    cout << "\n# Destructuring\n";
    bool b;
    double d;
    std::tie(b,d) = f();
    report(b,d);

    // Structured Binding
    cout << "\n# Structured Binding\n";
    auto [s, t] = f();
    report(s,t);

    return 0;
}
