/**
 * Basic DSA - Maximum Subarray (LeetCode 53)
 * Kadane: max sum of a contiguous subarray (non-empty).
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maxSubArray(const std::vector<int>& nums) {
    int best = nums[0];
    int cur = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        cur = std::max(nums[i], cur + nums[i]);
        best = std::max(best, cur);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Subarray\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[-2,1,-3,4,-1,2,1,-5,4] -> "
              << maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << "\n";
    std::cout << "[1] -> " << maxSubArray({1}) << "\n";
    std::cout << "[5,4,-1,7,8] -> " << maxSubArray({5, 4, -1, 7, 8}) << "\n";
}
