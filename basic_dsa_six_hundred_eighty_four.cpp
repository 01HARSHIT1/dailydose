/**
 * Basic DSA - Minimum Element After Replacement With Digit Sum (LeetCode 3300)
 * Replace each value with the sum of its digits, then return the minimum.
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int minElement(const std::vector<int>& nums) {
    int best = INT_MAX;
    for (int v : nums)
        best = std::min(best, digitSum(v));
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Element After Replacement With Digit Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minElement({10, 12, 13, 15}) << "\n";
    std::cout << "sample 2 -> " << minElement({999, 999, 999}) << "\n";
    std::cout << "sample 3 -> " << minElement({1, 2, 3, 4}) << "\n";
}
