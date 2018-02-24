// =================================================================================================
// C++ experiments with std::string.
// =================================================================================================

#include <iostream>
#include <string>
#include <functional>

using namespace std;

void main () {
    cout << "Playing with std::string.\n";

    // Initialization
    cout << "\n-- Initialization\n";
    string str1 {"Initialized string"};
    cout << str1 << "\n";

    // Input
    /*
    cout << "\n-- String I/O\n";

    cout << "Input string: ";
    cin >> str1;
    cout << "You typed: \"" << str1 << '"' << "\n";

    cout << "\nType a line of text.\n";
    getline (cin, str1, '\n');
    cout << "You typed \"" << str1 << "\"\n";
    */

    // Concatenation
    cout << "\n-- Concatenation\n";

    str1 = "This is ";
    string str2 { "a string" };
    string str3 = str1 + str2;

    cout << "Concatenated string: \"" << str3 << "\"\n";

    // Comparison
    cout << "\n-- Comparison" << "\n";

    str3 = "a string";
    cout << "Does \"a string\" == \"a string\"? " << ((str2==str3) ? "Yes!" : "No!?") << "\n";
    cout << "\"A\" > \"B\"? " << ((string("A") > string("B")) ? "Yes" : "No") << "\n";

    // Properties
    cout << "\n-- String Properties\n";

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cout << "Alphabet length = " << alphabet.length() << "\n";
    cout << "Alphabet empty? " << (alphabet.empty() ? "Yes" : "No") << "\n";
    cout << "Alphabet max size: " << alphabet.max_size() << "\n";
    cout << "Alphabet capacity: " << alphabet.capacity() << "\n";

    cout << "Seventh letter = '" << alphabet[6] << "'" << "\n";

    cout << "Alphabet forewards = ";
    for (auto strIterator = alphabet.begin();  strIterator != alphabet.end();  ++strIterator) {
        cout << *strIterator;
    }
    cout << "\n";

    cout << "Alphabet backwards = ";
    for (auto strIterator = alphabet.rbegin();  strIterator != alphabet.rend();  ++strIterator) {
        cout << *strIterator;
    }
    cout << "\n";

    cout << "Alphabet char at position 10: " << alphabet.at(10) << "\n";
    cout << "Alphabet front and back: " << alphabet.front() << ", " << alphabet.back() << "\n";

    // Substrings & substring modification
    cout << "\n-- Substrings & substring modification\n";
    cout << "Five letters starting at g: " << alphabet.substr(6,5) << "\n";
    string alphabet2 { alphabet };
    cout << "Alphabet without the above: " << alphabet2.erase(6,5) << "\n";
    cout << "Now with captital sequence inserted: " << alphabet2.insert(6,"GHIJK") << "\n";
    cout << "Alphabet with replacement: " << alphabet2.replace(6,5,"...") << "\n";
    cout << "Alphabet position of 'nop': " << alphabet.find("nop") << "\n";
    cout << "Alphabet contains 'nop'? " << ((alphabet.find("nop") == string::npos) ? "No" : "Yes") << "\n";
    cout << "Alphabet contains 'pon'? " << ((alphabet.find("pon") == string::npos) ? "No" : "Yes") << "\n";

    string blankTemplate = "1_345_789___3456_890";
    cout << "Index of first '_' in \"" << blankTemplate << "\": " << blankTemplate.find('_') << "\n";
    cout << "Index of last  '_' in \"" << blankTemplate << "\": " << blankTemplate.rfind('_') << "\n";

    // C-Style char buffers. There's no need to free these pointers. If you want to modify this, then you should
    // construct a secondary copy and work with that.
    cout << "\n-- C-style buffers\n";
    const char *strBuffer = alphabet.c_str();
    cout << "Alphabet from C-style buffer: " << strBuffer << "\n";

    // Value Conversion
    cout << "\n-- Numeric conversion\n";
    string numString { "37.1" };
    cout << "\"" << numString << "\" has int value "               << stoi(numString) << "\n";
    cout << "\"" << numString << "\" has long value "              << stol(numString) << "\n";
    cout << "\"" << numString << "\" has longlong value "          << stoll(numString) << "\n";
    cout << "\"" << numString << "\" has unsigned long value "     << stoul(numString) << "\n";
    cout << "\"" << numString << "\" has unsigned longlong value " << stoull(numString) << "\n";
    cout << "\"" << numString << "\" has float value "             << stof(numString) << "\n";
    cout << "\"" << numString << "\" has double value "            << stod(numString) << "\n";
    cout << "\"" << numString << "\" has long double value "       << stold(numString) << "\n";
    cout << "3.14159265354 to string: \"" << to_string(3.14159265354) << "\"\n";

    // Hashes
    cout << "\n-- Hashing\n";
    string hashSource = "Frammin' on the jim-jam, frippin' at the krotz!";
    hash<string> hashFunction;
    size_t hashValue = hashFunction(hashSource);
    cout << "Hash = " << hashValue << "\n";
}
