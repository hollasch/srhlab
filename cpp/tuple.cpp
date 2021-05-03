#include <iostream>

using namespace std;

tuple<bool,char,double,int> f()
{
    return { true, 'q', 3.7, 11 };
}

void report(bool b, char c, double d, int i) {
    cout << "b,c,d,i = {"
         << (b ? "true" : "false") << ", "
         << '\'' << c << "', "
         << d << ", "
         << i
         << "}\n";
}

int main() {
    // Create an immediate tuple and access via std::get<#>(var).

    auto x = std::make_tuple (true, 'q', 3.7, 11);

    cout << "x = {"
         << (std::get<0>(x) ? "true" : "false") << ", "
         << '\'' << std::get<1>(x) << "', "
         << std::get<2>(x) << ", "
         << std::get<3>(x)
         << "}\n";

    // Apply a tuple to a function.

    std::apply(report, x);

    // Use std::tie to destructure a tuple into individual variables.

    bool   b;
    char   c = '-';
    double d;
    int    i;

    std::tie(b,std::ignore,d,i) = f();

    cout << "b,c,d,i = {"
         << (b ? "true" : "false") << ", "
         << '\'' << c << "', "
         << d << ", "
         << i
         << "}\n";

    return 0;
}
