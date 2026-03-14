/**
 * Basic DSA - Valid Perfect Square (LeetCode 367)
 * Check if num is a perfect square without using sqrt.
 */
#include <iostream>

bool isPerfectSquare(int num) {
    if (num <= 1) return true;
    long long lo = 1, hi = num;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sq = mid * mid;
        if (sq == num) return true;
        if (sq < num) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Perfect Square\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "16 -> " << (isPerfectSquare(16) ? "true" : "false") << "\n";
    std::cout << "14 -> " << (isPerfectSquare(14) ? "true" : "false") << "\n";
    std::cout << "1 -> " << (isPerfectSquare(1) ? "true" : "false") << "\n";
}
