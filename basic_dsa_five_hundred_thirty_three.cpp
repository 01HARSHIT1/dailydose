/**
 * Basic DSA - Maximum Product Subarray (LeetCode 152)
 * Contiguous subarray with largest product. Track running max and min (negatives flip signs).
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maxProduct(const std::vector<int>& nums) {
    int best = nums[0];
    int curMax = nums[0];
    int curMin = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        int x = nums[i];
        if (x < 0)
            std::swap(curMax, curMin);
        curMax = std::max(x, curMax * x);
        curMin = std::min(x, curMin * x);
        best = std::max(best, curMax);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Product Subarray\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[2,3,-2,4]        -> " << maxProduct({2, 3, -2, 4}) << "\n";
    std::cout << "[-2,0,-1]         -> " << maxProduct({-2, 0, -1}) << "\n";
    std::cout << "[2,-5,-2,-4,3]    -> " << maxProduct({2, -5, -2, -4, 3}) << "\n";
    std::cout << "[-2,3,-4]         -> " << maxProduct({-2, 3, -4}) << "\n";
}
