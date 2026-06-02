/**
 * Basic DSA - Maximum Unique Subarray Sum After Deletion (LeetCode 3487)
 * Sum distinct positive values, or return the maximum if all are non-positive.
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int maxSum(const std::vector<int>& nums) {
    const int maximum = *std::max_element(nums.begin(), nums.end());
    if (maximum <= 0)
        return maximum;

    std::unordered_set<int> seen;
    int sum = 0;

    for (int value : nums) {
        if (value > 0 && seen.insert(value).second)
            sum += value;
    }

    return sum;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Unique Subarray Sum After Deletion\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxSum({1, 2, 3, 4, 5}) << "\n";
    std::cout << "sample 2 -> " << maxSum({1, 1, 0, 1, 1}) << "\n";
    std::cout << "sample 3 -> " << maxSum({1, 2, -1, -2, 1, 0, -1}) << "\n";
}
