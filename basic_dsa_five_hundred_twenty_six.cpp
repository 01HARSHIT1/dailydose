/**
 * Basic DSA - Number of 1 Bits (LeetCode 191)
 * Treat n as an unsigned 32-bit value and count how many bits are 1.
 * Clear lowest set bit each step: n &= n - 1. Time: O(number of 1 bits), Space: O(1).
 */
#include <cstdint>
#include <iostream>

int hammingWeight(uint32_t n) {
    int c = 0;
    while (n != 0) {
        n &= n - 1;
        ++c;
    }
    return c;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of 1 Bits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=11 -> " << hammingWeight(11) << "\n";
    std::cout << "n=128 -> " << hammingWeight(128) << "\n";
    std::cout << "n=0 -> " << hammingWeight(0) << "\n";
    std::cout << "n=0xFFFFFFFF -> " << hammingWeight(0xFFFFFFFFu) << "\n";
}
