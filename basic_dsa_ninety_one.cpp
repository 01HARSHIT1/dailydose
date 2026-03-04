/**
 * Basic DSA - Defanging an IP Address (LeetCode 1108)
 * Replace every '.' with "[.]".
 */
#include <iostream>
#include <string>

std::string defangIPaddr(std::string address) {
    std::string out;
    for (char c : address) {
        if (c == '.') out += "[.]";
        else out += c;
    }
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Defanging an IP Address\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "1.1.1.1 -> " << defangIPaddr("1.1.1.1") << "\n";
    std::cout << "255.100.50.0 -> " << defangIPaddr("255.100.50.0") << "\n";
}
