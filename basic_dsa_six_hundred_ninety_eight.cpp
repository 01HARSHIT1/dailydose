/**
 * Basic DSA - Maximum Number of Distinct Elements After Operations (LeetCode 3397)
 * Sort and greedily assign the smallest unused value within each element's [-k, k] range.
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int maxDistinctElements(std::vector<int> nums, int k) {
    int count = 0;
    int occupied = INT_MIN;
    std::sort(nums.begin(), nums.end());

    for (int num : nums) {
        if (occupied < num + k) {
            occupied = std::max(occupied + 1, num - k);
            ++count;
        }
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Number of Distinct Elements After Operations\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxDistinctElements({1, 2, 2, 3, 3, 4}, 2) << "\n";
    std::cout << "sample 2 -> " << maxDistinctElements({4, 4, 4, 4}, 1) << "\n";
}
