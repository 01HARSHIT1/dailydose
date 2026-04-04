/**
 * Basic DSA - Sqrt(x) (LeetCode 69)
 * Integer square root: largest r with r*r <= x.
 */
#include <iostream>

int mySqrt(int x) {
    if (x < 2)
        return x;
    long long lo = 1;
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

    std::cout << "4 -> " << mySqrt(4) << "\n";
    std::cout << "8 -> " << mySqrt(8) << "\n";
    std::cout << "2147395599 -> " << mySqrt(2147395599) << "\n";
}
