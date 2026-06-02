/**
 * Basic DSA - Maximize Score After Pair Deletions (LeetCode 3496)
 * Maximize removed sum by minimizing what remains at the end.
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

int maxScore(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    const int total = std::accumulate(nums.begin(), nums.end(), 0);

    if (n % 2 == 1)
        return total - *std::min_element(nums.begin(), nums.end());

    int minAdjacentSum = INT_MAX;
    for (int i = 1; i < n; ++i)
        minAdjacentSum = std::min(minAdjacentSum, nums[i - 1] + nums[i]);

    return total - minAdjacentSum;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximize Score After Pair Deletions\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxScore({2, 4, 1}) << "\n";
    std::cout << "sample 2 -> " << maxScore({5, -1, 4, 2}) << "\n";
    std::cout << "sample 3 -> " << maxScore({1, 2, 3, 4}) << "\n";
}
