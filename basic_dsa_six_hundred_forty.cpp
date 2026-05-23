/**
 * Basic DSA - Prime In Diagonal (LeetCode 2614)
 * Check both diagonals of the matrix; return the largest prime found, or 0 if none.
 */
#include <algorithm>
#include <iostream>
#include <vector>

bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0)
            return false;
    }
    return true;
}

int diagonalPrime(const std::vector<std::vector<int>>& nums) {
    int best = 0;
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        int a = nums[static_cast<size_t>(i)][static_cast<size_t>(i)];
        int b = nums[static_cast<size_t>(i)][static_cast<size_t>(n - 1 - i)];
        if (isPrime(a))
            best = std::max(best, a);
        if (isPrime(b))
            best = std::max(best, b);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Prime In Diagonal\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << diagonalPrime({{1, 2, 3}, {5, 6, 7}, {9, 10, 11}}) << "\n";
    std::cout << "sample 2 -> " << diagonalPrime({{1, 2, 3}, {5, 17, 7}, {9, 11, 10}}) << "\n";
}
