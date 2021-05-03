// =================================================================================================
// std::vector growth
// =================================================================================================

#include <iostream>
#include <new>
#include <string>
#include <vector>

using namespace std;

// minimal C++11 allocator with debug output
template <class Tp>
struct NAlloc {
    typedef Tp value_type;
    NAlloc() = default;
    template <class T> NAlloc(const NAlloc<T>&) {}

    Tp* allocate(std::size_t n)
    {
        cout << "> Allocating " << n << " elements\n";
        n *= sizeof(Tp);
        return static_cast<Tp*>(::operator new(n));
    }

    void deallocate(Tp* p, std::size_t n) 
    {
        cout << "> Deallocating " << n << " elements\n";
        ::operator delete(p);
    }
};

template <class T, class U>
bool operator==(const NAlloc<T>&, const NAlloc<U>&) { return true; }
template <class T, class U>
bool operator!=(const NAlloc<T>&, const NAlloc<U>&) { return false; }


void report(std::vector<int, NAlloc<int>>& v) {
    cout << "size " << v.size()
         << ", capacity " << v.capacity()
         << "\n";
}


int main () {
    cout << "std::vector Growth\n";

    cout << "\nInitial definition\n";
    std::vector<int, NAlloc<int>> v;
    report(v);

    cout << "\nSingle push_back\n";
    v.push_back(0);
    report(v);

    cout << "\n10 more pushes\n";
    for (int i=1; i <= 10; ++i)
        v.push_back(i);
    report(v);

    cout << "\n100 more pushes";
    for (int i=100; i < 200; ++i)
        v.push_back(i);
    report(v);

    cout << "\nReserve(1000) + push_back single\n";
    v.reserve(1000);
    report(v);

    cout << "\nReserve(1001) + push_back single\n";
    v.reserve(1001);
    report(v);

    cout << "\nReserve(1002) + push_back single\n";
    v.reserve(1002);
    report(v);

    cout << "\nDone\n";

    return 0;
}
