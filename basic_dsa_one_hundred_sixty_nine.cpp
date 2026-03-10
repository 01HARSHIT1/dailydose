/**
 * Basic DSA - First Bad Version (LeetCode 278)
 * Find first bad version using binary search (API: bool isBadVersion(int)).
 */
#include <iostream>

int badFrom = 4;  // simulate: versions 4+ are bad

bool isBadVersion(int n) {
    return n >= badFrom;
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

    badFrom = 4;
    std::cout << "n=5, bad=4 -> " << firstBadVersion(5) << "\n";

    badFrom = 1;
    std::cout << "n=1, bad=1 -> " << firstBadVersion(1) << "\n";

    badFrom = 2;
    std::cout << "n=3, bad=2 -> " << firstBadVersion(3) << "\n";
}
