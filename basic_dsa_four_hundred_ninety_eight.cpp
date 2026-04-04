/**
 * Basic DSA - Power of Two (LeetCode 231)
 * True iff n equals 2^k for integer k >= 0 (positive n only).
 */
#include <iostream>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Power of Two\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "1 -> " << isPowerOfTwo(1) << "\n";
    std::cout << "16 -> " << isPowerOfTwo(16) << "\n";
    std::cout << "3 -> " << isPowerOfTwo(3) << "\n";
}
