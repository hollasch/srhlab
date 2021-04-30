#pragma warning (disable: 4530)

#include <iostream>
#include <memory>

using namespace std;

class Reporter {
  public:
    Reporter() {
        cout << "Constructing.\n";
    }

    ~Reporter() {
        cout << "Destructing.\n";
    }
};


shared_ptr<Reporter> getReporter() {
    return make_shared<Reporter>();
}


int main () {
    cout << "Before if block.\n";

    if (const auto sharedReporter = getReporter()) {
        cout << "Inside if-block.\n";
    }

    cout << "After if block.\n";

    return 0;
}
