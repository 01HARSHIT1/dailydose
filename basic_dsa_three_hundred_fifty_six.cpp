/**
 * Basic DSA - Partition Equal Subset Sum (LeetCode 416)
 * Return true if nums can split into two subsets with equal sum.
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

bool canPartition(std::vector<int>& nums) {
    int s = std::accumulate(nums.begin(), nums.end(), 0);
    if (s % 2) return false;
    int t = s / 2;
    std::vector<bool> dp(t + 1);
    dp[0] = true;
    for (int x : nums)
        for (int j = t; j >= x; j--)
            dp[j] = dp[j] || dp[j - x];
    return dp[t];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Partition Equal Subset Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 5, 11, 5};
    std::cout << "[1,5,11,5] -> " << (canPartition(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {1, 2, 3, 5};
    std::cout << "[1,2,3,5] -> " << (canPartition(v2) ? "true" : "false") << "\n";
}
