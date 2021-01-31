#include <iostream>

// Unfortunately, C++ does not have a facility for creating strong typedfs. Either the `typedef` or
// the `using` keywords will create an _alias_ for the specified type. There are hacks to force a
// new type, for example constructing a template class that takes a number as a the second
// parameter, which is unique for each type. Boost also provides a way to create a strong typedef
// using this trick.
//
// For more information, search on {c++ strong typedef}.

using std::cout;

using A = int32_t;
using B = int32_t;

void main() {
    A x = 3;
    B y = 7;

    // This operation will yield no error.
    x = y;

    cout << "Result is " << x << ".\n";
}
