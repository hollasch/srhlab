#include <iostream>
#include <unordered_set>
#include <string>

void main() {
    std::cout << "\nUnordered Set Example\n";

    // Initialization
    std::unordered_set<std::string> set { "one", "two", "three", "four", "five", "six"};

    std::cout << "----------------------------------------\n";
    for (std::string s : set)
        std::cout << s << "\n";

    // Add item
    set.insert("seven");

    std::cout << "----------------------------------------\n";
    for (std::string s : set)
        std::cout << s << "\n";

    // Remove item
    set.erase("two");
    set.erase("four");
    set.erase("six");

    std::cout << "----------------------------------------\n";
    for (std::string s : set)
        std::cout << s << "\n";

    std::cout << "----------------------------------------\n";
    std::cout << "Contains 'three': " << (set.find("three") != set.cend() ? "true" : "false") << "\n";
    std::cout << "Contains 'green': " << (set.find("green") != set.cend() ? "true" : "false") << "\n";
}
