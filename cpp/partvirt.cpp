// Illustrates a case where the base class has a non-virtual destructor, but the derived class declares the destructor
// as virtual. S

#include <iostream>
using namespace std;

class A {
  public:
    A() { cout << "Ctor A\n"; }
    ~A() { cout << "Dtor A\n"; }
};

class B : public A {
  public:
    B() { cout << "Ctor B\n"; }
    virtual ~B() { cout << "Dtor B\n"; }
};

int main () {
    {
        cout << "Heap allocation & destruction:\n";
        B thing;
    }

    cout << "\nDynamic allocation and destruction via base class pointer:\n";
    A* thing = new B();
    delete thing; // Crashes

    cout << "\nDone.\n";
    return 0;
}
