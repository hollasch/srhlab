#include <iostream>

using namespace std;

pair<bool,double> f()
{
    return { true, 3.7 };
}

void report(bool b, double d) {
    cout << (b ? "true" : "false") << ", " << d << "\n";
}

void main()
{
    // Get pair return from function.
    auto x = f();
    report(x.first, x.second);

    // Function application
    std::apply(report, x);

    // Destructuring
    bool b;
    double d;
    std::tie(b,d) = f();
    report(b,d);
}
