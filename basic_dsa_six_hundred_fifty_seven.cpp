/**
 * Basic DSA - Maximum Odd Binary Number (LeetCode 2864)
 * Put all but one '1' at the front for the largest value, keep a single '1' at the end to stay odd.
 */
#include <algorithm>
#include <iostream>
#include <string>

std::string maximumOddBinaryNumber(const std::string& s) {
    int ones = static_cast<int>(std::count(s.begin(), s.end(), '1'));
    int n = static_cast<int>(s.size());
    std::string result(static_cast<size_t>(n), '0');
    for (int i = 0; i < ones - 1; ++i)
        result[static_cast<size_t>(i)] = '1';
    result[static_cast<size_t>(n - 1)] = '1';
    return result;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Odd Binary Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximumOddBinaryNumber("010") << "\n";
    std::cout << "sample 2 -> " << maximumOddBinaryNumber("0101") << "\n";
}
