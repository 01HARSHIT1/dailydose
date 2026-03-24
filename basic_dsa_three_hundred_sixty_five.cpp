/**
 * Basic DSA - Target Sum (LeetCode 494)
 * Ways to assign +/- to nums so sum equals target.
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int findTargetSumWays(std::vector<int>& nums, int target) {
    int s = std::accumulate(nums.begin(), nums.end(), 0);
    if ((s + target) % 2 || target > s || target < -s) return 0;
    int t = (s + target) / 2;
    std::vector<int> dp(t + 1);
    dp[0] = 1;
    for (int x : nums)
        for (int j = t; j >= x; j--)
            dp[j] += dp[j - x];
    return dp[t];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Target Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 1, 1, 1, 1};
    std::cout << "[1,1,1,1,1], 3 -> " << findTargetSumWays(v1, 3) << "\n";

    std::vector<int> v2 = {1};
    std::cout << "[1], 1 -> " << findTargetSumWays(v2, 1) << "\n";
}
