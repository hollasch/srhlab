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

std::shared_ptr<Data> newData(const char* indent) {
    cout << indent << "Creating and returning shared_ptr of new Data object.\n";
    auto newData = std::make_shared<Data>(13, true, 1.37f);
    return newData;
}

void printWeakStatus (std::weak_ptr<Data> wp, const char* name, const char* indent)
{
    cout << indent
         << name << ": "
         << "use_count " << wp.use_count() << ", "
         << "expired: " << (wp.expired()?"true":"false") << "\n";
}

void main() {
    cout << "\nPlaying with std::shared_ptr, std::weak_ptr.\n";

    weak_ptr<Data> weakPtr;
    printWeakStatus(weakPtr, "weakPtr", "");

    cout << "\n>>>> Entering scope 1.\n";
    {
        auto indent = "    ";

        cout << indent << "Creating new Data object.\n";
        shared_ptr<Data> sharedPtr = newData(indent);

        cout << indent << "sharedPtr = [" << sharedPtr << "] <"
            << sharedPtr->n << ", "
            << sharedPtr->b << ", "
            << sharedPtr->f << ">\n";

        cout << indent << "weakPtr <- sharedPtr\n";
        weakPtr = sharedPtr;

        printWeakStatus(weakPtr, "weakPtr", "    ");

        cout << indent << ">>>> Entering scope 2.\n";
        {
            auto indent = "        ";

            cout << indent << "sharedPtr2 <- sharedPtr\n";
            shared_ptr<Data> sharedPtr2 = sharedPtr;

            printWeakStatus(weakPtr, "weakPtr", indent);

            cout << indent << "weakPtr2 <- sharedPtr2\n";
            weak_ptr<Data> weakPtr2 = sharedPtr2;
            printWeakStatus(weakPtr2, "weakPtr2", indent);

            cout << indent << "<<<< Leaving scope 2.\n";
        }
        printWeakStatus(weakPtr, "weakPtr", indent);

        cout << indent << ">>>> Entering scope 3.\n";
        {
            auto indent = "        ";

            cout << indent << "sharedPtr3 <- weakPtr.lock()\n";
            shared_ptr<Data> sharedPtr3 = weakPtr.lock();

            printWeakStatus(weakPtr, "weakPtr", indent);

            cout << indent << "<<<< Leaving scope 3.\n";
        }
        printWeakStatus(weakPtr, "weakPtr", indent);

        cout << indent << "<<<< Leaving scope 1.\n";
    }

    printWeakStatus(weakPtr, "weakPtr", "");
}
