/**
 * Basic DSA - Sqrt(x) (LeetCode 69)
 * Return integer square root, truncating decimal part.
 */
#include <iostream>

int mySqrt(int x) {
    if (x <= 1) return x;
    long lo = 1, hi = x;
    while (lo < hi) {
        long mid = lo + (hi - lo + 1) / 2;
        if (mid * mid <= (long)x) lo = mid;
        else hi = mid - 1;
    }
    return (int)lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sqrt(x)\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "4 -> " << mySqrt(4) << "\n";
    std::cout << "8 -> " << mySqrt(8) << "\n";
    std::cout << "0 -> " << mySqrt(0) << "\n";
}
