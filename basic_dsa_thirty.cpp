/**
 * Basic DSA - Number of 1 Bits (LeetCode 191)
 * Count the number of set bits in a 32-bit unsigned integer.
 */
#include <iostream>
#include <cstdint>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of 1 Bits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "11 (binary 1011) -> " << hammingWeight(11) << "\n";
    std::cout << "128 (binary 10000000) -> " << hammingWeight(128) << "\n";
    std::cout << "4294967293 (binary 111...101) -> " << hammingWeight(4294967293) << "\n";
}
