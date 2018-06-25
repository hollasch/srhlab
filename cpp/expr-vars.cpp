// =================================================================================================
// Comma-operator Variable Declarations
//
// Bottom-line:
//     The for-loop is unique in that the first expression allows for a comma-separated list of
//     variable declarations. Like so many other things in C++, this only *looks* like another
//     common construct: the comma-operator. The comma operator evaluates sub-expressions from
//     left-to-right, and its result is the value of the last sub-expression. For example, the
//     expression "c=10, c+=5, c==15" yields true.
//
//     I wondered if variable declaration was a part of comma expressions, and perhaps could be used
//     in while-loops or even if-tests. Alas, no -- only for-loops allow for variable definitions.
// =================================================================================================

#include <iostream>

using namespace std;

void main() {
    cout << "\nTesting variable declarations in expressions.\n";

    // For-loop; pretty standard usage.

    cout << "\nfor-loop ----------------------\n";

    for (int v_for=0;  v_for < 10;  ++v_for)
        cout << "Inside: v_for = " << v_for << "\n";


    // While-loop

    cout << "\nwhile-loop --------------------\n";

    int safety = 5;
    while (int v_while=10) {
        // NOTE: The value of v_while is reset to 10 for every iteration.
        cout << "Inside: v_while = " << v_while << "\n";
        --v_while;
        cout << "Inside: v_while = " << v_while << "\n";

        if (--safety <= 0) break;
    }

    // NOTE: Can't declare a variable in a standard comma-expression.
    //
    //     while (int v_while=10, v_while < 20) v_while += 5;   // ERROR: missing ')' before ','

    cout << "\nif-test -----------------------\n";

    if (int v_if = 10) {
        cout << "Inside: v_if = " << v_if << "\n";
        --v_if;
    }

    // NOTE: Can't declare a variable in a standard comma-expression.
    //
    //     if (auto v_if = 10, v_if < 20)      // ERROR: missing ')' before ','
    //         cout << "if-test\n";
}
