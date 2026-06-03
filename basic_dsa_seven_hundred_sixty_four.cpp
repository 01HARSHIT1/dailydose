/**
 * Basic DSA - Minimum Cost to Divide Array Into Subarrays (LeetCode 3500)
 * Reverse DP with prefix sums; segment index term folds into cost suffix sum.
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

long long minimumCost(const std::vector<int>& nums, const std::vector<int>& cost, int k) {
    const int size = static_cast<int>(nums.size());
    std::vector<long long> prefixNums(size + 1, 0);
    std::vector<long long> prefixCost(size + 1, 0);
    std::vector<long long> dp(size + 1, LLONG_MAX);

    std::partial_sum(nums.begin(), nums.end(), prefixNums.begin() + 1);
    std::partial_sum(cost.begin(), cost.end(), prefixCost.begin() + 1);
    dp[size] = 0;

    for (int start = size - 1; start >= 0; --start) {
        for (int end = start; end < size; ++end) {
            const long long segmentCost =
                prefixNums[end + 1] * (prefixCost[end + 1] - prefixCost[start]) +
                static_cast<long long>(k) * (prefixCost[size] - prefixCost[start]) +
                dp[end + 1];
            dp[start] = std::min(dp[start], segmentCost);
        }
    }

    return dp[0];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Cost to Divide Array Into Subarrays\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumCost({3, 1, 4}, {4, 6, 6}, 1) << "\n";
    std::cout << "sample 2 -> "
              << minimumCost({4, 8, 5, 1, 14, 2, 2, 12, 1},
                             {7, 2, 8, 4, 2, 2, 1, 1, 2},
                             7)
              << "\n";
}
