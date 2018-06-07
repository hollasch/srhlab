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
        cout << "! Data constructor called.\n";
    };

    ~Data() {
        cout << "! Data destructor called.\n";
    }
};

void printWeakStatus (std::weak_ptr<Data> wp, const char* indent)
{
    cout << indent
         << "weakPtr: "
         << "use_count " << wp.use_count() << ", "
         << "expired: " << (wp.expired()?"true":"false") << "\n";
}

void main() {
    cout << "\nPlaying with std::shared_ptr, std::weak_ptr.\n";

    weak_ptr<Data> weakPtr;
    printWeakStatus(weakPtr, "");

    cout << "\n>>>> Entering scope 1.\n";
    {
        auto indent = "    ";

        cout << indent << "Creating new Data object.\n";
        shared_ptr<Data> sharedPtr = make_shared<Data>(13, true, 1.37f);

        cout << indent << "sharedPtr = [" << sharedPtr << "] <"
            << sharedPtr->n << ", "
            << sharedPtr->b << ", "
            << sharedPtr->f << ">\n";

        cout << indent << "weakPtr <- sharedPtr\n";
        weakPtr = sharedPtr;

        printWeakStatus(weakPtr, "    ");

        cout << indent << ">>>> Entering scope 2.\n";
        {
            auto indent = "        ";

            cout << indent << "sharedPtr2 <- sharedPtr\n";
            shared_ptr<Data> sharedPtr2 = sharedPtr;

            printWeakStatus(weakPtr, indent);

            cout << indent << "<<<< Leaving scope 2.\n";
        }
        printWeakStatus(weakPtr, indent);

        cout << indent << ">>>> Entering scope 3.\n";
        {
            auto indent = "        ";

            cout << indent << "sharedPtr3 <- weakPtr.lock()\n";
            shared_ptr<Data> sharedPtr3 = weakPtr.lock();

            printWeakStatus(weakPtr, indent);

            cout << indent << "<<<< Leaving scope 3.\n";
        }
        printWeakStatus(weakPtr, indent);

        cout << indent << "<<<< Leaving scope 1.\n";
    }

    printWeakStatus(weakPtr, "");
}
