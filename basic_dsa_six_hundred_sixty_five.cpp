/**
 * Basic DSA - Minimum Sum of Mountain Triplets I (LeetCode 2908)
 * For each middle j, combine the smallest element to its left and to its right (both < nums[j]).
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int minimumSum(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> prefixMin(static_cast<size_t>(n));
    std::vector<int> suffixMin(static_cast<size_t>(n));

    prefixMin[0] = nums[0];
    for (int i = 1; i < n; ++i)
        prefixMin[static_cast<size_t>(i)] = std::min(prefixMin[static_cast<size_t>(i - 1)], nums[static_cast<size_t>(i)]);

    suffixMin[static_cast<size_t>(n - 1)] = nums[static_cast<size_t>(n - 1)];
    for (int i = n - 2; i >= 0; --i)
        suffixMin[static_cast<size_t>(i)] = std::min(suffixMin[static_cast<size_t>(i + 1)], nums[static_cast<size_t>(i)]);

    int best = INT_MAX;
    for (int j = 1; j < n - 1; ++j) {
        if (prefixMin[static_cast<size_t>(j - 1)] < nums[static_cast<size_t>(j)] &&
            suffixMin[static_cast<size_t>(j + 1)] < nums[static_cast<size_t>(j)]) {
            best = std::min(best, prefixMin[static_cast<size_t>(j - 1)] + nums[static_cast<size_t>(j)] +
                                      suffixMin[static_cast<size_t>(j + 1)]);
        }
    }
    return best == INT_MAX ? -1 : best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Sum of Mountain Triplets I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumSum({8, 6, 1, 5, 3}) << "\n";
    std::cout << "sample 2 -> " << minimumSum({5, 4, 8, 7, 10, 2}) << "\n";
    std::cout << "sample 3 -> " << minimumSum({6, 5, 4, 3, 4, 5}) << "\n";
}
