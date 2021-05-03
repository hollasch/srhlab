#pragma warning (disable: 4530)
#include <iostream>

using namespace std;

int main () {
    int i = 37;

    cout << "Before for: i=" << i << endl;

    for (int i=1;  i <= 3;  ++i)
    {
        cout << "    Inside for: i=" << i << endl;
    }

    cout << "After  for: i=" << i << endl;

    return 0;
}
