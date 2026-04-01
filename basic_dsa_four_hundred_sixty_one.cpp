/**
 * Basic DSA - Harshad Number (LeetCode 3099)
 * If x is divisible by the sum of its decimal digits, return that sum; else -1.
 */
#include <iostream>

int sumOfTheDigitsOfHarshadNumber(int x) {
    int sum = 0, t = x;
    while (t > 0) {
        sum += t % 10;
        t /= 10;
    }
    if (sum == 0)
        return -1;
    return (x % sum == 0) ? sum : -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Harshad Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "18 -> " << sumOfTheDigitsOfHarshadNumber(18) << "\n";
    std::cout << "23 -> " << sumOfTheDigitsOfHarshadNumber(23) << "\n";
}
