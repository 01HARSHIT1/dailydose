/**
 * Basic DSA - Sum of Square Numbers (LeetCode 633)
 * Return true if c == a^2 + b^2 for integers a, b >= 0.
 */
#include <cmath>
#include <iostream>
#include <string>

bool judgeSquareSum(int c) {
    long long lo = 0;
    long long hi = static_cast<long long>(std::sqrt(c));
    while (lo <= hi) {
        long long s = lo * lo + hi * hi;
        if (s == c)
            return true;
        if (s < c)
            ++lo;
        else
            --hi;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Square Numbers\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "c=5 -> " << (judgeSquareSum(5) ? "true" : "false") << "\n";
    std::cout << "c=3 -> " << (judgeSquareSum(3) ? "true" : "false") << "\n";
    std::cout << "c=0 -> " << (judgeSquareSum(0) ? "true" : "false") << "\n";
}
