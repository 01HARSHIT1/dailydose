/**
 * Basic DSA - Sqrt(x) (LeetCode 69)
 * Non-negative x: return the integer part of its square root (truncate/floor).
 * Binary search on answer in [0, x]; compare mid*mid with x using 64-bit to avoid overflow.
 * Time: O(log x), Space: O(1).
 */
#include <iostream>

int mySqrt(int x) {
    long long lo = 0;
    long long hi = x;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sq = mid * mid;
        if (sq == x)
            return static_cast<int>(mid);
        if (sq < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return static_cast<int>(hi);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sqrt(x)\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "x=4 -> " << mySqrt(4) << "\n";
    std::cout << "x=8 -> " << mySqrt(8) << "\n";
    std::cout << "x=0 -> " << mySqrt(0) << "\n";
    std::cout << "x=2147395599 -> " << mySqrt(2147395599) << "\n";
}
