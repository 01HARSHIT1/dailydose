/**
 * Basic DSA - Ugly Number II (LeetCode 264)
 * Return the nth ugly number (positive integers whose only prime factors are 2, 3, 5).
 * Three pointers merge multiples like merge-k-sorted lists; O(n) time, O(n) space.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int nthUglyNumber(int n) {
    std::vector<int> ugly(static_cast<size_t>(n));
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; ++i) {
        int next2 = ugly[static_cast<size_t>(i2)] * 2;
        int next3 = ugly[static_cast<size_t>(i3)] * 3;
        int next5 = ugly[static_cast<size_t>(i5)] * 5;
        int next = std::min({next2, next3, next5});
        ugly[static_cast<size_t>(i)] = next;
        if (next == next2) ++i2;
        if (next == next3) ++i3;
        if (next == next5) ++i5;
    }
    return ugly[static_cast<size_t>(n - 1)];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Ugly Number II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=10 -> " << nthUglyNumber(10) << "\n";
    std::cout << "n=1  -> " << nthUglyNumber(1) << "\n";
    std::cout << "n=15 -> " << nthUglyNumber(15) << "\n";
}
