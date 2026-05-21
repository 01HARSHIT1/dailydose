/**
 * Basic DSA - Maximum Count of Positive Integer and Negative Integer (LeetCode 2529)
 * Sorted array with negatives at the start; binary search counts negatives before 0 and positives after 0.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maximumCount(const std::vector<int>& nums) {
    int negatives = static_cast<int>(std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin());
    int positives = static_cast<int>(nums.end() - std::upper_bound(nums.begin(), nums.end(), 0));
    return std::max(negatives, positives);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Count of Positive Integer and Negative Integer\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximumCount({-2, -1, -1, 1, 2, 3}) << "\n";
    std::cout << "sample 2 -> " << maximumCount({-3, -2, -1, 0, 0, 1, 2}) << "\n";
    std::cout << "sample 3 -> " << maximumCount({5, 20, 66, 1314}) << "\n";
}
