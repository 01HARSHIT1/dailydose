/**
 * Basic DSA - Factorial Trailing Zeroes (LeetCode 172)
 * Count trailing zeroes in n! (count factors of 5).
 */
#include <iostream>

int trailingZeroes(int n) {
    int count = 0;
    while (n >= 5) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Factorial Trailing Zeroes\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "3 -> " << trailingZeroes(3) << "\n";
    std::cout << "5 -> " << trailingZeroes(5) << "\n";
    std::cout << "0 -> " << trailingZeroes(0) << "\n";
    std::cout << "25 -> " << trailingZeroes(25) << "\n";
}
