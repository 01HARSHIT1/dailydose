/**
 * Basic DSA - Power of Two (LeetCode 231)
 * n is a power of two iff n > 0 and n has exactly one set bit: n & (n - 1) clears the
 * lowest set bit, leaving 0 only when there was one bit.
 * Time: O(1), Space: O(1).
 */
#include <iostream>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Power of Two\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=1 -> " << (isPowerOfTwo(1) ? "true" : "false") << "\n";
    std::cout << "n=16 -> " << (isPowerOfTwo(16) ? "true" : "false") << "\n";
    std::cout << "n=3 -> " << (isPowerOfTwo(3) ? "true" : "false") << "\n";
    std::cout << "n=0 -> " << (isPowerOfTwo(0) ? "true" : "false") << "\n";
}
