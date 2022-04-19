// =================================================================================================
// C++ experiments with std::array
// =================================================================================================

#include <iostream>
#include <array>

using namespace std;

int main () {
    array a {1, 2, 3, 4, 5};

    cout << "a (by range): ";
    for (auto x : a) {
        cout << x << ' ';
    }
    cout << '\n';

    cout << "a (by index): ";
    for (auto i=0; i < a.size(); ++i) {
        cout << a.at(i) << ' ';
    }
    cout << '\n';

    cout << "a (by iterator): ";
    for (auto it=cbegin(a); it != cend(a); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';

    cout << "a (by operator[]): ";
    for (auto i=0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    cout << "a.front(): " << a.front() << '\n';
    cout << "a.back(): " << a.back() << '\n';

    cout << "a (after fill(9)): ";
    a.fill(9);
    for (auto x : a) {
        cout << x << ' ';
    }
    cout << '\n';

}
