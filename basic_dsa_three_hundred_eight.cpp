/**
 * Basic DSA - Number Complement (LeetCode 476)
 * Flip bits of num so all bits in its binary representation are inverted.
 */
#include <iostream>

int findComplement(int num) {
    unsigned mask = ~0u;
    while (mask & num) mask <<= 1;
    return num ^ ~mask;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number Complement\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "5 -> " << findComplement(5) << "\n";
    std::cout << "1 -> " << findComplement(1) << "\n";
}
