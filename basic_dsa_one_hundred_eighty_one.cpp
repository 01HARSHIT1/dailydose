/**
 * Basic DSA - Number of 1 Bits (LeetCode 191)
 * Return number of set bits (Hamming weight) in unsigned integer.
 */
#include <iostream>

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
    std::cout << "4294967293 (binary ...11111101) -> " << hammingWeight(4294967293u) << "\n";
}
