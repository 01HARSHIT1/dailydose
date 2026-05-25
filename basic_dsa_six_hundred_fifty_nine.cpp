/**
 * Basic DSA - Smallest Number With All Set Bits (LeetCode 3370)
 * Find the smallest 2^k - 1 (all ones) that is >= n.
 */
#include <iostream>

int smallestNumber(int n) {
    int value = 1;
    while (value < n)
        value = value * 2 + 1;
    return value;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Smallest Number With All Set Bits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << smallestNumber(5) << "\n";
    std::cout << "sample 2 -> " << smallestNumber(10) << "\n";
    std::cout << "sample 3 -> " << smallestNumber(3) << "\n";
}
