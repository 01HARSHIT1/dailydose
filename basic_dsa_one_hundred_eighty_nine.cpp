/**
 * Basic DSA - Add Digits (LeetCode 258)
 * Repeatedly add digits until single digit (digital root).
 */
#include <iostream>

int addDigits(int num) {
    if (num == 0) return 0;
    return 1 + (num - 1) % 9;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Add Digits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "38 -> " << addDigits(38) << "\n";
    std::cout << "0 -> " << addDigits(0) << "\n";
    std::cout << "12345 -> " << addDigits(12345) << "\n";
}
