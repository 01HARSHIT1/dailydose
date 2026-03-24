/**
 * Basic DSA - Shortest Unsorted Continuous Subarray (LeetCode 581)
 * Length of smallest subarray that must be sorted for the whole array to sort.
 */
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int findUnsortedSubarray(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int end = -1;
    int max_seen = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        max_seen = std::max(max_seen, nums[i]);
        if (nums[i] < max_seen)
            end = i;
    }
    int start = -1;
    int min_seen = std::numeric_limits<int>::max();
    for (int i = n - 1; i >= 0; --i) {
        min_seen = std::min(min_seen, nums[i]);
        if (nums[i] > min_seen)
            start = i;
    }
    return start == -1 ? 0 : end - start + 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Shortest Unsorted Continuous Subarray\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 6, 4, 8, 10, 9, 15};
    std::cout << "[2,6,4,8,10,9,15] -> " << findUnsortedSubarray(v1) << "\n";

    std::vector<int> v2 = {1, 2, 3, 4};
    std::cout << "[1,2,3,4] -> " << findUnsortedSubarray(v2) << "\n";
}
