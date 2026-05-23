/**
 * Basic DSA - Minimize the Maximum Difference of Pairs (LeetCode 2616)
 * Sort, then binary search the max allowed difference; greedily pair adjacent elements within that threshold.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int minimizeMax(std::vector<int> nums, int p) {
    std::sort(nums.begin(), nums.end());
    int n = static_cast<int>(nums.size());

    auto canForm = [&](int limit) {
        int pairs = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[static_cast<size_t>(i)] - nums[static_cast<size_t>(i - 1)] <= limit) {
                ++pairs;
                ++i; // consume both elements of this pair
            }
        }
        return pairs >= p;
    };

    int lo = 0;
    int hi = n > 0 ? nums[static_cast<size_t>(n - 1)] - nums[0] : 0;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canForm(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimize the Maximum Difference of Pairs\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimizeMax({10, 1, 2, 7, 1, 3}, 2) << "\n";
    std::cout << "sample 2 -> " << minimizeMax({4, 2, 1, 2}, 1) << "\n";
}
