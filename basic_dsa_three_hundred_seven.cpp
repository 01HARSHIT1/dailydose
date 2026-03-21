/**
 * Basic DSA - Power of Two (LeetCode 231)
 * Return true if n is a power of two.
 */
#include <iostream>

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Power of Two\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "1 -> " << (isPowerOfTwo(1) ? "true" : "false") << "\n";
    std::cout << "16 -> " << (isPowerOfTwo(16) ? "true" : "false") << "\n";
    std::cout << "3 -> " << (isPowerOfTwo(3) ? "true" : "false") << "\n";
}
