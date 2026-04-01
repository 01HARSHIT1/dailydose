/**
 * Basic DSA - Largest Odd Number in String (LeetCode 1903)
 * Largest-valued odd integer that appears as a prefix substring of num (no leading zeros lost).
 */
#include <iostream>
#include <string>

std::string largestOddNumber(const std::string& num) {
    for (int i = static_cast<int>(num.size()) - 1; i >= 0; --i) {
        if ((num[i] - '0') % 2 == 1)
            return num.substr(0, static_cast<size_t>(i) + 1);
    }
    return "";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Largest Odd Number in String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "\"52\" -> \"" << largestOddNumber("52") << "\"\n";
    std::cout << "\"4206\" -> \"" << largestOddNumber("4206") << "\"\n";
    std::cout << "\"35427\" -> \"" << largestOddNumber("35427") << "\"\n";
}
