/**
 * Basic DSA - Count Increasing Quadruplets (LeetCode 2552)
 * Count (i,j,k,l) with nums[i] < nums[k] < nums[j] < nums[l]; DP tracks valid triplets for each j.
 */
#include <iostream>
#include <vector>

long long countQuadruplets(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<long long> dp(static_cast<size_t>(n), 0);
    long long answer = 0;

    for (int k = 2; k < n; ++k) {
        long long lessThanK = 0;
        for (int j = 0; j < k; ++j) {
            if (nums[static_cast<size_t>(j)] < nums[static_cast<size_t>(k)]) {
                ++lessThanK;
                answer += dp[static_cast<size_t>(j)];
            } else if (nums[static_cast<size_t>(j)] > nums[static_cast<size_t>(k)]) {
                dp[static_cast<size_t>(j)] += lessThanK;
            }
        }
    }
    return answer;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Increasing Quadruplets\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << countQuadruplets({1, 3, 2, 4, 5}) << "\n";
    std::cout << "sample 2 -> " << countQuadruplets({1, 2, 3, 4}) << "\n";
}
