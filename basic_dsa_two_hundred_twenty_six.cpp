/**
 * Basic DSA - Arranging Coins (LeetCode 441)
 * Find max complete rows of staircase (1,2,3,... coins per row).
 */
#include <iostream>

int arrangeCoins(int n) {
    long long lo = 0, hi = n;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        long long need = mid * (mid + 1) / 2;
        if (need <= (long long)n) lo = mid;
        else hi = mid - 1;
    }
    return (int)lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Arranging Coins\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "5 -> " << arrangeCoins(5) << "\n";
    std::cout << "8 -> " << arrangeCoins(8) << "\n";
    std::cout << "1 -> " << arrangeCoins(1) << "\n";
}
