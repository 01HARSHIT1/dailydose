/**
 * Basic DSA - Maximum Product of Three Numbers (LeetCode 628)
 * Return maximum product of three numbers from array.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int maximumProduct(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    return std::max(nums[0] * nums[1] * nums[n - 1],
                    nums[n - 3] * nums[n - 2] * nums[n - 1]);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Product of Three Numbers\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 3};
    std::cout << "[1,2,3] -> " << maximumProduct(v1) << "\n";

    std::vector<int> v2 = {1, 2, 3, 4};
    std::cout << "[1,2,3,4] -> " << maximumProduct(v2) << "\n";

    std::vector<int> v3 = {-1, -2, -3};
    std::cout << "[-1,-2,-3] -> " << maximumProduct(v3) << "\n";
}
