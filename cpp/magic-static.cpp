#include <iostream>

using std::cout;

int f() {
    static int x = 0;
    if (!x) {
        cout << "(initializing static value) ";
        x = 100;
    }
    return x;
}

int main (int argc, char *argv[]) {
    cout << "f() returns " << f() << '\n';
    cout << "f() returns " << f() << '\n';
    cout << "f() returns " << f() << '\n';
}
