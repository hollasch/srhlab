#include <iostream>

using namespace std;

pair<double,bool> f()
{
    return { 3.7, true };
}

void main()
{
    auto x = f();
    cout << "x.first = " << x.first << ", x.second = " << (x.second ? "true" : "false") << "\n";

    double a;
    bool b;
    std::tie(a,b) = f();
    cout << "a = " << a << ", b = " << (b ? "true" : "false") << "\n";
}
