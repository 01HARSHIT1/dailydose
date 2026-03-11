/**
 * Basic DSA - Reverse Bits (LeetCode 190)
 * Reverse bits of a 32-bit unsigned integer.
 */
#include <iostream>

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++) {
        ans = (ans << 1) | (n & 1);
        n >>= 1;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reverse Bits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "43261596 -> " << reverseBits(43261596) << "\n";
    std::cout << "4294967293 -> " << reverseBits(4294967293u) << "\n";
}
