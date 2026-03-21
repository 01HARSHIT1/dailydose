/**
 * Basic DSA - Number of 1 Bits (LeetCode 191)
 * Return Hamming weight of unsigned integer n.
 */
#include <iostream>
#include <cstdint>

int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) {
        n &= n - 1;
        cnt++;
    }
    return cnt;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of 1 Bits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "11 (binary 1011) -> " << hammingWeight(11) << "\n";
    std::cout << "128 -> " << hammingWeight(128) << "\n";
    std::cout << "2147483648 -> " << hammingWeight(2147483648u) << "\n";
}
