/**
 * Basic DSA - Find the Largest Almost Missing Integer (LeetCode 3471)
 * Return largest value appearing in exactly one size-k subarray, else -1.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int largestInteger(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());

    if (k == 1) {
        std::unordered_map<int, int> freq;
        for (int value : nums)
            ++freq[value];

        int ans = -1;
        for (const auto& entry : freq) {
            if (entry.second == 1)
                ans = std::max(ans, entry.first);
        }
        return ans;
    }

    if (k == n)
        return *std::max_element(nums.begin(), nums.end());

    auto isAlmostMissingAt = [&](int index) -> int {
        for (int i = 0; i < n; ++i) {
            if (i != index && nums[i] == nums[index])
                return -1;
        }
        return nums[index];
    };

    return std::max(isAlmostMissingAt(0), isAlmostMissingAt(n - 1));
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Largest Almost Missing Integer\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << largestInteger({3, 9, 2, 1, 7}, 3) << "\n";
    std::cout << "sample 2 -> " << largestInteger({3, 9, 7, 2, 1, 7}, 4) << "\n";
    std::cout << "sample 3 -> " << largestInteger({0, 0}, 1) << "\n";
}
