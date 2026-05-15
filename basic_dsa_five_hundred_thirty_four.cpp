/**
 * Basic DSA - Combination Sum IV (LeetCode 377)
 * Distinct permutations of nums (reuse allowed) summing to target. Order matters: DP on sum.
 */
#include <iostream>
#include <vector>

int combinationSum4(const std::vector<int>& nums, int target) {
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int s = 1; s <= target; ++s) {
        for (int x : nums) {
            if (s >= x) dp[s] += dp[s - x];
        }
    }
    return dp[target];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Combination Sum IV\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "nums=[1,2,3], target=4  -> " << combinationSum4({1, 2, 3}, 4) << "\n";
    std::cout << "nums=[9], target=3       -> " << combinationSum4({9}, 3) << "\n";
}
