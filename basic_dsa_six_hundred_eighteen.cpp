/**
 * Basic DSA - House Robber IV (LeetCode 2560)
 * Minimize the maximum stolen amount while robbing at least k non-adjacent houses; binary search the capability.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int minCapability(const std::vector<int>& nums, int k) {
    int lo = *std::min_element(nums.begin(), nums.end());
    int hi = *std::max_element(nums.begin(), nums.end());

    auto canRob = [&](int cap) {
        int taken = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] <= cap) {
                ++taken;
                ++i; // skip adjacent house
            }
        }
        return taken >= k;
    };

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canRob(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: House Robber IV\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minCapability({2, 3, 5, 9}, 2) << "\n";
    std::cout << "sample 2 -> " << minCapability({2, 7, 9, 3, 1}, 2) << "\n";
}
