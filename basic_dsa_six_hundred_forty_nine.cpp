/**
 * Basic DSA - Maximum Sum With Exactly K Elements (LeetCode 2656)
 * Each operation lets us add the current max then increment it; the best k picks form an arithmetic run.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maximizeSum(const std::vector<int>& nums, int k) {
    int maxVal = *std::max_element(nums.begin(), nums.end());
    return k * maxVal + k * (k - 1) / 2;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Sum With Exactly K Elements\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximizeSum({1, 2, 3, 4, 5}, 3) << "\n";
    std::cout << "sample 2 -> " << maximizeSum({5, 5, 5}, 2) << "\n";
}
