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

    cout << "\n# Structured Bindings\n";

    vector<pair<int, string>> pairs {
        { 0, "red" },
        { 1, "green" },
        { 2, "blue" }
    };

    for (auto [key, desc] : pairs) {
        cout << "int(" << key << ") = \"" << desc << "\"\n";
    }

    return 0;
}
