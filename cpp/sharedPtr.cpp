// =================================================================================================
// C++ experiments with std::shared_ptr, std::weak_ptr
// =================================================================================================

#include <iostream>
#include <memory>

using namespace std;

struct Data {
    int   n;
    bool  b;
    float f;

    Data (int _n, bool _b, float _f) : n(_n), b(_b), f(_f) {
        cout << "Data constructor called.\n";
    };

    ~Data() {
        cout << "! Data destructor called.\n";
    }
};

void printWeakStatus (std::weak_ptr<Data> wp)
{
    cout << "weakPtr: "
         << "use_count " << wp.use_count() << ", "
         << "expired: " << (wp.expired()?"true":"false") << "\n";
}

void main() {
    cout << "\nPlaying with std::shared_ptr, std::weak_ptr.\n";

    weak_ptr<Data> weakPtr;
    printWeakStatus(weakPtr);

    cout << "\n>>>> Entering scope 1.\n";
    {
        printWeakStatus(weakPtr);

        shared_ptr<Data> sharedPtr = make_shared<Data>(13, true, 1.37f);

        cout << "sharedPtr = [" << sharedPtr << "] <"
            << sharedPtr->n << ", "
            << sharedPtr->b << ", "
            << sharedPtr->f << ">\n";

        cout << "weakPtr <- sharedPtr\n";
        weakPtr = sharedPtr;
        printWeakStatus(weakPtr);

        cout << "    >>>> Entering scope 2.\n";
        {
            cout << "    sharedPtr2 <- sharedPtr\n";
            shared_ptr<Data> sharedPtr2 = sharedPtr;
            cout << "    ";
            printWeakStatus(weakPtr);
            cout << "    <<<< Leaving scope 2.\n";
        }
        cout << "Out of scope 2.\n";
        printWeakStatus(weakPtr);

        cout << "<<<< Leaving scope.\n";
    }

    cout << "\nOut of scope 1.\n";
    printWeakStatus(weakPtr);
}
