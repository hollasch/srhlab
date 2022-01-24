#include <iostream>

int func1 (double arg1) {
    // This function silences unused parameter warnings.
    std::ignore = arg1;
    return 37;
}

int sideEffect(int x) {
    std::cout << "sideEffect(" << x << ")\n";
    return 1;
}

int func2 (bool a, int b, double c) {
    // This function produces calls to sideEffect(1), sideEffect(2), and sideEffect(3). So you can
    // use the comma operator, but in either event, each argument is actually evaluated. The same is
    // true with the older style of using `(void)x`.

    std::ignore = a, b, c, 20.0, sideEffect(1);

    std::ignore = a;
    std::ignore = b;
    std::ignore = c;
    std::ignore = 20.0;
    std::ignore = sideEffect(2);
    std::ignore = true && sideEffect(3);
    std::ignore = false && sideEffect(4);

    (void)sideEffect(5);

    return 17;
}

int main () {
    func1(113.12);
    func2(true, 137, 3.14159265359);
    return 0;
}
