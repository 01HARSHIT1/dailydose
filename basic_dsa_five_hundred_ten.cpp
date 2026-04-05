/**
 * Basic DSA - Maximum Subarray (Kadane) (LeetCode 53)
 * Find the largest sum of a contiguous subarray. Array is non-empty.
 * Time: O(n), Space: O(1).
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
    std::cout << "Problem: Maximum Subarray (Kadane)\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[-2,1,-3,4,-1,2,1,-5,4] -> " << maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << "\n";
    std::cout << "[1] -> " << maxSubArray({1}) << "\n";
    std::cout << "[5,4,-1,7,8] -> " << maxSubArray({5, 4, -1, 7, 8}) << "\n";
}
