/**
 * Basic DSA - Count the Number of Fair Pairs (LeetCode 2563)
 * Sort, then count pairs with sum in [lower, upper] via (sum <= upper) - (sum < lower) using binary search.
 */
#include <algorithm>
#include <iostream>
#include <vector>

long long countPairsAtMost(const std::vector<int>& nums, long long limit) {
    long long count = 0;
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left < right) {
        if (static_cast<long long>(nums[static_cast<size_t>(left)]) + nums[static_cast<size_t>(right)] <= limit) {
            count += right - left;
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

long long countFairPairs(std::vector<int> nums, int lower, int upper) {
    std::sort(nums.begin(), nums.end());
    return countPairsAtMost(nums, upper) - countPairsAtMost(nums, lower - 1);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count the Number of Fair Pairs\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << countFairPairs({0, 1, 7, 4, 4, 5}, 3, 6) << "\n";
    std::cout << "sample 2 -> " << countFairPairs({1, 7, 9, 2, 5}, 11, 11) << "\n";
}
