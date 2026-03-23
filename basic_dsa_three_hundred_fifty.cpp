/**
 * Basic DSA - Maximum Subarray (LeetCode 53)
 * Contiguous subarray with largest sum (Kadane).
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int maxSubArray(std::vector<int>& nums) {
    int best = nums[0], cur = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        cur = std::max(nums[i], cur + nums[i]);
        best = std::max(best, cur);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Subarray\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "example 1 -> " << maxSubArray(v1) << "\n";

    std::vector<int> v2 = {1};
    std::cout << "[1] -> " << maxSubArray(v2) << "\n";
}
