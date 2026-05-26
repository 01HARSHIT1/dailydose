/**
 * Basic DSA - Type of Triangle (LeetCode 3024)
 * Validate the triangle inequality, then classify by how many sides are equal.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string triangleType(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    if (nums[0] + nums[1] <= nums[2])
        return "none";
    if (nums[0] == nums[1] && nums[1] == nums[2])
        return "equilateral";
    if (nums[0] == nums[1] || nums[1] == nums[2])
        return "isosceles";
    return "scalene";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Type of Triangle\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << triangleType({3, 3, 3}) << "\n";
    std::cout << "sample 2 -> " << triangleType({3, 4, 5}) << "\n";
    std::cout << "sample 3 -> " << triangleType({1, 1, 3}) << "\n";
}
