/**
 * Basic DSA - Ugly Number (LeetCode 263)
 * Check if n is positive and has only 2, 3, 5 as prime factors.
 */
#include <iostream>

bool isUgly(int n) {
    if (n <= 0) return false;
    for (int p : {2, 3, 5})
        while (n % p == 0) n /= p;
    return n == 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Ugly Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "6 -> " << (isUgly(6) ? "true" : "false") << "\n";
    std::cout << "1 -> " << (isUgly(1) ? "true" : "false") << "\n";
    std::cout << "14 -> " << (isUgly(14) ? "true" : "false") << "\n";
}
