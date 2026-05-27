/**
 * Basic DSA - Smallest Divisible Digit Product I (LeetCode 3345)
 * Scan upward from n until the product of digits is divisible by t.
 */
#include <iostream>

int smallestNumber(int n, int t) {
    for (int candidate = n;; ++candidate) {
        int product = 1;
        for (int x = candidate; x > 0; x /= 10)
            product *= x % 10;
        if (product % t == 0)
            return candidate;
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Smallest Divisible Digit Product I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << smallestNumber(10, 2) << "\n";
    std::cout << "sample 2 -> " << smallestNumber(15, 3) << "\n";
    std::cout << "sample 3 -> " << smallestNumber(15, 10) << "\n";
}
