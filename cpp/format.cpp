#include <iostream>
#include <format>
#include <string>


int main() {

    std::cout <<"\nExamples of std::format()\n\n";

    std::cout << std::format("Hello {}!\n", "world");
    std::cout << std::format("{2}, {1}, {0}\n", "three", "two", "one");
    std::cout << std::format("True is {}, false is {}.\n", true, false);
    std::cout << std::format("Pi is {}.\n", 3.14159265359);
    std::cout << std::format("Pi is {:.4f}.\n", 3.14159265359);
    std::cout << std::format("Hamburger is {:#x}.\n", 3735928559);
}
