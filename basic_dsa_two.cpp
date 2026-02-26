/**
 * Basic DSA - Maximum Subarray (Kadane's Algorithm) (LeetCode 53)
 * Find contiguous subarray with largest sum.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(std::vector<int>& nums) {
    int maxSum = nums[0], cur = 0;
    for (int x : nums) {
        cur = std::max(0, cur) + x;
        maxSum = std::max(maxSum, cur);
    }
    return maxSum;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Subarray (Kadane's Algorithm)\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "[-2,1,-3,4,-1,2,1,-5,4] -> " << maxSubArray(a1) << "\n";

    std::vector<int> a2 = {1};
    std::cout << "[1] -> " << maxSubArray(a2) << "\n";

    std::vector<int> a3 = {5, 4, -1, 7, 8};
    std::cout << "[5,4,-1,7,8] -> " << maxSubArray(a3) << "\n";
}
