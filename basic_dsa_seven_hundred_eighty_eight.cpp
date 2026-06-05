/**
 * Basic DSA - Maximum Product of Two Digits (LeetCode 3536)
 * Track the two largest digits while scanning the decimal representation.
 */

#include <iostream>

int maxProduct(int value) {
    int largestDigit = 0;
    int secondLargestDigit = 0;

    for (int remaining = value; remaining > 0; remaining /= 10) {
        const int digit = remaining % 10;
        if (largestDigit < digit) {
            secondLargestDigit = largestDigit;
            largestDigit = digit;
        } else if (secondLargestDigit < digit) {
            secondLargestDigit = digit;
        }
    }

    return largestDigit * secondLargestDigit;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Product of Two Digits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxProduct(31) << "\n";
    std::cout << "sample 2 -> " << maxProduct(22) << "\n";
    std::cout << "sample 3 -> " << maxProduct(124) << "\n";
}
