// This class uses rvalue references (X&&) to define the two move constructors.

class MyClass {
    int* buffer = nullptr;
    string someText;

  private:

    // Disable copying for this example. To implement it properly, you'd have to
    // create a copy of the internal buffer.
    MyClass (const MyClass&);
    MyClass& operator= (const MyClass&);

  public:

    // Move Constructor
    MyClass (MyClass&& other) {
        buffer = other.buffer;
        other.buffer = nullptr;   // Leave source in "empty" but valid state.
        someText = std::move(other.someText);
    }

    // Move Assignment Operator
    MyClass& MyClass::operator= (MyClass&& other) {
        if (this != &other) {
            if (buffer) delete buffer;
            buffer = other.buffer;

            other.buffer = nullptr;   // Leave source in "empty" but valid state.
            someText = std::move(other.someText);
        }
    }

    ~MyClass {
        if (buffer) delete buffer;
    }
};


// Note that this class has the exact same behavior as the class above: moving
// will be enabled and work correctly,and copying will be disabled.

class MyClassB {
    unique_ptr<int> buffer;
    string someText;
}
