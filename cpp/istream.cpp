#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream f("istream-test.txt");

    vector<string> v;

    for (string s; getline(f, s); ) {
        v.push_back(s);
    }

    for (vector<string>::const_reverse_iterator i = v.rbegin(); i != v.rend(); ++i) {
        cout << *i << endl;
    }

    return 0;
}
