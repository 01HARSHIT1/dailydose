/**
 * Basic DSA - Split With Minimum Sum (LeetCode 2578)
 * Sort digits ascending; distribute them alternately into two numbers to minimize their sum.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int splitNum(int num) {
    std::string digits = std::to_string(num);
    std::sort(digits.begin(), digits.end());

    int a = 0;
    int b = 0;
    for (size_t i = 0; i < digits.size(); ++i) {
        int d = digits[i] - '0';
        if (i % 2 == 0)
            a = a * 10 + d;
        else
            b = b * 10 + d;
    }
    return a + b;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Split With Minimum Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << splitNum(4325) << "\n";
    std::cout << "sample 2 -> " << splitNum(687) << "\n";
}
