/**
 * Basic DSA - Excel Sheet Column Number (LeetCode 171)
 * Convert Excel column title to 1-based column number.
 */
#include <iostream>
#include <string>

int titleToNumber(std::string columnTitle) {
    long long ans = 0;
    for (char c : columnTitle) {
        ans = ans * 26 + (c - 'A' + 1);
    }
    return (int)ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Excel Sheet Column Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "A -> " << titleToNumber("A") << "\n";
    std::cout << "AB -> " << titleToNumber("AB") << "\n";
    std::cout << "ZY -> " << titleToNumber("ZY") << "\n";
}
