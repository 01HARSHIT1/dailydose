/**
 * Basic DSA - Partition Equal Subset Sum (LeetCode 416)
 * Check if array can be partitioned into two subsets with equal sum.
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <bitset>

bool canPartition(std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    int target = sum / 2;
    std::bitset<10001> dp;
    dp[0] = 1;
    for (int x : nums)
        dp |= dp << x;
    return dp[target];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Partition Equal Subset Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 5, 11, 5};
    std::cout << "[1,5,11,5] -> " << (canPartition(a1) ? "true" : "false") << "\n";

    std::vector<int> a2 = {1, 2, 3, 5};
    std::cout << "[1,2,3,5] -> " << (canPartition(a2) ? "true" : "false") << "\n";

    std::vector<int> a3 = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "[1,2,3,4,5,6,7] -> " << (canPartition(a3) ? "true" : "false") << "\n";
}
