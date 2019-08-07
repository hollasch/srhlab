#include <iostream>

using std::cout;

class TestInit {
  public:
    TestInit() = default;

    uint32_t value() { return m_value; }

  private:
    uint32_t m_value = 123;    // Member constructor initialization at point of declaration.
};


void main (int argc, char *argv[])
{
    TestInit instance;

    cout << "Value is " << instance.value() << "\n";
}
