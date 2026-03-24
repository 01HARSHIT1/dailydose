/**
 * Basic DSA - Longest Continuous Increasing Subsequence (LeetCode 674)
 * Max length of a strictly increasing contiguous subarray.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int findLengthOfLCIS(std::vector<int>& nums) {
    if (nums.empty())
        return 0;
    int best = 1;
    int cur = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1]) {
            ++cur;
            best = std::max(best, cur);
        } else {
            cur = 1;
        }
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Continuous Increasing Subsequence\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 3, 5, 4, 7};
    std::cout << "[1,3,5,4,7] -> " << findLengthOfLCIS(v1) << "\n";

    std::vector<int> v2 = {2, 2, 2, 2, 2};
    std::cout << "[2,2,2,2,2] -> " << findLengthOfLCIS(v2) << "\n";
}
