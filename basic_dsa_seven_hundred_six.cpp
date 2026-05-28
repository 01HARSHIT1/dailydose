/**
 * Basic DSA - Maximum Difference Between Adjacent Elements in a Circular Array (LeetCode 3423)
 * Compare every adjacent pair, including the wrap-around between last and first.
 */
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int maxAdjacentDistance(const std::vector<int>& nums) {
    int best = std::abs(nums.front() - nums.back());
    for (size_t i = 1; i < nums.size(); ++i)
        best = std::max(best, std::abs(nums[i] - nums[i - 1]));
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Difference Between Adjacent Elements in a Circular Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxAdjacentDistance({1, 2, 4}) << "\n";
    std::cout << "sample 2 -> " << maxAdjacentDistance({-5, -10, -5}) << "\n";
}
