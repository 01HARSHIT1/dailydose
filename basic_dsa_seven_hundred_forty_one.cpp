/**
 * Basic DSA - Sum of K Subarrays With Length at Least M (LeetCode 3473)
 * Maximize sum of k non-overlapping subarrays, each with length >= m.
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int maxSum(const std::vector<int>& nums, int k, int m) {
    constexpr int kInf = 20000000;
    const int n = static_cast<int>(nums.size());
    std::vector<int> prefix(n + 1);
    std::partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);

    std::vector<std::vector<std::vector<int>>> dp(
        n + 1, std::vector<std::vector<int>>(2, std::vector<int>(k + 1, -kInf)));

    dp[n][0][0] = 0;
    dp[n][1][0] = 0;

    for (int i = n - 1; i >= 0; --i) {
        for (int remaining = 0; remaining <= k; ++remaining) {
            dp[i][0][remaining] = dp[i + 1][0][remaining];
            if (remaining > 0 && i + m <= n) {
                dp[i][0][remaining] = std::max(
                    dp[i][0][remaining],
                    dp[i + m][1][remaining - 1] + (prefix[i + m] - prefix[i]));
            }
            dp[i][1][remaining] =
                std::max(dp[i][0][remaining], dp[i + 1][1][remaining] + nums[i]);
        }
    }

    return dp[0][0][k];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of K Subarrays With Length at Least M\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxSum({1, 2, -1, 3, 3, 4}, 2, 2) << "\n";
    std::cout << "sample 2 -> " << maxSum({-10, 3, -1, -2}, 4, 1) << "\n";
}
