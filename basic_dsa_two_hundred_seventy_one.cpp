/**
 * Basic DSA - First Bad Version (LeetCode 278)
 * Find first bad version using API isBadVersion(n).
 */
#include <iostream>

bool isBadVersion(int n) {
    return n >= 4;  // mock: first bad is 4
}

int firstBadVersion(int n) {
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (isBadVersion(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: First Bad Version\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=5 -> " << firstBadVersion(5) << "\n";
    std::cout << "n=1 -> " << firstBadVersion(1) << "\n";
}
